#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <fstream>

using namespace std;

const char *nombre_archivo="bd.dat";
struct Diccionario{

    char palabra[50];
    char traduccion[50];
    char funcionalidad[100];

};

map<string, string> diccionario; // Mapa para almacenar palabras y sus traducciones

//instanciar metodos
void Leer();
void Crear();
void Nosotros();
void Actualizar();
void Borrar();
void Menu();
void CargarDiccionario();
string TraducirPalabra(const string &palabra);
void TraducirCodigo();