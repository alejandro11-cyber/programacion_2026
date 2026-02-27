#include "camion.h"
#include <iostream>

// Constructor por defecto
Vehiculo::camion() {
    marca = "";
    modelo = "";
    anio = 0;
    placa = 0;
}

// Constructor con parámetros
Vehiculo::Vehiculo(std::string marca, std::string modelo, int año) {
    this->marca = marca;
    this->modelo = modelo;
    this->año = anio;
    this->placa = 0; 
}

// Métodos para actualizar
void camion::actualizarMarca(std::string nuevaMarca) {
    marca = nuevaMarca;
}

void camion::actualizarModelo(std::string nuevoModelo) {
    modelo = nuevoModelo;
}

void camion::actualizarAño(int nuevoAnio) {
    año = nuevoAnio;
}

void camion::actualizarPlaca(std::string nuevaPlaca) {
    placa = nuevaPlaca;
}


// Método para mostrar
void camion::mostrarInformacion() {
    std::cout << "Marca: " << marca << std::endl;
    std::cout << "Modelo: " << modelo << std::endl;
    std::cout << "Anio: " << año << std::endl;
    std::cout << "Placas: " << placa << std::endl;
}

// Getters
std::string camion::obtenerMarca() {
    return marca;
}

std::string camion::obtenerModelo() {
    return modelo;
}

int camion::obtenerAnio() {
    return año;
}

int camion::obtenerPlaca() {
    return placa;
}