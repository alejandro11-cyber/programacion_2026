#pragma once

#include <string>
#include <chrono>
#include "../third_party/json.hpp"

// Clase que representa un mensaje en la conversación
class Mensaje {
public:
    enum class Rol { Usuario, Sistema, Asistente };

    Mensaje() = default;
    Mensaje(Rol rol, std::string contenido);

    Rol obtenerRol() const;
    const std::string& obtenerContenido() const;
    std::string obtenerTimestampISO() const;

    // Serialización a JSON
    nlohmann::json a_json() const;
    static Mensaje desde_json(const nlohmann::json& j);

private:
    Rol m_rol{Rol::Usuario};
    std::string m_contenido;
    std::chrono::system_clock::time_point m_ts{std::chrono::system_clock::now()};
};