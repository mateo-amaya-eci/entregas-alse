#include <iostream> 
#include <string>
#include <list>
using namespace std;

class producto{
    string nombre;
    double precio;
    int stock;
public:
    producto(string n = "", double p = 0.0, int s = 0) : nombre(n), precio(p), stock(s) {};
    string getnombre() const {return nombre;}
    double getprecio() const { return precio;}
    int getstock() const { return stock;}
    
    void mostrarProducto() const {
        cout << "Nombre: " << nombre << ", Precio: $" << precio << ", Stock: " << stock << endl;
    }
    
    double getPrecioTotal() const {
        return precio * stock;
    }
};

class carritocompras{
public:
    list<producto> items;
    
    void agregarproducto(const producto& p) {
        items.push_back(p);
        cout << "Producto '" << p.getnombre() << "' agregado al carrito." << endl;
    };
    
    void eliminarProducto(const string& nombre) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getnombre() == nombre) {
                cout << "Producto eliminado: " << it->getnombre() << endl;
                items.erase(it);
                return;
            }
        }
        cout << "Producto '" << nombre << "' no encontrado en el carrito." << endl;
    };
    
    void mostrarProductos() {
        if (items.empty()) {
            cout << "El carrito está vacío." << endl;
            return;
        }
        
        cout << "\n--- Productos en el carrito ---" << endl;
        int contador = 1;
        for (const auto& item : items) {
            cout << contador << ". ";
            item.mostrarProducto();
            cout << "   Subtotal: $" << item.getPrecioTotal() << " (" << item.getstock() << " x $" << item.getprecio() << ")" << endl;
            contador++;
        }
    }
    
    void totalcompra(){
        if (items.empty()) {
            cout << "El carrito está vacío." << endl;
            return;
        }
        
        double total = 0.0;
        cout << "\n--- Detalle de la compra ---" << endl;
        for (const auto& item : items) {
            double subtotal = item.getPrecioTotal();
            cout << "Producto: " << item.getnombre() << ", Precio: $" << item.getprecio() 
                << ", Cantidad: " << item.getstock() << ", Subtotal: $" << subtotal << endl;
            total += subtotal;
        }
        cout << "Total de la compra: $" << total << endl;
    }
    
    bool vacio() const {
        return items.empty();
    }
};

class usuario{
    list<carritocompras> historial;
public:
    void agregarhistorial(const carritocompras& c) {
        if (!c.items.empty()) {
            historial.push_back(c);
            cout << "\n--- Compra guardada en historial ---" << endl;
            
            // Mostrar todo el historial automáticamente
            cout << "\n--- HISTORIAL COMPLETO DE COMPRAS ---" << endl;
            int compraNum = 1;
            for (const auto& carrito : historial) {
                cout << "Compra #" << compraNum << ":" << endl;
                double totalCompra = 0.0;
                for (const auto& prod : carrito.items) {
                    double subtotal = prod.getPrecioTotal();
                    cout << "  - " << prod.getnombre() << ": $" << prod.getprecio() 
                        << " x " << prod.getstock() << " = $" << subtotal << endl;
                    totalCompra += subtotal;
                }
                cout << "  Total: $" << totalCompra << endl << endl;
                compraNum++;
            }
        }
    };
};

producto crearProducto() {
    string nombre;
    double precio;
    int stock;
    
    cout << "Ingrese nombre del producto: ";
    getline(cin, nombre);
    
    cout << "Ingrese precio del producto: ";
    cin >> precio;
    
    cout << "Ingrese stock del producto: ";
    cin >> stock;
    
    cin.ignore();
    return producto(nombre, precio, stock);
}

int main() {
    carritocompras carrito;
    usuario usuario1;
    int opcion;
    
    do {
        cout << "\n=== MENÚ DE COMPRAS ===" << endl;
        cout << "1. Agregar producto al carrito" << endl;
        cout << "2. Eliminar producto del carrito" << endl;
        cout << "3. Mostrar productos en carrito" << endl;
        cout << "4. Mostrar total de la compra" << endl;
        cout << "5. Finalizar compra (guardar en historial)" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        
        cin >> opcion;
        cin.ignore();
        
        switch(opcion) {
            case 1: {
                producto nuevoProducto = crearProducto();
                carrito.agregarproducto(nuevoProducto);
                break;
            }
            case 2: {
                if (carrito.vacio()) {
                    cout << "El carrito está vacío." << endl;
                } else {
                    carrito.mostrarProductos();
                    string nombre;
                    cout << "Ingrese el nombre del producto a eliminar: ";
                    getline(cin, nombre);
                    carrito.eliminarProducto(nombre);
                }
                break;
            }
            case 3:
                carrito.mostrarProductos();
                break;
            case 4:
                carrito.totalcompra();
                break;
            case 5:
                if (carrito.vacio()) {
                    cout << "El carrito está vacío. No se puede finalizar la compra." << endl;
                } else {
                    usuario1.agregarhistorial(carrito);
                    // Limpiar el carrito después de finalizar la compra
                    carrito = carritocompras();
                    cout << "Carrito vaciado. Puede comenzar una nueva compra." << endl;
                }
                break;
            case 0:
                cout << "¡Gracias por usar el sistema de compras!" << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }
        
    } while (opcion != 0);
    
    return 0;
}