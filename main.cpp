
//GESTIONAR UNA BLIOTECA
// 

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

struct Libro {
    string titulo;
    string autor;
    int anio;
};

void registrarLibro();
void mostrarCatalogo();

int main() {
    const char* port_env = getenv("PORT");
    string port = (port_env != nullptr) ? port_env : "8080";
    cout << "----Iniciando el sistema en el puerto: " << port << "----" << endl;

    int opcion;
    bool sistemaActivo = true;

    while (sistemaActivo) {
        cout << "\n--- GESTOR DE BIBLIOTECA MOONIE ---" << endl;
        cout << "1. Registrar un nuevo libro" << endl;
        cout << "2. Ver catalogo completo" << endl;
        cout << "3. Salir del sistema" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            registrarLibro();
        } 
        else if (opcion == 2) {
            mostrarCatalogo();
        } 
        else if (opcion == 3) {
            cout << "Cerrando sistema... ¡Vuelva pronto!" << endl;
            sistemaActivo = false; 
        } else {
            cout << "Error: Opcion no valida. Intentalo de nuevo." << endl;
            sistemaActivo = false;
        }
    }

    cout <<"Servicio escuchando en el puerto: " << port << endl;
    while (true){
        
    }
    

    return 0;
}


void registrarLibro() {
    Libro l;
    cout << "\n--- Ingresa los datos del libro ---" << endl;
    cout << "Titulo : ";
    cin >> l.titulo;
    cout << "Autor : ";
    cin >> l.autor;
    cout << "Anio de publicacion: ";
    cin >> l.anio;
    ofstream archivoEscritura("biblioteca.txt", ios::app);
    if (archivoEscritura.is_open()) {
        archivoEscritura << l.titulo << " " << l.autor << " " << l.anio << endl;
        archivoEscritura.close();
        cout << "¡El libro se guardo correctamente en el archivo!" << endl;
    } else {
        cout << "Error al abrir la base de datos." << endl;
    }
}

void mostrarCatalogo() {
    ifstream archivoLectura("biblioteca.txt");
    string t, a;
    int an;

    cout << "\n--- CATALOGO DE LIBROS DISPONIBLES ---" << endl;
    cout << "TITULO | AUTOR | ANIO" << endl;
    cout << "-----------------------------------" << endl;

    if (archivoLectura.is_open()) {
        while (archivoLectura >> t >> a >> an) {
            cout << t << " - " << a << " (" << an << ")" << endl;
        }
        archivoLectura.close();
    } else {
        cout << "La biblioteca esta vacia o el archivo no existe." << endl;
    }
}