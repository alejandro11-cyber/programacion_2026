#ifndef CONVERSACION_H
#define CONVERSACION_H

#include <vector>
#include <string>
#include "mensaje.h"

class Conversacion {
private:
    std::vector<Mensaje> mensajes; 
    std::string titulo;              

public:
   
    explicit Conversacion(const std::string& titulo = "Conversación sin título");

    void agregarMensaje(const Mensaje& msg);

  
    const std::vector<Mensaje>& obtenerMensajes() const;

  
    void guardarEnArchivo(const std::string& ruta) const;


    void setTitulo(const std::string& nuevoTitulo);


    std::string getTitulo() const;
};

#endif
