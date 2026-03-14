#include "figura.h"
#include <iostream>

using namespace std;

Figura::Figura(string nombre) {
    this->nombre = nombre;
}

Figura::~Figura(){
    //no esta vacio
}

string Figura::obtenerNombre(){
    return nombre;
}

void Figura::describir(){
    cout << "Es una figura llamda: " << nombre << endl;
}