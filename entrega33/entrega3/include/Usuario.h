#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string nombre;
    std::string id;
    int maxLibrosPrestados;

public:
    Usuario(const std::string& nombre, const std::string& id, int maxLibros);
    virtual ~Usuario() = default;
    
    std::string getNombre() const;
    std::string getId() const;
    int getMaxLibrosPrestados() const;
    virtual void mostrarInfo() const;
};

class Estudiante : public Usuario {
public:
    Estudiante(const std::string& nombre, const std::string& id);
};

class Profesor : public Usuario {
public:
    Profesor(const std::string& nombre, const std::string& id);
};

#endif // USUARIO_H