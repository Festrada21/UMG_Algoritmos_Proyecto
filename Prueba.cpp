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

int main(){

   Menu(); 

}

void Menu(){
char opt;
    cout<<"Bienvenido al proyecto de Algoritmos Grupo #3 2do Semestre 2023"<<endl;
  do {
    cout<<"Menu del programa:";
      cout << "\nr. Registrar palabra\nv. Ver Diccionario\na. Actualizar palabra\nb. Borrar palabra\nt. Traducir\np. Participantes del grupo\ns. Salir\nSeleccione una opción: ";
      cin >> opt;
      switch (tolower(opt)) {
          case 'r':
              Crear();
              break;
          case 'v':
              Leer();
              break;
          case 'a':
              Actualizar();
              break;
          case 'b':
              Borrar();
              break;
          case 't':
              TraducirCodigo();
              break;
          case 'p':
              Nosotros();
              break;
         default:
            system("clear");
            cout<<"Opcion ingresada no valida"<<endl;
            break;
      }
  } while (opt != 's');
    system("clear");
    cout<<"Gracias por utilizar nuestro proyecto"<<endl;
    system("pause") ;
}