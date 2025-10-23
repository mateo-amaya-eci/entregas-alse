#include "Biblioteca.h"
#include <iostream>
#include <algorithm> 

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

Libro* Biblioteca::buscarLibroPorTitulo(const std::string& titulo) {
    std::string tituloLower = titulo;
    std::transform(tituloLower.begin(), tituloLower.end(), tituloLower.begin(), ::tolower); // Convertir a minúsculas

    for (auto& libro : libros) {
        std::string libroTituloLower = libro.getTitulo();
        std::transform(libroTituloLower.begin(), libroTituloLower.end(), libroTituloLower.begin(), ::tolower); // Convertir a minúsculas

        if (libroTituloLower == tituloLower) {
            return &libro;
        }
    }
    return nullptr;
}

// Método para buscar por autor
Libro* Biblioteca::buscarporautor(const std::string& autor) {
    std::string autorLower = autor;
    std::transform(autorLower.begin(), autorLower.end(), autorLower.begin(), ::tolower); // Convertir a minúsculas

    for (auto& libro : libros) {
        std::string libroAutorLower = libro.getAutor();
        std::transform(libroAutorLower.begin(), libroAutorLower.end(), libroAutorLower.begin(), ::tolower); // Convertir a minúsculas

        if (libroAutorLower == autorLower) {
            return &libro;
        }
    }
    return nullptr;
}