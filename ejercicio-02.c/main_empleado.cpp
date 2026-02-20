#include <iostream>
#include "empleado_tiempo_completo.h"

int main() {
    std::cout << "=== Sistema de Gestion de Empleados ===" << std::endl;
    std::cout << std::endl;

    Empleado emp1("Luis Fernández", "EMP-101", 18000.0);
    std::cout << "Empleado (clase base):" << std::endl;
    emp1.mostrarInformacion();
    std::cout << std::endl;

    EmpleadoTiempoCompleto etc1;
    std::cout << "Empleado tiempo completo (constructor por defecto):" << std::endl;
    etc1.mostrarInformacion();
    std::cout << std::endl;

    EmpleadoTiempoCompleto etc2("María González", "EMP-202", 25000.0, 45, 3500.0);
    std::cout << "Empleado tiempo completo (constructor con parámetros):" << std::endl;
    etc2.mostrarInformacion();
    std::cout << "Salario total: " << etc2.calcularSalarioTotal() << std::endl;
    std::cout << std::endl;

    etc2.actualizarBono(5000.0);
    std::cout << "Después de actualizar bono:" << std::endl;
    etc2.mostrarInformacion();
    std::cout << "Salario total: " << etc2.calcularSalarioTotal() << std::endl;

    return 0;
}