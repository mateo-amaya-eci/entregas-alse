#include "Auto.h"
#include <iostream>

Auto::Auto(const std::string& marca, const std::string& modelo, const std::string& placa,int capacidadPasajeros, int numeroPuertas, const std::string& tipoTransmision)
    : Vehiculo(marca, modelo, placa), capacidadPasajeros(capacidadPasajeros),numeroPuertas(numeroPuertas),tipoTransmision(tipoTransmision) {}

int Auto::getCapacidadPasajeros() const { return capacidadPasajeros; }
int Auto::getNumeroPuertas() const { return numeroPuertas; }
std::string Auto::getTipoTransmision() const { return tipoTransmision; }

void Auto::mostrarInformacion() const {
    std::cout << "🚗 AUTO - Marca: " << marca 
              << ", Modelo: " << modelo 
              << ", Placa: " << placa 
              << "\n    Capacidad: " << capacidadPasajeros << " pasajeros"
              << ", Puertas: " << numeroPuertas
              << ", Transmisión: " << tipoTransmision
              << ", Disponible: " << (estaDisponible() ? "Sí" : "No")
              << std::endl;
}

std::string Auto::getTipo() const {
    return "Auto";
}