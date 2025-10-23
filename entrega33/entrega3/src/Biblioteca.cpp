#include "Biblioteca.h"
#include <iostream>

void Biblioteca::agregarLibro(const Libro& libro) {
    libros.push_back(libro);
    std::cout << "Libro agregado exitosamente." << std::endl;
}

void Biblioteca::eliminarLibro(const std::string& ISBN) {
    for (auto it = libros.begin(); it != libros.end(); ++it) {
        if (it->getISBN() == ISBN) {
            libros.erase(it);
            std::cout << "Libro eliminado exitosamente." << std::endl;
            return;
        }
    }
    std::cout << "Libro no encontrado." << std::endl;
}

void Biblioteca::mostrarLibrosDisponibles() const {
    std::cout << "\n--- Libros Disponibles ---" << std::endl;
    for (const auto& libro : libros) {
        if (libro.estaDisponible()) {
            libro.mostrarinfo();
        }
    }
}
Libro* Biblioteca:: buscarLibroPorTitulo(const string& titulo) {
    for (auto& libro : libros) {
        if (libro.getTituplo() == titulo) {
            return &libro;
        }
    }
    return nullptr;
}
Libro* Biblioteca::buscarLibroPorISBN(const std::string& titulo) {
    for (auto& libro : libros) {
        if (libro.getTitulo() == titulo) {
            return &libro;
        }
    }
    return nullptr;
}

Libro* buscarporautor(const string& autor) {
    for (auto& libro : libros) {
        if (libro.getAutor() == autor) {
            return &libro;
        }
    }
    return nullptr;
}