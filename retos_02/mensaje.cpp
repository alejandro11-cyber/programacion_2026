#include "mensaje.h"

Mensaje::Mensaje(const std::string& texto, const std::string& autor) {
    contenido = texto;
    remitente = autor;
    fechaHora = std::time(nullptr); 

