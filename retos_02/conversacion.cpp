#include "conversacion.h"
#include <fstream>
#include <ctime>

void Conversacion::agregarMensaje(const Mensaje& msg) {
    mensajes.push_back(msg);
}

void Conversacion::guardarEnArchivo(const std::string& ruta) const {
    std::ofstream archivo(ruta, std::ios::app);
    if (!archivo) {
        return; // Si no se pudo abrir, salir
    }

    for (const auto& msg : mensajes) {
        std::string fecha = std::ctime(&msg.FechaHora);
        if (!fecha.empty() && fecha.back() == '\n') {
            fecha.pop_back(); // quitar salto de línea
        }

        archivo << "[" << msg.remitente << "] "
                << fecha << " -> "
                << msg.contenido << '\n';
    }
}
