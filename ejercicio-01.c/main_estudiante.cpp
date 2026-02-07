// main.cpp
#include <iostream>
#include "estudiante.h"

int main() {
    std::cout << "=== Sistema de Estudiantes ===\n\n";

    // Estudiante con constructor vacío
    Estudiante estudiante1;
    std::cout << "Estudiante 1 (por defecto):\n";
    estudiante1.mostrarInformacionCompleta();
    std::cout << "\n";

    // Actualizar datos del estudiante1
    estudiante1.actualizarNombre("Thalan Alejandro Mares Vera");
    estudiante1.actualizarCodigo("A25216362");
    estudiante1.actualizarEdad(19);
    estudiante1.actualizarPromedio(8.0f);
    estudiante1.actualizarActivo(true);

    std::cout << "Estudiante 1 actualizado:\n";
    estudiante1.mostrarInformacionCompleta();
    estudiante1.calcularEstadoAcademico();
    std::cout << "\n";

    // Estudiante con datos iniciales
    Estudiante estudiante2("lizando morfines arcila", "A25216372", 18, 7.7f, true);
    std::cout << "Estudiante 2 (con parámetros):\n";
    estudiante2.mostrarInformacionCompleta();
    estudiante2.calcularEstadoAcademico();
    std::cout << "\n";

    // Probar incremento de edad
    std::cout << "Sumando un año al estudiante 2:\n";
    estudiante2.incrementarEdad();
    estudiante2.mostrarEdad();
    std::cout << "\n";

    // Probar validación de promedio
    std::cout << "Intento de promedio inválido:\n";
    estudiante2.actualizarPromedio(15.0f);
    estudiante2.mostrarPromedio();
    std::cout << "\n";

    return 0;
}