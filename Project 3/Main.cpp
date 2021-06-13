#include <iostream>
#include <algorithm>    // Librería usada par ciertos usos de std
#include <windows.h>    // Librería usada para el mapa e interacción con teclado
#include <time.h>
#include <cstdlib>
#include <conio.h>

#include "Boss.hpp"
#include "Enemy.hpp"
#include "Herz.hpp"
#include "Character.hpp"
#include "Item.hpp"

// Flechas para mover a HERZ
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80 
#define EXIT 27     // Tecla asignada: escape    
#define NEW 110     // Tecla asignada: N 

using namespace::std;
int map[ 100 ][ 50 ];
void gotoxy( int x, int y );

int contEnemy;      // Cuenta el número de enemigos
int contBoss;       // Cuenta el número de jefes
int contPotion;     // Cuenta el número de pociones

// Función para la posición del cursor
void gotoxy( int x, int  y )
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    HANDLE hstdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleCursorPosition( hstdOut, coord );
    return;
}


// Función para ocultar el cursor en la consola
void ocultarCursor()
{
    HANDLE consol;
    consol = GetStdHandle( STD_OUTPUT_HANDLE );
    CONSOLE_CURSOR_INFO hide;
    hide.dwSize = 5;    // Tipo cursor
    hide.bVisible = FALSE;  // Ocultar cursor
    SetConsoleCursorInfo( consol, &hide );
    return;
}


void intro()
{
    system("CLS");
    cout << "" << endl;
    cout << "             _______________________________________________________ " << endl;
    cout << "            *                                                       *" << endl;
    cout << "            |                                                       |" << endl;
    cout << "            |          Presiona cualquier tecla para jugar          |" << endl;
    cout << "            |                                                       |" << endl;
    cout << "            *_______________________________________________________*" << endl;
    ocultarCursor();
    getch();
    system("CLS");
}


void maze()
{  
    // Creación de tablero
    int contThree = 60;  // Contador para limitar el 3
    int contFour = 250;     // Contador para limitar el 4
    int contFive = 120;

    //  Cada ejecución de maze hace que el contador de enemigos, jefes y pociones sea 1
    contEnemy = 1;
    contBoss = 1;
    contPotion = 1;

    srand( time( NULL) );

    for( int i = 9; i < 61; i++ )
    {
        for( int j = 4; j < 31; j++ )
        {
            map[i][j] = rand() % 5;     // Genera número aleatorio

            // Si es 0, pone una pared en dicha posición 
            if( map[i][j] == 0 )    
            {
                gotoxy( i, j );
                cout << (char) 219;
            }

            // Si es 3, coloca un enemigo normal
            else if( map[i][j] == 3  )   
            {
                map[i][j] = 1;     // Cambia el valor de la posicion a 1 para que se pueda mover
                
                // Cada 50 veces que map[i][j] sea 3, se pone un enemigo
                if( contEnemy <= 25 && contThree >= 50 )        
                {
                    map[i][j] = 3;  // Si entra al bucle, vuelve a cambiar el valor a 3
                    contThree = 0;          
                    contEnemy++;
                    gotoxy( i, j );
                    cout << (char) 146;
                }
            }

            // Si es 4, coloca un jefe
            else if( map[i][j] == 4  )    
            {
                map[i][j] = 2;     // Cambia el valor de la posicion a 2 para que se pueda mover
                // Cada 50 veces que map[i][j] sea 3, se pone un enemigo
                if( contBoss <= 5 && contFour >= 225 )        
                {
                    map[i][j] = 4;  // Si entra al bucle, vuelve a cambiar el valor a 4
                    contFour = 0;   // Resetea contador
                    contBoss++;
                    gotoxy( i, j );
                    cout << (char) 21;
                }
            }
            
            else if( map[i][j] == 5  )    
            {
                map[i][j] = 1;     // Cambia el valor de la posicion a 2 para que se pueda mover
                
                // Cada 50 veces que map[i][j] sea 3, se pone un enemigo
                if( contPotion <= 5 && contFive >= 120 )        
                {
                    map[i][j] = 5;  // Si entra al bucle, vuelve a cambiar el valor a 5
                    contFive = 0;   // Resetea contador
                    contPotion++;
                    gotoxy( i, j );
                    cout << (char) 21;
                }
            }

            else{
                gotoxy( i, j );
                cout << " ";
            }
            
            contThree++;    /// Sube el valor de contThree, cada 50, puede poner un enemigo
            contFour++;     /// Sube el valor de contFour, cada 200, puede poner un jefe
            contFive++;     // Sube el valor de contFive, cada 120, puede poner un item 
            
        }
    }
}


void border()
{
    // Parte horizontal
    for( int i = 9; i < 62; i++ )
    {
        gotoxy( i, 3 );
        cout << (char) 205;
        gotoxy( i, 31 );
        cout << (char) 205;
    }

    // Pared vertical
    for( int j = 4; j < 31; j++ )
    {
        gotoxy( 8, j );
        cout << (char) 186;
        gotoxy( 61, j );
        cout << (char) 186;
    }

    gotoxy( 8, 3 );
    cout << (char) 201;     // Diagonal superior izquierda
    gotoxy( 61, 3 );
    cout << (char) 187;     // Diagonal inferior derecha
    gotoxy( 8, 31 );
    cout << (char) 200;     // Digonal inferior izquierda
    gotoxy( 61, 31 );
    cout << (char) 188;     // Diagonal superior derecha
}


int arrowsMovement()
{
    bool isfinish = false;     // Bandera de fin de mapa 
    int x = 9, y = 4;   // Coordenadas de inicio
    gotoxy( x, y );
    Herz herz( 100, 25 );
    cout << (char) 4;   // "Diseño" del jugador

    while( !( isfinish ) )
    {
        if( kbhit() )
        {
            char key = getch();
            gotoxy( x, y );
            cout << " ";

            // Movimiento de acuerdo a las flechas que sean pulsadas por el jugador
            if( key == LEFT )
            if( map[ x-1 ][y] == 1 || map[ x-1 ][y] == 2 && x > 8 ) x--;

            if( key == RIGHT )
            if( map[ x+1 ][y] == 1 || map[ x+1 ][y] == 2 && x < 60 ) x++ ;

            if( key == UP )
            if( map[x][ y-1 ] == 1 || map[x][ y-1 ] == 2 && y > 4 ) y--;

            if( key == DOWN )
            if( map[x][ y+1 ] == 1 || map[x][ y+1 ] == 2 && y < 41 ) y++;

            gotoxy( x, y ); cout << (char) 4;

            // Si entra a este bucle, el jugador ha ganado
            if( ( x == 60 && y == 30 )||( x == 60 && y == 4 ) )
            {
                system( "CLS" );
                gotoxy( 32, 15 );
                cout << "Felicitaciones!!" << endl;
                gotoxy( 28, 16 );
                cout << "Has obtenido la reliquia y terminado el juego" << endl;

                gotoxy( 28, 20 );
                cout << "Presiona Escape para salir" << endl;

                gotoxy( 28, 23 );
                cout << "Presiona N para un " << endl;
                gotoxy( 28,24 );
                cout << "nuevo juego " << endl;
                system("CLS");
            }

            if( key == NEW )
            {   
                //system("CLS");
                maze();
                border();
                arrowsMovement();
                system( "CLS" );
            }

            if( key == EXIT )
                isfinish = true;

            Sleep( 5 );
        }
    }

    return 0;
}


void generateMap( ){

    intro();
    system("CLS");
    ocultarCursor();

    gotoxy( 30, 1 );
    cout << "MAZMORRA";

    gotoxy( 65, 4 );
    cout << "Herz: ";
    cout << (char) 4;

    gotoxy( 65, 5 );
    cout << "Enemigo: ";
    cout << (char) 146;

    gotoxy( 65, 6 );
    cout << "Jefe: ";
    cout << (char) 21;

    gotoxy( 65, 29 );
    cout << "Presiona N para cargar mapa nuevo" << endl;
    gotoxy( 65, 30 );
    cout << "Presiona Escape para salir" << endl;

    border();
    maze();
    arrowsMovement();
    
    return;
}


int main()
{
    generateMap();

    return 0;
}