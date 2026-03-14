#ifndef RECTANGULO_H
#define RECTANGULO_H
#include <string>
#include "figura.h"
using std::string;

class Rectangulo : public Figura {
    private:
        double base;
        double altura;

    public:
        Rectangulo(string nombre, double base, double altura);
        virtual ~Rectangulo();
       virtual double calcularArea() override;
       virtual void describir() override;

        double obtenerBase();
        double obtenerAltura();
};

#endif