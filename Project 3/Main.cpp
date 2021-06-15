#include <iostream>
#include <algorithm>    // Librería usada par ciertos usos de std
#include <windows.h>    // Librería usada para el mapa e interacción con teclado
#include <time.h>
#include <cstdlib>
#include <conio.h>

#include "Character.hpp"
#include "Boss.hpp"
#include "Enemy.hpp"
#include "Herz.hpp"

#include "Item.hpp"
#include "Potion.hpp"
#include "HealthPotion.hpp"
#include "PowerPotion.hpp"

#include "Weapon.hpp"

// Librerías para los ataques
#include "Weak.hpp"
#include "Strong.hpp"
#include "Ultimate.hpp"

// Flechas para mover a HERZ
#define UP 119
#define LEFT 97
#define RIGHT 100
#define DOWN 115
#define EXIT 27     // Tecla asignada: escape    
#define NEW 110     // Tecla asignada: n
#define PICK 99     // Tecla asignada: c
#define ATTACK 122  // Tecla asignada: z
#define ONE 49      // Tecla asignada: 1
#define TWO 50      // Tecla asignada: 2
#define THREE 51      // Tecla asignada: 3
#define FOUR 52      // Tecla asignada: 4
#define FIVE 53      // Tecla asignada: 5
#define SIX 54      // Tecla asignada: 6
#define SEVEN 55      // Tecla asignada: 7
#define EIGHT 56      // Tecla asignada: 8
#define NINE 57      // Tecla asignada: 9
#define ZERO 48    // Tecla asignada: 0

#define WEAK_ATTACK 106     // Tecla asignada: j
#define STRONG_ATTACK 107   // Tecla asignada: k

using namespace::std;

bool turnoJugador = false;     // Para el manejo de turnos
int map[ 100 ][ 50 ];       // Mapa para generar la parte "gráfica"
Item map2[ 100 ][ 50 ];     // Mapa para generar espacios con los items 
Character map3[ 100 ][ 50 ];    // Mapa para generar enemigos/bosses

void gotoxy( int x, int y );


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

// Pantalla de inicio
int intro()
{
    int dificultad;
    char KEY;
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
    cout << "             _______________________________________________________ " << endl;
    cout << "            *                                                       *" << endl;
    cout << "            |           Seleccione dificultad:                      |" << endl;
    cout << "            |       N. Facil              C. Dificil                |" << endl;
    cout << "            |                                                       |" << endl;
    cout << "            *_______________________________________________________*" << endl;
    KEY = getch();
    if( kbhit ){
        if( KEY == NEW ){
            system( "CLS" );
            return 1;
        }
        else if ( KEY == PICK ){
            system( "CLS" );
            return 2;
        }
    }
    return 0;
}


// Define y marca el croquis del mapa
void border( int eleccion )
{
    if ( eleccion == 2 ){
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
        cout << (char) 187;     // Diagonal inferior izquierda
        gotoxy( 8, 31 );
        cout << (char) 200;     // Digonal inferior derecha
        gotoxy( 61, 31 );
        cout << (char) 188;     // Diagonal superior derecha

        return;
    }
    else{
        // Parte horizontal
        for( int i = 9; i < 50; i++ )
        {
            gotoxy( i, 3 );
            cout << (char) 205;
            gotoxy( i, 25 );
            cout << (char) 205;
        }

        // Pared vertical
        for( int j = 4; j < 25; j++ )
        {
            gotoxy( 8, j );
            cout << (char) 186;
            gotoxy( 50, j );
            cout << (char) 186;
        }

        gotoxy( 8, 3 );
        cout << (char) 201;     // Diagonal superior izquierda
        gotoxy( 50, 3 );
        cout << (char) 187;     // Diagonal superior derecha
        gotoxy( 8, 25 );
        cout << (char) 200;     // Digonal inferior derecha
        gotoxy( 50, 25 );
        cout << (char) 188;     // Diagonal superior derecha
    }
}

int getContBoss( int contBoss )
{
    return contBoss;
}

// Crea y organiza el laberinto
void maze( int eleccion )
{  
    system( "CLS" );
    // Creación de tablero
    int contThree = 60;  // Contador para limitar el 3
    int contFour = 250;     // Contador para limitar el 4
    int contFive = 120;

    //  Cada ejecución de maze hace que el contador de enemigos, jefes y pociones sea 1
    int contEnemy = 1;
    int contBoss = 1;
    int contPotion = 1;
    Potion potion( 1 );
    Enemy enemy( 70, 25 );
    srand( time( NULL) );
    if( eleccion == 2 ){
        // Creacion del mapa usando aleatoriedad
        for( int i = 9; i < 61; i++ )
        {
            for( int j = 4; j < 31; j++ )
            {
                map[i][j] = rand() % 6;     // Genera número aleatorio de 0 a 5

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
                    
                    // Cada 50 tiros, se pone un enemigo
                    if( contEnemy <= 25 && contThree >= 50 )        
                    {
                        map[i][j] = 3;  // Si entra al bucle, vuelve a cambiar el valor a 3
                        map3[i][j] = enemy;
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
                    // Cada 225 tiros, se pone un enemigo
                    if( contBoss <= 5 && contFour >= 225 )        
                    {
                        map[i][j] = 4;  // Si entra al bucle, vuelve a cambiar el valor a 4
                        contFour = 0;   // Resetea contador
                        contBoss++;
                        gotoxy( i, j );
                        cout << (char) 21;
                    }
                }
                
                // Si es 5, coloca un item
                else if( map[i][j] == 5  )    
                {
                    map[i][j] = 1;     // Cambia el valor de la posicion a 2 para que se pueda mover
                    
                    // Cada 50 veces que map[i][j] sea 3, se pone un item
                    if( contPotion <= 4 && contFive >= 250 )        
                    {
                        map[i][j] = 5;  // Si entra al bucle, vuelve a cambiar el valor a 5
                        contFive = 0;   // Resetea contador
                        contPotion++;
                        gotoxy( i,j );
                        map2[i][j] = potion;    // PRUEBA, DEBE DE CAMBIAR CUANDO ESTÉ LA PELEA
                        gotoxy( i, j );
                        cout << (char) 63;
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


        border( eleccion );
    }
    else{
        // Creacion del mapa usando aleatoriedad
        for( int i = 9; i < 50; i++ )
        {
            for( int j = 4; j < 25; j++ )
            {
                map[i][j] = rand() % 6;     // Genera número aleatorio de 0 a 5

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
                    
                    // Cada 50 tiros, se pone un enemigo
                    if( contEnemy <= 25 && contThree >= 50 )        
                    {
                        map[i][j] = 3;  // Si entra al bucle, vuelve a cambiar el valor a 3
                        map3[i][j] = enemy;
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
                    // Cada 225 tiros, se pone un enemigo
                    if( contBoss <= 2 && contFour >= 225 )        
                    {
                        map[i][j] = 4;  // Si entra al bucle, vuelve a cambiar el valor a 4
                        contFour = 0;   // Resetea contador
                        contBoss++;
                        gotoxy( i, j );
                        cout << (char) 21;
                    }
                }
                
                // Si es 5, coloca un item
                else if( map[i][j] == 5  )    
                {
                    map[i][j] = 1;     // Cambia el valor de la posicion a 2 para que se pueda mover
                    
                    // Cada 50 veces que map[i][j] sea 3, se pone un item
                    if( contPotion <= 4 && contFive >= 250 )        
                    {
                        map[i][j] = 5;  // Si entra al bucle, vuelve a cambiar el valor a 5
                        contFive = 0;   // Resetea contador
                        contPotion++;
                        gotoxy( i,j );
                        map2[i][j] = potion;    // PRUEBA, DEBE DE CAMBIAR CUANDO ESTÉ LA PELEA
                        gotoxy( i, j );
                        cout << (char) 63;
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


        border( eleccion );
    }

    gotoxy( 130, 3 );
    cout << " _______________________________________________________ " << endl;
    gotoxy( 130, 4 );
    cout << "*                                                       *" << endl;
    gotoxy( 130, 5 );
    cout << "|                                                       |" << endl;
    gotoxy( 130, 6 );
    cout << "|                    ESCENA DE PELEA                    |" << endl;
    gotoxy( 130, 7 );
    cout << "|                                                       |" << endl;
    gotoxy( 130, 8 );
    cout << "*_______________________________________________________*" << endl;

    gotoxy( 130, 15 );
    cout << "Vida Herz: ";

    gotoxy( 170, 15 );
    cout << "Vida Enemigo: ";


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

    gotoxy( 65, 7 );
    cout << "Pocion: ";
    cout << (char) 63;

    gotoxy( 65, 29 );
    cout << "Presiona N para cargar mapa nuevo" << endl;
    gotoxy( 65, 30 );
    cout << "Presiona Escape para salir" << endl;

    gotoxy( 28, 33 );
    cout << "Inventario" << endl; 
    gotoxy( 8, 35 );
    cout << "1. " << endl; 
    gotoxy( 8, 36 );
    cout << "2. " << endl; 
    gotoxy( 8, 37 );
    cout << "3. " << endl; 
    gotoxy( 8, 38 );
    cout << "4. " << endl; 
    gotoxy( 8, 39 );
    cout << "5. " << endl; 
    gotoxy( 8, 40 );
    cout << "6. " << endl; 
    gotoxy( 8, 41 );
    cout << "7.  " << endl; 
    gotoxy( 8, 42 );
    cout << "8.  " << endl; 
    gotoxy( 8, 43 );
    cout << "9. " << endl; 
    gotoxy( 8, 44 );
    cout << "0. " << endl; 

    return;
}


void winner( Character * enemy )
{
    // Entra aquí si el enemigo ha perdido sus puntos de vida
    if( enemy->getHp() == 0  )
    {
        enemy->~Character();    //Destruye el objeto enemigo
    }

    // Entra al else, si es Herz quien ha perdido
    else
    {

    }   

    return;
}


void fight( Herz * herz, Character * enemy )
{
    char jugador = turnoJugador ? 'X' : '0';
    char key = getch();

    Weak * weak;
    Strong * strong;

    if( key == WEAK_ATTACK )
    {
        //herz->attack( , enemy, weak );
    }

    else if( key == STRONG_ATTACK )
    {
        //herz->attack( , enemy, strong );
    }


    return;
}


int arrowsMovement( int eleccion )
{
    bool isfinish = false;     // Bandera de fin de mapa 
    int x = 9, y = 4;   // Coordenadas de inicio del jugador
    int bandera = 0;
    gotoxy( x, y );
    cout << (char) 4;   // "Diseño" del jugador

    Herz herz( 100, 25 );

    ocultarCursor();

    while( !( isfinish ) )
    {
        if( kbhit() )
        {
            char key = getch();
            gotoxy( x, y );
            cout << " ";
            
            if( bandera == 0 )
            {
                // Movimiento de acuerdo a las flechas que sean pulsadas por el jugador
                if( key == LEFT )
                    if( map[ x-1 ][y] == 1 || map[ x-1 ][y] == 2) x--;

                if( key == RIGHT )
                    if( map[ x+1 ][y] == 1 || map[ x+1 ][y] == 2) x++ ;

                if( key == UP )
                    if( map[x][ y-1 ] == 1 || map[x][ y-1 ] == 2) y--;

                if( key == DOWN )
                    if( map[x][ y+1 ] == 1 || map[x][ y+1 ] == 2 ) y++;

                gotoxy( x, y ); 
                cout << (char) 4;
            }


            // Si entra a este bucle, el jugador ha ganado
            if( ( x == 60 && y == 30 )||( x == 60 && y == 4 ) )
            {  
                // Indica que ha ganado y le permite elegir si desea jugar otra vez o salir
                system( "CLS" );
                gotoxy( 42, 15 );
                cout << "Felicitaciones!!" << endl;
                gotoxy( 28, 16 );
                cout << "Has obtenido la reliquia y terminado el juego" << endl;

                gotoxy( 28, 20 );
                cout << "Presiona Escape para salir" << endl;

                gotoxy( 28, 23 );
                cout << "Presiona N para un nuevo juego" << endl;
            }

            // Si el jugador toca la letra n crea un nuevo mapa
            if( key == NEW )
            {   
                //system("CLS");
                maze( eleccion );
                border( eleccion );
                arrowsMovement( eleccion );
                system( "CLS" );
                isfinish = true;
            }

            // Si el jugador toca la letra escape, termina la ejecución del programa
            if( key == EXIT )
                isfinish = true;

            // Si el jugador toca la letra c, toma un objeto del suelo
            if( key == PICK )
            {
                // Revisa la posición actual de Herz y revisa todos los lados anidados en busca de un item
                gotoxy( x, y);
                if( map[ x-1 ][y] == 5 || map[ x+1 ][y] == 5 || map[x][ y-1 ] == 5 || map[x][ y+1 ] == 5 )
                {
                    // Busca en cual está el objeto exactamente
                    if( map[ x-1 ][y] == 5 )
                    {
                        herz.pickItem( map2[x-1][y] );  // Añade el item al inventario de Herz
                        gotoxy( x-1, y );   // Ubica la posicion del item
                        cout << (char) 32;  // Borra el item y pone un " " en su lugar
                        map[x-1][y] = 1;    // Modifica su codigo a 1 para que Herz pueda pasar
                    }

                    // Mismo proceso realizado en los siguientes segmentos 
                    else if( map[ x+1 ][y] == 5 )
                    {
                        herz.pickItem( map2[x+1][y] );
                        gotoxy( x+1, y );
                        map[x+1][y] = 1;
                        cout << (char) 32;
                         
                    }

                    else if( map[x][ y-1 ] == 5 )
                    {
                        herz.pickItem( map2[x][ y-1 ] );
                        gotoxy( x, y-1 ); 
                        map[x][ y-1 ] = 1;
                        cout << (char) 32;
                    }

                    else
                    {
                        herz.pickItem( map2[x][ y+1 ] );
                        gotoxy( x, y+1 );
                        map[x][ y+1 ] = 1;
                        cout << (char) 32;
                    }
                }
            }

            if( key == ATTACK )
            {
                if( map[ x-1 ][y] == 3 || map[ x+1 ][y] == 3 || map[x][ y-1 ] == 3 || map[x][ y+1 ] == 3 )
                {
                    
                    // Revisa cada posición aledaña a Herz para saber dónde está el enemigo
                    if( map[ x-1 ][y] == 3 )
                    {
                        fight( &herz, &map3[x-1][y] );
                    }

                    else if( map[ x+1 ][y] == 3 )
                    {
                        fight (&herz, &map3[x+1][y]);
                    }

                    else if( map[x][ y-1 ] == 3 )
                    {
                        fight( &herz, &map3[x][ y-1 ]); 
                    }

                    else
                    {
                        fight( &herz, &map3[x][ y+1 ]);
                    }

                }
            }

            Sleep( 5 );
        }
    }

    return 0;
}


void generateMap( ){
    int eleccion;
    eleccion = intro();
    ocultarCursor();

    maze( eleccion );
    arrowsMovement( eleccion );
    system( "CLS" );
    
    return;
}


int main()
{
    generateMap();

    return 0;
}