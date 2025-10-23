cmake_minimum_required(VERSION 3.10)
project(SistemaAlquiler)

# Configurar estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluir directorios de cabeceras
include_directories(include)

# Archivos fuente
set(SOURCES
    src/Vehiculo.cpp
    src/Auto.cpp
    src/Bicicleta.cpp
    src/SistemaAlquiler.cpp
    src/main.cpp
)

# Crear ejecutable
add_executable(SistemaAlquiler ${SOURCES})