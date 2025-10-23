#ifndef BiBLiOTECA_h

#define BiBLiOTECA_h

// Incluye la definición de la clase Libro
#include "Libro.h"

// Incluye la biblioteca estándar para manejar vectores
#include <vector>

// Definición de la clase Biblioteca
class Biblioteca {
    // Atributos privados
    std::vector<Libro> libros; // Vector que almacena objetos de tipo Libro

public:
    // Método para agregar un libro a la biblioteca
    void agregarLibro(const Libro& libro);

    // Método para eliminar un libro de la biblioteca usando su ISBN
    void eliminarLibro(const std::string& ISBN);

    // Método para mostrar todos los libros disponibles en la biblioteca
    void mostrarLibrosDisponibles() const;

    // Método para buscar un libro por su ISBN
    // Devuelve un puntero al libro encontrado o nullptr si no existe
    Libro* buscarLibroPorISBN(const std::string& ISBN);

    // Método para buscar un libro por su autor
    // Devuelve un puntero al libro encontrado o nullptr si no existe
    Libro* buscarporautor(const std::string& autor);
    
    Libro* buscarLibroPorTitulo(const std::string& titulo);
};

#endif // BiBLOTECA_h