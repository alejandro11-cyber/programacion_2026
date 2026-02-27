#ifndef camion_H
#define camion_H

#include <string>

class camion : public Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    int anio;
    std::string placa;

public:
    // Constructores
    camion();
    camion(std::string marca, std::string modelo, int anio, std::string placa);

    // Métodos para actualizar
    void actualizarMarca(std::string nuevaMarca);
    void actualizarModelo(std::string nuevoModelo);
    void actualizarAnio(int nuevoAnio);
    void actualizarPlaca(std::string nuevaPlaca);

    // Métodos para mostrar
    void mostrarInformacion();

    // Getters
    std::string obtenerMarca();
    std::string obtenerModelo();
    int obtenerAnio();
    std::string obtenerPlaca();
};

#endif // camion_H