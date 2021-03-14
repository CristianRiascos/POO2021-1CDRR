#include <iostream>
#include "actaTrabajo.h"

using std::cout;
using std::cin;

ActaTrabajo::ActaTrabajo()
{

}

// Usamos este constructor cuando no hay codirector
ActaTrabajo::ActaTrabajo( int numero, string fecha, string autor, string nombreTrabajo, trabajo tipoTrabajo, 
    string periodo, float notaFinal, string director, string jurado1, string jurado2, estado estadoTrabajo, 
    aceptacion estadoAceptacion )
{
    // Asignar valores 
    this -> numero = numero;
    this-> fecha = fecha;
    this -> autor = autor;
    this -> nombreTrabajo = nombreTrabajo;
    this -> tipoTrabajo = tipoTrabajo;
    this -> periodo = periodo;
    this -> notaFinal = notaFinal;
    this -> director = director;
    this -> jurado1;
    this -> jurado2;
    this -> estadoTrabajo = estadoTrabajo;
    this -> estadoAceptacion = estadoAceptacion;
}

// Usamos este constructor cuando hay codirector
ActaTrabajo::ActaTrabajo( int numero, string fecha, string autor, string nombreTrabajo, trabajo tipoTrabajo, 
    string periodo, float notaFinal, string director,  string codirector, string jurado1, string jurado2, 
    estado estadoTrabajo, aceptacion estadoAceptacion )
{
    // Asignar valores 
    this -> numero = numero;
    this-> fecha = fecha;
    this -> autor = autor;
    this -> nombreTrabajo = nombreTrabajo;
    this -> tipoTrabajo = tipoTrabajo;
    this -> periodo = periodo;
    this -> notaFinal = notaFinal;
    this -> director = director;
    this -> codirector = codirector;
    this -> jurado1;
    this -> jurado2;
    this -> estadoTrabajo = estadoTrabajo;
    this -> estadoAceptacion = estadoAceptacion;
}

void ActaTrabajo::crearActa()   
{
    int opcTipoTrabajo;
    int existenciaCodirector;

    cout << "\nIngrese los siguientes datos\n";

    cout << "\nNombre del autor: "; cin >> autor;
    cout << "\nNombre del trabajo: "; cin >> nombreTrabajo;

    // Implementamos un mini-menu para establecer el tipo de trabajo 
    cout << "\nCual es el tipo de trabajo?\n";      
    cout << "\n0. Aplicado\n1. Investigacion\n";
    
    while( 1 )
    {
        cout << " "; cin >> opcTipoTrabajo;

        // Dependiendo de la elección se asigna un tipo de trabajo u otro.
        if( opcTipoTrabajo == 0 )   
        {
            tipoTrabajo = trabajo::APLICADO;
            break;
        }

        else if( opcTipoTrabajo == 1 )  
        {
            tipoTrabajo = trabajo::INVESTIGACION;
            break;
        }

        // Entra en ciclo infinito hasta que ingrese una de las opciones válidas
        else
        {
            cout << "\n\tERROR: Opcion no valida, intente de nuevo.\n";
        }
    }

    cout << "\nDirector: "; cin >> director;
    
    cout << "\nHay codirector?";
    cout << "\n0. No\n1. Si";

    while( 1 )
    {
        cout << " "; cin >> existenciaCodirector;

        // Verifica si existe codirector o no
        if( existenciaCodirector == 0 )   
        {
            existeCodirector = false;
            break;
        }

        else if( existenciaCodirector == 1 )  
        {
            existeCodirector = true;
            cout << "\nCodirector: "; cin >> codirector;
            break;
        }

        // Entra en ciclo infinito hasta que ingrese una de las opciones válidas
        else
        {
            cout << "\n\tERROR: Opcion no valida, intente de nuevo.\n";
        }
    }

    cout << "\nJurado 1: "; cin >> jurado1;
    cout << "\nJurado 2: "; cin >> jurado2;
    cout << "\nPeriodo: "; cin >> periodo;

    estadoAceptacion = aceptacion::PENDIENTE;
    estadoTrabajo = estado::ABIERTA;
    system( "PAUSE()" );
}

void ActaTrabajo::cerrarActa()
{   
    estadoTrabajo = estado::CERRADA;
    // Aquí pondremos un sleep para hacer un efecto de espera mientras cierra.
    system( "PAUSE()" );
}

void calificarCriterios();
int calificarNotaFinal();
void addComentario();

