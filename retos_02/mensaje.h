#ifndef MENSAJE_H
#define MENSAJE_H

#include <string>
#include <ctime>

class Mensaje {
public:
    std::string contenido;   
    std::string remitente;   
    std::time_t fechaHora;   

    // Constructor que inicializa contenido y remitente, y asigna la hora actual
    Mensaje(const std::string& texto, const std::string& autor)
        : contenido(texto), remitente(autor), fechaHora(std::time(nullptr)) {}
};

#endif