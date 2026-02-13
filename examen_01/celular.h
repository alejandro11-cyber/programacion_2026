// celular.h
#ifndef CELULAR_H
#define CELULAR_H

#include <string>

class Celular {
private:
    std::string marca;
    std::string modelo;
    float precio;
    float costo;
    std::string procesador;

public:
    // Constructores
    Celular();
    Celular(const std::string& marca, const std::string& modelo,
            float precio, float costo, const std::string& procesador);

    // Cambiar datos
    void actualizarMarca(const std::string& nuevaMarca);
    void actualizarModelo(const std::string& nuevoModelo);
    void actualizarPrecio(float nuevoPrecio);
    void actualizarCosto(float nuevoCosto);
    void actualizarProcesador(const std::string& nuevoProcesador);

    // Consultar datos
    std::string obtenerMarca() const;
    std::string obtenerModelo() const;
    float obtenerPrecio() const;
    float obtenerCosto() const;
    std::string obtenerProcesador() const;

    // Mostrar información
    void mostrarMarca() const;
    void mostrarModelo() const;
    void mostrarPrecio() const;
    void mostrarCosto() const;
    void mostrarProcesador() const;
    void mostrarInformacionCompleta() const;

    // Otros métodos
    float calcularGanancia() const; // precio - costo
    void evaluarRendimiento() const; // según procesador
};

#endif