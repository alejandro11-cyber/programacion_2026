#include "Rectangulo.h"
#include <iostream>
using namespace std;

Rectangulo::Rectangulo(string nombre, double base, double altura)
    : Figura(nombre) {
        this->base = base;
        this->altura = altura;
    }

    Rectangulo::~Rectangulo() {
        //no esta vacio
     }

    double Rectangulo::calcularArea() {
        return base * altura;
    }

    double Rectangulo::obtenerBase() {
        return base;
    }

    double Rectangulo::obtenerAltura() {
        return altura;
    }
    void Rectangulo::describir() {
        cout << "Figura: Rectangulo, base: " << base << ", altura: " << altura << endl;
    }
