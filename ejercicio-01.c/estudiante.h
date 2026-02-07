// estudiante.h
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante {
private:
    std::string nombre;
    std::string codigo;
    int edad;
    float promedio;
    bool activo;

public:
    // Constructores
    Estudiante();
    Estudiante(const std::string& nombre, const std::string& codigo,
               int edad, float promedio, bool activo);

    // Cambiar datos
    void actualizarNombre(const std::string& nuevoNombre);
    void actualizarCodigo(const std::string& nuevoCodigo);
    void actualizarEdad(int nuevaEdad);
    void actualizarPromedio(float nuevoPromedio);
    void actualizarActivo(bool nuevoEstado);

    // Consultar datos
    std::string obtenerNombre() const;
    std::string obtenerCodigo() const;
    int obtenerEdad() const;
    float obtenerPromedio() const;
    bool obtenerActivo() const;

    // Mostrar información
    void mostrarNombre() const;
    void mostrarCodigo() const;
    void mostrarEdad() const;
    void mostrarPromedio() const;
    void mostrarActivo() const;
    void mostrarInformacionCompleta() const;

    // Otros métodos
    void incrementarEdad();
    void calcularEstadoAcademico() const;
};

#endif