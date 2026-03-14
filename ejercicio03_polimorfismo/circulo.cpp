#include "circulo.h"
#include <iostream>
using namespace std;

Circulo::Circulo(string nombre, double radio)
    : Figura(nombre){
        this->radio = radio;
}

Circulo::~Circulo() { 
    //no esta vacio
}

double Circulo::calcularArea() {
    return 3.141592 * radio * radio;
}

void Circulo::describir() {
    cout << "Figura: Circulo, radio: " << radio << endl;
}

double Circulo::obtenerRadio() {
    return radio;
}