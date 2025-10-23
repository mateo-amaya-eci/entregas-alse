#ifndef SISTEMAALQUILER_H
#define SISTEMAALQUILER_H

#include "Vehiculo.h"
#include <vector>
#include <memory>

class SistemaAlquiler {
private:
    std::vector<std::shared_ptr<Vehiculo>> vehiculos;

public:
    // Registrar vehículos
    void registrarVehiculo(std::shared_ptr<Vehiculo> vehiculo);
    
    // Operaciones de alquiler
    bool alquilarVehiculo(const std::string& placa);
    bool devolverVehiculo(const std::string& placa);
    
    // Consultas
    void mostrarVehiculosDisponibles() const;
    void mostrarTodosLosVehiculos() const;
    Vehiculo* buscarVehiculo(const std::string& placa);
    
    // Estadísticas
    int contarVehiculosDisponibles() const;
    int contarTotalVehiculos() const;
};

#endif