#include "SistemaAlquiler.h"
#include "Auto.h"
#include "Bicicleta.h"
#include <iostream>
#include <memory>

void mostrarMenu() {
    std::cout << "\n=== SISTEMA DE ALQUILER DE VEHÍCULOS ===" << std::endl;
    std::cout << "1. Registrar vehículo" << std::endl;
    std::cout << "2. Mostrar vehículos disponibles" << std::endl;
    std::cout << "3. Mostrar todos los vehículos" << std::endl;
    std::cout << "4. Alquilar vehículo" << std::endl;
    std::cout << "5. Devolver vehículo" << std::endl;
    std::cout << "6. Buscar vehículo por placa" << std::endl;
    std::cout << "7. Estadísticas" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Seleccione una opción: ";
}

void registrarVehiculo(SistemaAlquiler& sistema) {
    int tipo;
    std::cout << "\nTipo de vehículo:" << std::endl;
    std::cout << "1. Auto" << std::endl;
    std::cout << "2. Bicicleta" << std::endl;
    std::cout << "Seleccione: ";
    std::cin >> tipo;
    std::cin.ignore();

    std::string marca, modelo, placa;
    std::cout << "Marca: ";
    std::getline(std::cin, marca);
    std::cout << "Modelo: ";
    std::getline(std::cin, modelo);
    std::cout << "Placa: ";
    std::getline(std::cin, placa);

    if (tipo == 1) {
        int capacidad, puertas;
        std::string transmision;
        std::cout << "Capacidad de pasajeros: ";
        std::cin >> capacidad;
        std::cout << "Número de puertas: ";
        std::cin >> puertas;
        std::cin.ignore();
        std::cout << "Tipo de transmisión (Manual/Automática): ";
        std::getline(std::cin, transmision);

        sistema.registrarVehiculo(std::make_shared<Auto>(marca, modelo, placa, capacidad, puertas, transmision));
    } else if (tipo == 2) {
        std::string tipoBici;
        int marchas;
        char suspension;
        std::cout << "Tipo de bicicleta (Montaña/Carrera/Urbana): ";
        std::getline(std::cin, tipoBici);
        std::cout << "Número de marchas: ";
        std::cin >> marchas;
        std::cout << "¿Tiene suspensión? (s/n): ";
        std::cin >> suspension;
        std::cin.ignore();

        sistema.registrarVehiculo(std::make_shared<Bicicleta>(marca, modelo, placa, tipoBici, marchas, suspension == 's'));
    }
}

int main() {
    SistemaAlquiler sistema;
    
    // Agregar algunos vehículos de ejemplo
    sistema.registrarVehiculo(std::make_shared<Auto>("Toyota", "Corolla", "ABC123", 5, 4, "Automática"));
    sistema.registrarVehiculo(std::make_shared<Auto>("Honda", "Civic", "DEF456", 5, 4, "Manual"));
    sistema.registrarVehiculo(std::make_shared<Bicicleta>("Trek", "X-Caliber", "BIC001", "Montaña", 21, true));
    sistema.registrarVehiculo(std::make_shared<Bicicleta>("Specialized", "Allez", "BIC002", "Carrera", 18, false));

    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore();

        switch(opcion) {
            case 1:
                registrarVehiculo(sistema);
                break;
                
            case 2:
                sistema.mostrarVehiculosDisponibles();
                break;
                
            case 3:
                sistema.mostrarTodosLosVehiculos();
                break;
                
            case 4: {
                std::string placa;
                std::cout << "Placa del vehículo a alquilar: ";
                std::getline(std::cin, placa);
                sistema.alquilarVehiculo(placa);
                break;
            }
                
            case 5: {
                std::string placa;
                std::cout << "Placa del vehículo a devolver: ";
                std::getline(std::cin, placa);
                sistema.devolverVehiculo(placa);
                break;
            }
                
            case 6: {
                std::string placa;
                std::cout << "Placa del vehículo a buscar: ";
                std::getline(std::cin, placa);
                Vehiculo* vehiculo = sistema.buscarVehiculo(placa);
                if (vehiculo) {
                    std::cout << "Vehículo encontrado: ";
                    vehiculo->mostrarInformacion();
                } else {
                    std::cout << "Vehículo no encontrado." << std::endl;
                }
                break;
            }
                
            case 7: {
                std::cout << "\n--- ESTADÍSTICAS ---" << std::endl;
                std::cout << "Total de vehículos: " << sistema.contarTotalVehiculos() << std::endl;
                std::cout << "Vehículos disponibles: " << sistema.contarVehiculosDisponibles() << std::endl;
                std::cout << "Vehículos alquilados: " << sistema.contarTotalVehiculos() - sistema.contarVehiculosDisponibles() << std::endl;
                break;
            }
                
            case 0:
                std::cout << "Saliendo del sistema..." << std::endl;
                break;
                
            default:
                std::cout << "Opción no válida." << std::endl;
        }
        
    } while (opcion != 0);
    
    return 0;
}