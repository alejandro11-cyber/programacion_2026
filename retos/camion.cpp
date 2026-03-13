#include "camion.h"
#include <iostream>

Camion::Camion() : Vehiculo() {
    maximo_de_peso = 0.0;
    capacidad_personas = 0;
}

// Constructor por defecto
Camion::Camion(std::string marca, std::string modelo, int anio, std::string placa,
           float maximo_de_peso, std::string capacidad_personas) 
           : Vehiculo(marca, modelo, anio, placa) {

            this->maximo_de_peso = maximo_de_peso;
    this->capacidad_personas = capacidad_personas;
}

// Métodos para actualizar

   void actualizarMaximoDePeso(float nuevoMaximoDePeso);
    void actualizarCapacidadPersonas(std::string nuevaCapacidadPersonas);

// Método para mostrar información
   void Camion::mostrarInformacion() {
    Vehiculo::mostrarInformacion(); 
    std::cout << "Maximo peso: " << maximo_de_peso << " toneladas" << std::endl;
    std::cout << "Maximo personas: " << capacidad_personas << std::endl;
}

// Getters
float Camion::obtenerMaximoDePeso() {
    return maximo_de_peso;
    

int Camion::obtenerCapacidadPersonas() {
    return std::stoi(capacidad_personas);
}