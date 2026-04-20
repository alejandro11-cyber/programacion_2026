#include "Mensaje.h"
#include <iomanip>
#include <sstream>

using json = nlohmann::json;

Mensaje::Mensaje(Rol rol, std::string contenido)
    : m_rol(rol), m_contenido(std::move(contenido)), m_ts(std::chrono::system_clock::now()) {}

Mensaje::Rol Mensaje::obtenerRol() const { return m_rol; }
const std::string& Mensaje::obtenerContenido() const { return m_contenido; }

std::string Mensaje::obtenerTimestampISO() const {
    auto t = std::chrono::system_clock::to_time_t(m_ts);
    std::tm tm;
#if defined(_WIN32)
    gmtime_s(&tm, &t);
#else
    gmtime_r(&t, &tm);
#endif
    std::ostringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%SZ");
    return ss.str();
}

json Mensaje::a_json() const {
    json j;
    std::string rol_s = (m_rol == Rol::Usuario) ? "usuario" : (m_rol == Rol::Asistente) ? "asistente" : "sistema";
    j["rol"] = rol_s;
    j["contenido"] = m_contenido;
    j["timestamp"] = obtenerTimestampISO();
    return j;
}

Mensaje Mensaje::desde_json(const json& j) {
    std::string rol_s = j.value("rol", "usuario");
    Rol r = (rol_s == "asistente") ? Rol::Asistente : (rol_s == "sistema") ? Rol::Sistema : Rol::Usuario;
    Mensaje m(r, j.value("contenido", ""));
    return m;
}