#include "Libro.h"
#include <iostream>

Libro::Libro(const std::string& titulo, const std::string& autor, const std::string& ISBN) 
    :titulo(titulo), autor(autor), ISBN(ISBN), disponible(true){}

std::string Libro::getTitulo() const { return titulo;}
std::string Libro::getAutor() const {return autor;}
std::string Libro::getISBN() const {return ISBN;}
bool Libro::estaDisponible() const {return disponible;}

void Libro::setDisponible(bool disp) {disponible = disp;}
void Libro:: mostrarinfo() const {
    std::cout << "titulo: " << titulo  << ", autor: " << autor  << ", ISBN: " << ISBN  << ", disponible: " << (disponible ? "si" : "no") << std::endl;

}