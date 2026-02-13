// celular.cpp
#include "celular.h"
#include <iostream>
#include <iomanip>

Celular::Celular()
    : marca(""), modelo(""), precio(0.0f), costo(0.0f), procesador("") {}

Celular::Celular(const std::string& marca, const std::string& modelo,
                 float precio, float costo, const std::string& procesador)
    : marca(marca), modelo(modelo), precio(0.0f), costo(0.0f), procesador(procesador) {
    if (precio >= 0.0f && costo >= 0.0f) {
        this->precio = precio;
        this->costo = costo;
    } else {
        std::cerr << "Precio y costo deben ser valores positivos\n";
        this->precio = 0.0f;
        this->costo = 0.0f;
    }
}

// Actualizar datos
void Celular::actualizarMarca(const std::string& nuevaMarca) { marca = nuevaMarca; }
void Celular::actualizarModelo(const std::string& nuevoModelo) { modelo = nuevoModelo; }
void Celular::actualizarPrecio(float nuevoPrecio) {
    if (nuevoPrecio >= 0.0f) {
        precio = nuevoPrecio;
    } else {
        std::cerr << "Precio inválido, debe ser positivo\n";
    }
}
void Celular::actualizarCosto(float nuevoCosto) {
    if (nuevoCosto >= 0.0f) {
        costo = nuevoCosto;
    } else {
        std::cerr << "Costo inválido, debe ser positivo\n";
    }
}
void Celular::actualizarProcesador(const std::string& nuevoProcesador) { procesador = nuevoProcesador; }

// Obtener datos
std::string Celular::obtenerMarca() const { return marca; }
std::string Celular::obtenerModelo() const { return modelo; }
float Celular::obtenerPrecio() const { return precio; }
float Celular::obtenerCosto() const { return costo; }
std::string Celular::obtenerProcesador() const { return procesador; }

// Mostrar datos
void Celular::mostrarMarca() const { std::cout << "Marca: " << marca << "\n"; }
void Celular::mostrarModelo() const { std::cout << "Modelo: " << modelo << "\n"; }
void Celular::mostrarPrecio() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Precio: $" << precio << "\n";
    std::cout.unsetf(std::ios_base::floatfield);
}
void Celular::mostrarCosto() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Costo: $" << costo << "\n";
    std::cout.unsetf(std::ios_base::floatfield);
}
void Celular::mostrarProcesador() const { std::cout << "Procesador: " << procesador << "\n"; }

void Celular::mostrarInformacionCompleta() const {
    mostrarMarca();
    mostrarModelo();
    mostrarPrecio();
    mostrarCosto();
    mostrarProcesador();
}

// Otros métodos
float Celular::calcularGanancia() const {
    return precio - costo;
}

void Celular::evaluarRendimiento() const {
    if (procesador.find("Snapdragon") != std::string::npos)
        std::cout << "Rendimiento: Alto\n";
    else if (procesador.find("Mediatek") != std::string::npos)
        std::cout << "Rendimiento: Medio\n";
    else
        std::cout << "Rendimiento: Básico\n";
}