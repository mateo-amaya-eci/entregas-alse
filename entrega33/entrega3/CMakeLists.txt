# Especifica la versión mínima requerida de CMake
cmake_minimum_required(VERSION 3.10)

# Define el nombre del proyecto
project(Biblioteca)

# Configura el estándar de C++ que se utilizará
set(CMAKE_CXX_STANDARD 17)              # Establece el estándar de C++ como C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)     # Indica que el estándar es obligatorio

# Incluir directorios de cabeceras
include_directories(include)            # Especifica el directorio "include" para buscar archivos de cabecera

# Archivos fuente
set(SOURCES                             # Define una lista de archivos fuente que forman parte del proyecto
    src/Libro.cpp                       # Archivo fuente para la clase "Libro"
    src/Biblioteca.cpp                  # Archivo fuente para la clase "Biblioteca
    src/main.cpp                        # Archivo fuente principal (punto de entrada del programa)
)

# Crear ejecutable
add_executable(Biblioteca ${SOURCES})   # Crea un ejecutable llamado "Biblioteca" usando los archivos fuente definidos