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

void Leer(){
    system("clear");
    //abrir un archivo
    FILE* archivo = fopen(nombre_archivo,"rb");
    if (!archivo){        
        FILE* archivo = fopen(nombre_archivo,"w+b");
    }
     Diccionario diccionario;
     int id=0; //indice o posicionicion dentro del archivo

     //leer el archivo
     fread(&diccionario,sizeof(Diccionario),1,archivo);

     cout<<"Diccionario de Palabras: "<<endl;
     cout<<"___________________________________________________________________________________"<<endl;
     cout<<left<<setw(10)<<"ID"<<"|"<<left<<setw(10)<<"Palabra"<<"|"<<left<<setw(15)<<"Traduccion"<<"|"<<left<<setw(30)<<"Funcionalidad"<<endl;
     cout<<"___________________________________________________________________________________"<<endl;
     do
     {
        cout<<left<<setw(10)<<id<<"|"<<left<<setw(10)<<diccionario.palabra<<"|"<<left<<setw(15)<<diccionario.traduccion<<"|"<<left<<setw(30)<<diccionario.funcionalidad<<endl;
        //para que cambie de registro
        fread(&diccionario,sizeof(Diccionario),1,archivo);
        id+=1;
     } while (feof(archivo)==0);
     fclose(archivo);
}

void Crear(){
    FILE* archivo = fopen(nombre_archivo,"a+b");
    char res;
    Diccionario diccionario;
    do
    {
        fflush(stdin);
        cin.ignore();
        cout<<"Ingrese palabra: "<<endl;
        cin.getline(diccionario.palabra,50);
        cout<<"Ingrese traduccion: "<<endl;
        cin.getline(diccionario.traduccion,50);
        cout<<"Ingrese funcionalidad: "<<endl;
        cin.getline(diccionario.funcionalidad,100);

        //almacenamiento de datos
        fwrite(&diccionario,sizeof(Diccionario),1,archivo);

        cout<<"Desea ingresar otro registro al Diccionario (s/n)"<<endl;
        cin>>res;
    } while (res=='s'||res=='S');
    
    fclose(archivo);
    Leer();
}

void Actualizar(){
    Leer();
    FILE* archivo = fopen(nombre_archivo,"r+b");
    char res;
    Diccionario diccionario;
    int id=0;
    cout<<"Ingrese ID a modificar: "<<endl;
    cin>>id;  
        //posicionar el puntero
        fseek(archivo,id * sizeof(Diccionario),SEEK_SET);
        cin.ignore();
        cout<<"Ingrese palabra: "<<endl;
        cin.getline(diccionario.palabra,50);
        cout<<"Ingrese traduccion: "<<endl;
        cin.getline(diccionario.traduccion,50);
        cout<<"Ingrese funcionalidad: "<<endl;
        cin.getline(diccionario.funcionalidad,100);

        //almacenamiento de datos
        fwrite(&diccionario,sizeof(Diccionario),1,archivo);

    fclose(archivo);
    Leer();
        cout<<" la Palabra "<<diccionario.palabra<<" con ID: "<<id<<" fue actualizada exitosamente."<<endl;
         cout<<"                                                                    "<<endl;
}

void Borrar(){
    Leer();
    const char *nombre_archivo_temp = "bd_temp.dat";
    FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
    FILE* archivo = fopen(nombre_archivo,"rb");
    //especificar el elemento a eliminar
    Diccionario diccionario;
    int id=0,id_n=0;

    cout<<"Ingrese el ID a eliminar: "<<endl;
    cin>>id;

    while (fread(&diccionario,sizeof(Diccionario),1,archivo)){
        if (id_n!=id)
        {
            fwrite(&diccionario,sizeof(Diccionario),1,archivo_temp);
        }
        id_n++;        
    }
 
    fclose(archivo);
    fclose(archivo_temp);

        //Crear archivo desde el temporal sin el id que se desea eliminar
        archivo_temp = fopen(nombre_archivo_temp,"rb");
        archivo = fopen(nombre_archivo,"wb");

        while (fread(&diccionario,sizeof(Diccionario),1,archivo_temp)){
        if (id_n!=id)
        {
            fwrite(&diccionario,sizeof(Diccionario),1,archivo);
        }
        id_n++;        
        }

        fclose(archivo);
        fclose(archivo_temp);
        Leer();
        cout<<"Se borró con exito la palagra: "<<diccionario.palabra<<" con Id: "<<id<<endl;
        cout<<"                                                                    "<<endl;
}

void CargarDiccionario() {
    FILE *archivo = fopen(nombre_archivo, "rb");
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de diccionario." << endl;
        exit(1);
    }

    Diccionario palabra;
    while (fread(&palabra, sizeof(Diccionario), 1, archivo)) {
        diccionario[palabra.palabra] = palabra.traduccion;
    }

    fclose(archivo);
}


string TraducirPalabra(const string &palabra) {
    // Verifica si la palabra está en el diccionario y tradúcela si es necesario
    if (diccionario.find(palabra) != diccionario.end()) {
        return diccionario[palabra];
    } else {
        return palabra;
    }
}

void TraducirCodigo() {
    CargarDiccionario();
    string texto;
    cout << "Ingrese el texto a traducir (ingrese 'fin' en una línea separada para finalizar):\n";

    int nivelEstructura = 0; // Lleva un seguimiento del nivel de anidamiento de las estructuras
    bool dentroIf = false;   // Indica si estamos dentro de una estructura if

    while (true) {
        string linea;
        getline(cin, linea);
        
        if (linea == "fin") {
            break; // Termina la entrada de texto si se ingresa "fin"
        }

        texto += linea + "\n"; // Agrega la línea al texto

        if (cin.eof()) {
            break; // Termina si se alcanza el final del archivo de entrada
        }
    }

    // Procesar y traducir el texto
    string palabra;
    string textoTraducido;

    for (char c : texto) {
        if (isalnum(c) || c == '_') {
            palabra += c;
        } else {
            // Verifica si la palabra está en el diccionario y tradúcela si es necesario
            string palabraTraducida = TraducirPalabra(palabra);
            if (!palabra.empty()) {
                textoTraducido += palabraTraducida;
                palabra.clear();
            }

            if (c == '{') {
                nivelEstructura++;
                if (nivelEstructura == 1 && dentroIf) {
                    textoTraducido += " inicio si ";
                } else if (nivelEstructura == 1) {
                    textoTraducido += " inicio ";
                } else {
                    textoTraducido += "{";
                }
            } else if (c == '}') {
                nivelEstructura--;
                if (nivelEstructura == 0) {
                    textoTraducido += " fin ";
                } else {
                    textoTraducido += "}";
                }
            } else if (c == 'i' && nivelEstructura == 1) {
                // Verifica si estamos dentro de un 'if'
                string posibleIf = palabra;
                if (posibleIf == "si" || posibleIf == "entonces") {
                    dentroIf = true;
                }
            } else if (c == 'f' && nivelEstructura == 1 && dentroIf) {
                // Verifica si estamos dentro de un 'if' y encontramos 'fin'
                string posibleFin = palabra;
                if (posibleFin == "fin") {
                    dentroIf = false;
                }
            } else {
                textoTraducido += c;
            }
        }
    }

    cout << "\nTexto traducido:\n";
    cout << textoTraducido << endl;
    cout << "_____________________";

}

void Nosotros(){
    system("clear");
    cout<<"Integrantes del grupo:"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"Nombre y apellido | Carnet "<<endl;
    cout<<"Pablo Montiel     | 3590 23 15883 "<<endl;
    cout<<"Melvin Ramos      | 5990-23-17316 "<<endl;
    cout<<"Fredy  Batz       | 3590 23 7848"<<endl;
    cout<<"Nery Osorio       | 3590-23-22940 "<<endl;
    cout<<"Francisco Estrada | 5339 23 5990"<<endl;
    cout<<"_______________________________________"<<endl;
}
