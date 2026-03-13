#ifndef CAMION_H
#define CAMION_H

#include "vehiculo.h"
#include <string>

class Camion : public Vehiculo {

private:
    float maximo_de_peso;           // máximo de peso que puede cargar
    std::string capacidad_personas; // capacidad de personas del camión

public:
    // Constructores
    Camion();
    Camion(std::string marca, std::string modelo, int anio, std::string placa,
           float maximo_de_peso, std::string capacidad_personas);

    // Métodos para actualizar atributos
    void actualizarMaximoDePeso(float nuevoMaximoDePeso);
    void actualizarCapacidadPersonas(std::string nuevaCapacidadPersonas);

    // Métodos para mostrar información
    void mostrarInformacion();

    // Métodos para obtener atributos
    float obtenerMaximoDePeso();
    std::string obtenerCapacidadPersonas();
};

#endif // CAMION_H