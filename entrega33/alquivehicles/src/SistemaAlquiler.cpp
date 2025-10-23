#include "SistemaAlquiler.h"
#include <iostream>

void SistemaAlquiler::registrarVehiculo(std::shared_ptr<Vehiculo> vehiculo) {
    vehiculos.push_back(vehiculo);
    std::cout << "Vehículo registrado exitosamente." << std::endl;
}

bool SistemaAlquiler::alquilarVehiculo(const std::string& placa) {
    for (auto& vehiculo : vehiculos) {
        if (vehiculo->getPlaca() == placa) {
            if (vehiculo->estaDisponible()) {
                vehiculo->setDisponible(false);
                std::cout << "Vehículo alquilado exitosamente." << std::endl;
                return true;
            } else {
                std::cout << "El vehículo no está disponible." << std::endl;
                return false;
            }
        }
    }
    std::cout << "Vehículo no encontrado." << std::endl;
    return false;
}

bool SistemaAlquiler::devolverVehiculo(const std::string& placa) {
    for (auto& vehiculo : vehiculos) {
        if (vehiculo->getPlaca() == placa) {
            if (!vehiculo->estaDisponible()) {
                vehiculo->setDisponible(true);
                std::cout << "Vehículo devuelto exitosamente." << std::endl;
                return true;
            } else {
                std::cout << "El vehículo ya estaba disponible." << std::endl;
                return false;
            }
        }
    }
    std::cout << "Vehículo no encontrado." << std::endl;
    return false;
}

void SistemaAlquiler::mostrarVehiculosDisponibles() const {
    std::cout << "\n--- VEHÍCULOS DISPONIBLES ---" << std::endl;
    int contador = 0;
    for (const auto& vehiculo : vehiculos) {
        if (vehiculo->estaDisponible()) {
            vehiculo->mostrarInformacion();
            contador++;
        }
    }
    if (contador == 0) {
        std::cout << "No hay vehículos disponibles." << std::endl;
    }
}

void SistemaAlquiler::mostrarTodosLosVehiculos() const {
    std::cout << "\n--- TODOS LOS VEHÍCULOS ---" << std::endl;
    for (const auto& vehiculo : vehiculos) {
        vehiculo->mostrarInformacion();
    }
}

Vehiculo* SistemaAlquiler::buscarVehiculo(const std::string& placa) {
    for (auto& vehiculo : vehiculos) {
        if (vehiculo->getPlaca() == placa) {
            return vehiculo.get();
        }
    }
    return nullptr;
}

int SistemaAlquiler::contarVehiculosDisponibles() const {
    int count = 0;
    for (const auto& vehiculo : vehiculos) {
        if (vehiculo->estaDisponible()) {
            count++;
        }
    }
    return count;
}

int SistemaAlquiler::contarTotalVehiculos() const {
    return vehiculos.size();
}