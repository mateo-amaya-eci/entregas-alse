#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    std::string placa;
    bool disponible;

public:
    Vehiculo(const std::string& marca, const std::string& modelo, const std::string& placa);
    virtual ~Vehiculo() = default;
    
    // Getters
    std::string getMarca() const;
    std::string getModelo() const;
    std::string getPlaca() const;
    bool estaDisponible() const;
    
    // Setters
    void setDisponible(bool disp);
    
    // Método virtual que será sobreescrito por clases derivadas
    virtual void mostrarInformacion() const;
    virtual std::string getTipo() const = 0; // Método puramente virtual
};

#endif