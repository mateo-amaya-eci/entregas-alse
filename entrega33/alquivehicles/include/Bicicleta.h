#ifndef BICICLETA_H
#define BICICLETA_H

#include "Vehiculo.h"

class Bicicleta : public Vehiculo {
private:
    std::string tipo; // Montaña, Carrera, Urbana, etc.
    int numeroMarchas;
    bool tieneSuspension;

public:
    Bicicleta(const std::string& marca, const std::string& modelo, const std::string& placa,
              const std::string& tipo, int numeroMarchas, bool tieneSuspension);
    
    // Getters específicos
    std::string getTipoBicicleta() const;
    int getNumeroMarchas() const;
    bool getTieneSuspension() const;
    
    // Sobrescribir métodos virtuales
    void mostrarInformacion() const override;
    std::string getTipo() const override;
};

#endif