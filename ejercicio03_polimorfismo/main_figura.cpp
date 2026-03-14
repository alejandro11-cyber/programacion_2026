#include "circulo.h"
#include "rectangulo.h"

int main() {
    std::cout << "=== Programa de Figuras Geometricas (Polimorfismo) ===" << std::endl;
    std::cout << std::endl;

    Figura* f1 = new Circulo("Circulo", 7.5);   // radio cambiado
    Figura* f2 = new Rectangulo("Rectangulo", 3.0, 8.0); // dimensiones cambiadas

    std::cout << "--- Primera Figura (Circulo) ---" << std::endl;
    f1->describir();
    std::cout << "Area calculada: " << f1->calcularArea() << std::endl;
    std::cout << std::endl;

    std::cout << "--- Segunda Figura (Rectangulo) ---" << std::endl;
    f2->describir();
    std::cout << "Area calculada: " << f2->calcularArea() << std::endl;
    std::cout << std::endl;

    std::cout << "--- Iterando sobre todas las figuras ---" << std::endl;
    Figura* figuras[] = { f1, f2 };
    for (int i = 0; i < 2; i++) {
        figuras[i]->describir();
        std::cout << "Area calculada: " << figuras[i]->calcularArea() << std::endl;
    }

    delete f1;
    delete f2;

    return 0;
}