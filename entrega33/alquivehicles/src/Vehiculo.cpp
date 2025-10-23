#include "Vehiculo.h"
#include <iostream>

Vehiculo::Vehiculo(const std::string& marca, const std::string& modelo, const std::string& placa)
    : marca(marca), modelo(modelo), placa(placa), disponible(true) {}

std::string Vehiculo::getMarca() const { return marca; }
std::string Vehiculo::getModelo() const { return modelo; }
std::string Vehiculo::getPlaca() const { return placa; }
bool Vehiculo::estaDisponible() const { return disponible; }

void Vehiculo::setDisponible(bool disp) { disponible = disp; }

void Vehiculo::mostrarInformacion() const {
    std::cout << "Marca: " << marca 
              << ", Modelo: " << modelo 
              << ", Placa: " << placa 
              << ", Disponible: " << (disponible ? "Sí" : "No")
              << std::endl;
}