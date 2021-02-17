#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

void menu(){
    cout << "MENU\n\n";
    cout << "1. Crear el directorio con algunos contactos\n";
    cout << "2. Agregar mas contactos(nombre,apellidos,telefono)\n";
    cout << "3. Visualizar contactos\n";
    cout << "0. Salir\n\n";    
    return;
}

void sleep( unsigned milliseconds){
    Sleep( milliseconds );
}

void crearArchivo(){
    ofstream archivo( "Contactos.txt", ios::trunc );

    cout << "CREAR ARCHIVO NUEVO\n";
    if( archivo.fail() ){
        cout << "\nERROR: Ha ocurrido un error con el archivo!\n";
        exit( 1 );
    }

    cout << "\nCreando archivo. Por favor espere...\n";
    sleep( 1500 );
    cout << "\nEXITO! El archivo fue creado correctamente\n";
    archivo.close();   

    return;
}

void addContactos(){
    char nombres[ 50 ], apellidos[ 50 ], telefono [ 15 ];
    ofstream archivo("Contactos.txt", ios::app);

    cout << "ANIADIR CONTACTOS\n";
    if( archivo.fail() ){
        cout << "\nERROR:Ha ocurrido un error con el archivo!\n";
        exit( 1 );
    }

    cin.ignore();
    cout << "\nNombre: "; cin.getline( nombres, 30, '\n' );
    cout << "Apellido: "; cin.getline( apellidos, 30, '\n' );
    cout << "Telefono: "; cin.getline( telefono, 15, '\n' );

    archivo << nombres << endl;
    archivo << apellidos << endl;
    archivo << telefono << endl;
    archivo << endl;

    cout << "\nAniadiendo contactos. Por favor espere...\n";
    sleep( 1200 );
    cout << "\nEXITO! Aniadidos satisfactoriamente\n";
    archivo.close();


    return;
}

void visualizarContactos(){
    string imprimir;
    ifstream archivo( "Contactos.txt", ios::in );

    cout << "VISUALIZAR CONTACTOS\n\n";
    if( archivo.fail() ){
        cout << "ERROR: Ha ocurrido un error con el archivo!\n";
        exit( 1 );
    }

    while( !archivo.eof() ){
        getline( archivo, imprimir );
        cout << imprimir << endl;
    }

    archivo.close();
    return;
}

int main(){
    system("CLS()");
    int opc;

    while( opc != 0)
    {   
        cout << '\n';
        system("PAUSE");
        system("CLS");
        menu();
        cout << "Que desea hacer? "; cin >> opc;
        system("CLS()");  

        switch ( opc )
        {
        case 1:{  
            crearArchivo();
            break;
        }
        case 2:{
            addContactos();
            break;
        }
        case 3:{
            visualizarContactos();
            break;
        }
        case 0:{
            break;
        }
        default:{
            cout<< "\nOpcion no disponible!\n";            
            break;
        }

        }
    }
}