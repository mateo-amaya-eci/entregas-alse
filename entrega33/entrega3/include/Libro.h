

#ifndef LIBRO_H
#define LIBRO_H

// Incluye la biblioteca estándar para manejar cadenas de texto
#include <string>

// Definición de la clase Libro
class Libro {
    // Atributos privados de la clase
    std::string titulo;       // Título del libro
    std::string autor;        // Autor del libro
    std::string ISBN;         // Código ISBN del libro
    bool disponible;          // Indica si el libro está disponible o no

public:
    // Constructor: Inicializa un objeto Libro con título, autor e ISBN
    Libro(const std::string& titulo, const std::string& autor, const std::string& ISBN);

    // Métodos para obtener información del libro
    std::string getTitulo() const;  // Devuelve el título del libro
    std::string getAutor() const;    // Devuelve el autor del libro
    std::string getISBN() const;     // Devuelve el ISBN del libro
    bool estaDisponible() const;    // Devuelve si el libro está disponible

    // Método para cambiar el estado de disponibilidad del libro
    void setDisponible(bool disp);

    // Método para mostrar la información del libro
    void mostrarinfo() const;
};

// Finaliza la protección contra inclusiones múltiples
#endif // LIBRO_H
