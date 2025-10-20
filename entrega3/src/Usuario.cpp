#include "Usuario.h"
#include <iostream>

Usuario::Usuario(const std::string& nombre, const std::string& id, int maxLibros)
    : nombre(nombre), id(id), maxLibrosPrestados(maxLibros) {}

std::string Usuario::getNombre() const { return nombre; }
std::string Usuario::getId() const { return id; }
int Usuario::getMaxLibrosPrestados() const { return maxLibrosPrestados; }

void Usuario::mostrarInfo() const {
    std::cout << "Nombre: " << nombre << ", ID: " << id 
              << ", Máximo libros: " << maxLibrosPrestados << std::endl;
}

Estudiante::Estudiante(const std::string& nombre, const std::string& id)
    : Usuario(nombre, id, 3) {}

Profesor::Profesor(const std::string& nombre, const std::string& id)
    : Usuario(nombre, id, 10) {}