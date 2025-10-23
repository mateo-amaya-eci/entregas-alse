#include "Biblioteca.h"
#include <iostream>
#include "Libro.h"
using namespace std;

int main() {
    Biblioteca biblioteca;
    biblioteca.agregarLibro(Libro("Cien Años de Soledad", "Gabriel García Márquez", "197-32"));
    biblioteca.agregarLibro(Libro("1984", "George Orwell", "198-84"));
    biblioteca.agregarLibro(Libro("Don Quijote de la Mancha", "Miguel de Cervantes", "1605-01"));

    int opcion;
    do {
        cout << "\n ==== SISTEMA DE BIBLIOTECA ==== \n";
        cout << "1. Mostrar libros disponibles\n";
        cout << "2. Agregar libro\n";
        cout << "3. Eliminar libro\n";
        cout << "4. Buscar por título\n";
        cout << "5. Buscar por autor\n";
        cout << "0. Salir\n";
        cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea

        switch (opcion) {
            case 1:
                biblioteca.mostrarLibrosDisponibles();
                break;
            case 2: {
                string titulo, autor, ISBN;
                cout << "Titulo: ";
                getline(cin, titulo);
                cout << "Autor: ";
                getline(cin, autor);
                cout << "ISBN: ";
                cin >> ISBN;
                biblioteca.agregarLibro(Libro(titulo, autor, ISBN));
                break;
            }
            case 3: {
                string ISBN;
                cout << "ISBN del libro a eliminar: ";
                cin >> ISBN;
                biblioteca.eliminarLibro(ISBN);
                break;
            }
            case 4: {
                string titulo;
                cout << "Título a buscar: ";
                cin.ignore();
                getline(cin, titulo);
                Libro* libro = biblioteca.buscarLibroPorTitulo(titulo);
                if (libro) {
                    cout << "Libro encontrado:\n";
                    libro->mostrarinfo();
                } else {
                    cout << "Libro no encontrado.\n";
                }
                break;
            }
            case 5: {
                string autor;
                cout << "Autor a buscar: ";
                cin.ignore();
                getline(cin, autor);
                Libro* libro = biblioteca.buscarporautor(autor);
                if (libro) {
                    cout << "Libro encontrado:\n";
                    libro->mostrarinfo();
                } else {
                    cout << "Libro no encontrado.\n";
                }
                break;
            }
            case 0:
                cout << "Saliendo del sistema.\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }

    } while (opcion != 0);

    return 0;
}