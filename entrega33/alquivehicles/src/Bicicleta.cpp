#include "Bicicleta.h"
#include <iostream>

Bicicleta::Bicicleta(const std::string& marca, const std::string& modelo, const std::string& placa,const std::string& tipo, int numeroMarchas, bool tieneSuspension)
    : Vehiculo(marca, modelo, placa),
      tipo(tipo),
      numeroMarchas(numeroMarchas),
      tieneSuspension(tieneSuspension) {}

std::string Bicicleta::getTipoBicicleta() const { return tipo; }
int Bicicleta::getNumeroMarchas() const { return numeroMarchas; }
bool Bicicleta::getTieneSuspension() const { return tieneSuspension; }

void Bicicleta::mostrarInformacion() const {
    std::cout << "🚲 BICICLETA - Marca: " << marca 
              << ", Modelo: " << modelo 
              << ", Placa: " << placa 
              << "\n    Tipo: " << tipo
              << ", Marchas: " << numeroMarchas
              << ", Suspensión: " << (tieneSuspension ? "Sí" : "No")
              << ", Disponible: " << (estaDisponible() ? "Sí" : "No")
              << std::endl;
}

std::string Bicicleta::getTipo() const {
    return "Bicicleta";
}