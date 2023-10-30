#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

const char *nombre_archivo = "bd.dat";

struct diccionario {
    char palabra[50];
    char traduccion[50];
    char funcionalidad[200];
};

void leer();
void crear();
void actualizar();
void borrar();
void traducirCodigo();
void menu();
void nosotros();
void agregarPalabrasPredefinidas();

int main() {
    int opcion;
    bool entradaValida = false;

    do {
        menu();

        cout << "Ingrese de 0 al 8 la opcion deseada: ";

        if (cin >> opcion) {
            entradaValida = (opcion >= 0 && opcion <= 8);
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            entradaValida = false;
        }

        if (!entradaValida) {
            cout << "Entrada no valida. Ingrese un numero entre 0 y 8." << endl;
            
        } else {
            switch (opcion) {
                 case 0:
           			 agregarPalabrasPredefinidas();
           			 break;
                 case 1:
           			 leer();
           			 break;
       			 case 2:
           			 crear();
           			 break;
      			 case 3:
           			 actualizar();
           			 break;
       			 case 4:
          			  borrar();
          			  break;
       			 case 5:
         			 traducirCodigo();
           			 break;
                case 6:
                    system("cls || clear");  // Limpiar la consola en Windows o Unix/Linux
                    break;
                case 7:
                     nosotros();
                    break;
                case 8:
                    cout<<"Gracias por utilizar nuestro programa"<<endl;
                    cout << "Le deseo un excelente dia" << endl;
                    break;
            }
        }
    } while (opcion != 8);
    
    return 0;
}

void menu() {
    cout<<"Bienvenido al proyecto de Algoritmos Grupo #3 2do Semestre 2023"<<endl;
    cout << "Menu del programa:" << endl;
    cout << "0. Carga inicial de palabras" << endl;
    cout << "1. Leer el diccionario" << endl;
    cout << "2. Agregar una palabra" << endl;
    cout << "3. Actualizar una palabra" << endl;
    cout << "4. Borrar una palabra" << endl;
    cout << "5. Traducir codigo C++" << endl;
    cout << "6. Limpiar pantalla y mostrar menu" << endl;
    cout << "7. Nosotros" << endl;
    cout << "8. Salir" << endl;
}

void agregarPalabrasPredefinidas() {
    diccionario nuevasPalabras[] = {
{"asm","Ensamblador","Define una seccion de codigo en lenguaje ensamblador"},
{"auto","Automatico","Infiere automaticamente el tipo de una variable"},
{"bool","Booleano","Representa un valor logico, verdadero o falso"},
{"break","Salto","Rompe un bucle o una estructura de control"},
{"case","Caso","Define una opcion en una sentencia `switch`"},
{"catch","Captura","Maneja excepciones en bloques `try catch`"},
{"char","Caracter","Almacena un caracter en 8 bits"},
{"class","Clase","Define una plantilla para la creacion de objetos"},
{"const","Constante","Define una variable inmutable"},
{"const_cast","Conversionconstante","Convierte entre tipos de datos constante y no constante"},
{"continue","Continuar","Salta al siguiente ciclo de bucle"},
{"default","Predeterminado","Define un caso por defecto en un `switch`"},
{"delete","Borrar","Libera la memoria asignada dinamicamente"},
{"do","Hacer","Inicia un bucle do while"},
{"double","Dobleprecision","Almacena numeros en coma flotante de doble precision"},
{"dynamic_cast","Conversiondinamica","Realiza conversiones seguras en tiempo de ejecucion"},
{"else","Entonces","Define una rama alternativa en una sentencia `if`"},
{"enum","Enumeracion","Define un conjunto de valores nombrados"},
{"explicit","Explícito","Restringe la conversion automatica de tipos"},
{"extern","Externo","Declara una variable o funcion externa"},
{"false","Falso","Representa el valor logico falso"},
{"float","Flotante","Almacena numeros en coma flotante de precision simple"},
{"for","Para","Inicia un bucle con una expresion de control"},
{"friend","Amigo","Permite el acceso a miembros privados desde una clase externa"},
{"goto","Ira","Salta a una etiqueta específica en el codigo"},
{"if","Si","Inicia una sentencia condicional"},
{"inline","Enlínea","Sugiere que la funcion sea inlined por el compilador"},
{"int","Entero","Almacena numeros enteros"},
{"long","Largo","Almacena numeros enteros largos"},
{"mutable","Mutable","Permite modificar miembros de una clase constante"},
{"namespace","Espaciodenombres","Agrupa elementos para evitar conflictos de nombres"},
{"new","Nuevo","Asigna memoria en tiempo de ejecucion"},
{"operator","Operador","Define operadores personalizados para tipos de datos"},
{"private","Privado","Limita el acceso a miembros de una clase"},
{"protected","Protegido","Permite el acceso a miembros desde clases derivadas"},
{"public","Publico","Permite el acceso libre a miembros de una clase"},
{"register","Registro","Solicita que se utilice un registro de CPU para una variable"},
{"reinterpret_cast","Conversiondereinterpretacion","Realiza conversiones de tipo peligrosas"},
{"return","Retorno","Finaliza una funcion y devuelve un valor"},
{"short","Corto","Almacena numeros enteros cortos"},
{"signed","Consigno","Define numeros enteros con signo"},
{"sizeof","Tamaño","Devuelve el tamaño en bytes de un tipo de datos"},
{"static","Estatico","Limita el alcance de una variable a un archivo"},
{"static_cast","Conversionestatica","Realiza conversiones seguras en tiempo de compilacion"},
{"struct","Estructura","Define una estructura de datos"},
{"switch","Conmutar","Inicia una sentencia de seleccion multiple"},
{"template","Plantilla","Define plantillas de codigo reutilizables"},
{"this","Este","Hace referencia al objeto actual"},
{"throw","Lanzar","Lanza una excepcion"},
{"true","Verdadero","Representa el valor logico verdadero"},
{"try","Intentar","Define un bloque para manejar excepciones"},
{"typedef","Definirtipo","Crea alias para tipos de datos"},
{"typeid","TipodeID","Obtiene informacion sobre el tipo de un objeto"},
{"typename","Nombredetipo","Especifica un tipo de dato en plantillas"},
{"union","Union","Almacena varios tipos de datos en la misma ubicacion"},
{"unsigned","Sinsigno","Define numeros enteros sin signo"},
{"using","Usar","Hace que los nombres estén disponibles en el ambito actual"},
{"virtual","Virtual","Define funciones virtuales para la herencia"},
{"void","Vacio","Representa la falta de tipo o valor"},
{"volatile","Volatil","Indica que la variable puede cambiar en cualquier momento"},
{"while","Mientras","Inicia un bucle mientras se cumpla una condicion"},

        // Agrega mas palabras en el mismo formato si es necesario
    };

    FILE* archivoDiccionario = fopen(nombre_archivo, "wb");  // "wb" para abrir en modo escritura y borrar el contenido existente
    if (!archivoDiccionario) {
        cout << "No se pudo abrir el archivo del diccionario." << endl;
        return;
    }

    for (int i = 0; i < sizeof(nuevasPalabras) / sizeof(diccionario); i++) {
        // Escribir la nueva palabra en el archivo del diccionario
        fwrite(&nuevasPalabras[i], sizeof(diccionario), 1, archivoDiccionario);
    }

    fclose(archivoDiccionario);
    system("cls || clear");
    cout << "Palabras predefinidas agregadas al diccionario exitosamente." << endl;
}

void leer() {
      system("cls");
    FILE *archivo = fopen(nombre_archivo, "rb");
    if (!archivo) {
        archivo = fopen(nombre_archivo, "w+b");
    }
    diccionario diccionario;
    int id = 0;
    fread(&diccionario, sizeof(diccionario), 1, archivo);
    cout <<left<<setw(130)<< "____________________Inicio de DIccionario______________________" << endl;
    cout <<left<<"id" <<left<<setw(20)<< "      Palabra:   " <<left<<setw(20)<< "    Traduccion: " <<left<<setw(20)<<"       Funcionalidad: " << endl;
    do {
        cout << id << "  | " <<left<<setw(20)<< diccionario.palabra << " | " <<left<<setw(20)<< diccionario.traduccion << " | " << diccionario.funcionalidad << endl;
       
        fread(&diccionario, sizeof(diccionario), 1, archivo);
        id += 1;
    } while (feof(archivo) == 0);
    cout <<left<<setw(130)<< "____________________Fin de Diccionario_________________________" << endl;
    cout<<endl;
    fclose(archivo);
}

void crear() {
    FILE *archivo = fopen(nombre_archivo, "a+b");
    char res;
    diccionario diccionario;
    do {
        fflush(stdin);
  
        cout << "Ingrese Palabra: ";
        cin >> diccionario.palabra;
        cin.ignore();

        cout << "Ingrese Traduccion: ";
        cin.getline(diccionario.traduccion, 50);

        cout << "Ingrese Funcionalidad: ";
        cin.getline(diccionario.funcionalidad, 50);

        fwrite(&diccionario, sizeof(diccionario), 1, archivo);
        
        cout << "Desea agregar otra palabra (s/n): ";
        cin >> res;

    } while (res == 's' || res == 'S');
    fclose(archivo);
    system("cls || clear");
    leer();
}

void actualizar() {
     FILE *archivo = fopen(nombre_archivo, "r+b");
    diccionario diccionario;
    int id = 0;
    cout << "Ingrese el ID que desea actualizar: ";
    cin >> id;
    fseek(archivo, id * sizeof(diccionario), SEEK_SET);

    cout << "Ingrese la palabra: ";
    cin >> diccionario.palabra;
    cin.ignore();

    cout << "Ingrese Traduccion: ";
    cin.getline(diccionario.traduccion, 50);

    cout << "Ingrese Funcionalidad: ";
    cin.getline(diccionario.funcionalidad, 50);

    fwrite(&diccionario, sizeof(diccionario), 1, archivo);

    fclose(archivo);
    system("cls || clear");
    leer();
}

void borrar() {
     const char *nombre_archivo_temp = "archivo_temp.dat";
    FILE *archivo_temp = fopen(nombre_archivo_temp, "w+b");
    FILE *archivo = fopen(nombre_archivo, "rb");
    diccionario diccionario;
    int id = 0, id_n = 0;
    cout << "Ingrese el ID a eliminar: ";
    cin >> id;

    while (fread(&diccionario, sizeof(diccionario), 1, archivo)) {
        if (id_n != id) {
            fwrite(&diccionario, sizeof(diccionario), 1, archivo_temp);
            id_n++;
        }
    }

    fclose(archivo);
    fclose(archivo_temp);

    archivo_temp = fopen(nombre_archivo_temp, "rb");
    archivo = fopen(nombre_archivo, "wb");
    while (fread(&diccionario, sizeof(diccionario), 1, archivo_temp)) {
        fwrite(&diccionario, sizeof(diccionario), 1, archivo);
    }

    fclose(archivo);
    fclose(archivo_temp);
    system("cls || clear");
    leer();
}

void traducirCodigo() {
    cin.ignore();  // Limpia el buffer de entrada.
    string codigo;
    cout << "Ingresa el codigo C++ a traducir (termina con una linea en blanco):\n";
    
    // Lee el código línea por línea y agrégalo a la variable 'codigo'.
    string linea;
    string inicioReemplazar = " Inicio ";
	string finReemplazar = " Fin ";
	string inicioReemplazarSi = " Inicio Si";
	string finReemplazarSi = "Fin Si \n Entonces Inicio Entonces";
	string inicioReemplazarElse = " Inicio entonces ";
	string finReemplazarElse = " Fin entonces ";
	
    bool dentroDeIf = false;
    bool dentroDeElseIf = false;

    while (getline(cin, linea) && !linea.empty()) {
        if (linea.find("if (") != string::npos) {
            dentroDeIf = true;
			
            size_t posicionInicio = linea.find("{");
			while (posicionInicio != string::npos) {
    			linea.replace(posicionInicio, 1, inicioReemplazarSi);
    			posicionInicio = linea.find("{", posicionInicio + inicioReemplazarSi.length());
				}
	
        }else if (linea.find("}else{") != string::npos) {
        	 if (dentroDeIf) {
                size_t posicionInicio = linea.find("}else{");
				while (posicionInicio != string::npos) {
    				linea.replace(posicionInicio, 6, finReemplazarSi);
    		   		posicionInicio = linea.find("}else{", posicionInicio + finReemplazarSi.length());
				}
                dentroDeIf = false;
                dentroDeElseIf = true;
            } 
			
		}else if (linea.find("}") != string::npos) {    
		 if (dentroDeElseIf) {
		 	    size_t posicionInicio = linea.find("}");
				while (posicionInicio != string::npos) {
    				linea.replace(posicionInicio, 1, finReemplazarElse);
    		   		posicionInicio = linea.find("}", posicionInicio + finReemplazarElse.length());
				}
		 	dentroDeElseIf=false;
		 }else{
		 	size_t posicionInicio = linea.find("}");
				while (posicionInicio != string::npos) {
    				linea.replace(posicionInicio, 1, finReemplazar);
    		   		posicionInicio = linea.find("}", posicionInicio + finReemplazar.length());
				}
		 }
		 
	    }else if (linea.find("{") != string::npos){
	    		size_t posicionInicio = linea.find("{");
				while (posicionInicio != string::npos) {
    				linea.replace(posicionInicio, 1, inicioReemplazar);
    		   		posicionInicio = linea.find("{", posicionInicio + inicioReemplazar.length());
				}
		}        
        
        codigo += linea + '\n';
}

    ifstream archivo(nombre_archivo, ios::in | ios::binary);
    diccionario palabra;
    while (archivo.read(reinterpret_cast<char*>(&palabra), sizeof(diccionario))) {
        // Reemplace las palabras en el código por sus traducciones.
        string palabraBuscar(palabra.palabra);
        string palabraReemplazar(palabra.traduccion); // Declaración de palabraReemplazar aquí
        size_t posicion = codigo.find(palabraBuscar);
        while (posicion != string::npos) {
            codigo.replace(posicion, palabraBuscar.length(), palabraReemplazar);
            posicion = codigo.find(palabraBuscar);
        }
    }
    
    archivo.close();
    
    cout << "\nCodigo traducido:\n" << codigo << endl;
}

void nosotros(){
    system("clear");
    cout<<"Integrantes del grupo:"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<" Seccion D "<<endl;
    cout<<"Nombre y apellido | Carnet "<<endl;
    cout<<"Pablo Montiel     | 3590 23 15883 "<<endl;
    cout<<"Fredy  Batz       | 3590 23 7848"<<endl;
    cout<<"Nery Osorio       | 3590-23-22940 "<<endl;
    cout<<" Seccion C "<<endl;
    cout<<"Nombre y apellido | Carnet "<<endl;
    cout<<"Melvin Ramos      | 5990-23-17316 "<<endl;
    cout<<"Francisco Estrada | 5990 23 5339"<<endl;
    cout<<"_______________________________________"<<endl;
}