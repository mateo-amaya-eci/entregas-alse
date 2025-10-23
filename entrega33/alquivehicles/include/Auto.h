#ifndef AUTO_H
#define AUTO_H

#include "Vehiculo.h"

class Auto : public Vehiculo {
private:
    int capacidadPasajeros;
    int numeroPuertas;
    std::string tipoTransmision;

public:
    Auto(const std::string& marca, const std::string& modelo, const std::string& placa,
         int capacidadPasajeros, int numeroPuertas, const std::string& tipoTransmision);
    
    // Getters específicos
    int getCapacidadPasajeros() const;
    int getNumeroPuertas() const;
    std::string getTipoTransmision() const;
    
    // Sobrescribir métodos virtuales
    void mostrarInformacion() const override;
    std::string getTipo() const override;
};

#endif