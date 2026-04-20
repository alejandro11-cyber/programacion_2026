#include "Conversacion.h"
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <fstream>

using json = nlohmann::json;
namespace fs = std::filesystem;

void Conversacion::agregarMensaje(const Mensaje& m) {
    m_mensajes.push_back(m);
}

const std::vector<Mensaje>& Conversacion::obtenerMensajes() const {
    return m_mensajes;
}

json Conversacion::a_json() const {
    json j;
    j["mensajes"] = json::array();
    for (const auto& m : m_mensajes) j["mensajes"].push_back(m.a_json());
    return j;
}

Conversacion Conversacion::desde_json(const json& j) {
    Conversacion c;
    if (j.contains("mensajes") && j["mensajes"].is_array()) {
        for (const auto& mj : j["mensajes"]) {
            c.agregarMensaje(Mensaje::desde_json(mj));
        }
    }
    return c;
}

std::string Conversacion::guardarEnDisco(const std::string& base_dir) const {
    auto ahora = std::chrono::system_clock::now();
    auto t = std::chrono::system_clock::to_time_t(ahora);
    std::tm tm;
#if defined(_WIN32)
    localtime_s(&tm, &t);
#else
    localtime_r(&t, &tm);
#endif

    std::ostringstream carpeta_ss;
    carpeta_ss << std::put_time(&tm, "%Y-%m-%d") << "/" << std::put_time(&tm, "%H-%M-%S");
    fs::path dir = fs::path(base_dir) / carpeta_ss.str();
    fs::create_directories(dir);

    std::ostringstream archivo_ss;
    archivo_ss << "conversacion_" << std::put_time(&tm, "%Y%m%dT%H%M%S") << ".json";
    fs::path archivo = dir / archivo_ss.str();

    std::ofstream ofs(archivo);
    ofs << a_json().dump(2);
    ofs.close();
    return archivo.string();
}