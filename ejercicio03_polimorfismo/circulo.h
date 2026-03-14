#ifndef CIRCULO_H
#define CIRCULO_H
#include <string>
#include "figura.h"


class Circulo : public Figura {
    private:
    double radio;

    public:
    Circulo(string nombre, double radio);
    virtual ~Circulo();

    virtual double calcularArea() override;
    virtual void describir() override;

    double obtenerRadio();

};

#endif