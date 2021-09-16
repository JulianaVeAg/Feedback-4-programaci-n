//============================================================================
// Name        : feedback4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

void agenda();
void leerAgenda();
void agregarContactos();
string nombreArchivo;

int main() {
	
	agenda();
	leerAgenda();
	agregarContactos();
	

	
	return 0;
}

void agenda(){
	ofstream agenda;
	char respuesta;

	string contenidoAgenda;
	//int n;
	
	//Si queremos que el nombre del archivo lo ponga el usuario.
	
	cout<<"Por favor escriba como desea que se llame el archivo";
	getline(cin,nombreArchivo);
	
	agenda.open(nombreArchivo.c_str(), ios::out);
	
	//Si queremos poner nosotros mismos el nombre del archivo solo debemos ponerla aqui.
	//agenda.open("agenda.txt", ios::out);
	
	if(agenda.fail()){
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	
	//Para escribir en el archivo utilizaremos:
	
	/*agenda<< "esta sera un agenda con los datos personales de varios contactos";
	agenda<<"Nombre: Juan" << endl;
	agenda<<"Apellido: Palomo" << endl;
	agenda<<"Telefono: 6000000" << endl;
	
	agenda<<"Nombre: Sofia" << endl;
	agenda<<"Apellido: Garcia" << endl;
	agenda<<"Telefono: 6001111" << endl;
	

	agenda<<"Nombre: Josue" << endl;
	agenda<<"Apellido: Roa" << endl;
	agenda<<"Telefono: 622222" << endl;

	*/
	
	//Pero si queremos que sea el usuario quien rellene los datos de la agenda utilizaremos:
	
	cout << "Por favor introduzca los datos que desea guardar en la agenda" <<endl;

	
	
	do{
	 cout << "Introduzca el contacto" << endl;
	 getline(cin,contenidoAgenda);
     agenda<<contenidoAgenda<<endl;
    
     cout << "¿Quieres seguir agregando contactos" << endl;
     cin>>respuesta;
     fflush(stdin);
	}while((respuesta=='S') || (respuesta=='s'));
	
	
	agenda.close();
}

void leerAgenda(){
	ifstream agenda;
	string texto;
	fflush(stdin);
	
	agenda.open(nombreArchivo.c_str(), ios::in);
	
	if(agenda.fail()){
			cout << "No se pudo abrir el archivo";
			exit(1);
		}
	
	while(!agenda.eof()){
		getline(agenda,texto);
		cout << texto << endl;
	}
	
	
	
	agenda.close();
}
void agregarContactos(){
	
	ofstream agenda;

	
	agenda.open(nombreArchivo.c_str(), ios::app);
	
	if(agenda.fail()){
				cout << "No se pudo abrir el archivo";
				exit(1);
	}
	
	//Hay dos opciones de añadir texto a nuestro archivo
	
	//Primera opcion
	
	/*agenda<<"\nvamos a proceder a agrear mas coctactos" << endl;
	agenda<< "Daniela velasquez 6588888" << endl;
	agenda<<"Maria egugenia jsdjsa" << endl;
	*/
	//Segunda opcion:
	
	string textoAgregado;
	cout << "Introduzca el texto que desea añadir\n" << endl;
	getline(cin,textoAgregado);
	
	agenda<<textoAgregado; 
	
	agenda.close();
	}