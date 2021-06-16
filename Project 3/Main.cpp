#include <iostream>
#include <algorithm>    // Librería usada par ciertos usos de std
#include <windows.h>    // Librería usada para el mapa e interacción con teclado
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <type_traits>

#include "Character.hpp"
#include "Boss.hpp"
#include "Enemy.hpp"
#include "Herz.hpp"

#include "Item.hpp"
#include "Potion.hpp"
#include "HealthPotion.hpp"
#include "PowerPotion.hpp"
#include "InstantDmgPotion.hpp"
#include "EscapePotion.hpp"

#include "Weapon.hpp"
#include "Bow.hpp"
#include "Scimitar.hpp"
#include "Greatsword.hpp"

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
#define ULTIMATE_ATTACK 108        // Tecla asignada: l

using namespace::std;

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
    
    // Entra en bucle hasta que toque una tecla válida (N o C)
    while ( KEY != NEW || KEY != PICK )
    {
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

Item generarObjeto(){
    Item objeto;
    int random = rand()%7; // Randomiza entre 0 a 6
    int dmg = 10+rand()%21; // Randomiza el dano entre 10 y 30
    int hpheal = 1+rand()%51; // Randomiza la curacion entre 1 y 50

    if( random == 0 ){
        objeto = Bow (dmg);
    }
    else if( random == 1 ){
        objeto = Scimitar (dmg);
    }
    else if( random == 2 ){
        objeto = Greatsword (dmg);
    }
    else if( random ==3 ){
        objeto = HealthPotion(hpheal);
    }
    else if( random ==4 ){
        objeto = PowerPotion();
    }
    else if( random == 5 ){
        objeto = InstantDmgPotion();
    }
    else if( random == 6 ){
        objeto = EscapePotion();
    }
    return objeto;
}

// Crea y organiza el laberinto
void maze( int eleccion )
{  
    system( "CLS" );
    // Creación de tablero
    int bossElection;   // Será para determinar cuál boss se pone

    int contThree = 60;  // Contador para limitar el 3
    int contFour = 250;     // Contador para limitar el 4
    int contFive = 120;

    //  Cada ejecución de maze hace que el contador de enemigos, jefes y pociones sea 1
    int contEnemy = 1;
    int contBoss = 1;
    int contPotion = 1;

    Herz herz( 100, 25 );
    Potion potion( 1 );
    Enemy enemy( 70, 25 );
    Boss boss( 300, 50 );
    Boss bossOmega( &herz );

    srand( time( NULL) );

    // Genera el mapa pequeño al ser opción fácil
    if( eleccion == 2 )
    {
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
                        if( rand()%2 == 0 )
                        {
                            map3[i][j] = boss;
                        }
                        else
                        {
                            map3[i][j] = bossOmega;
                        }
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
                        map2[i][j] = generarObjeto();    // Genera un objeto aleatorio entre los ya disenados
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

    // Mapa grande si elige opción dificil
    else
    {
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
                    if( contBoss <= 3 && contFour >= 225 )        
                    {
                        if( rand()%2 == 0 )
                        {
                            map3[i][j] = boss;
                        }
                        else
                        {
                            map3[i][j] = bossOmega;
                        }

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
                        map2[i][j] = generarObjeto();    // Genera un objeto aleatorio entre los ya disenados
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


// Determina la pelea y el ganador
int fight( Herz * herz, Character * enemy )
{
    char jugador = true;    // Para el sistema de turnos
    char key = getch();     // Para tomar cual ataque desea hacer el usuario
    int attackEnemy;    // Para saber qué ataque usará el enemigo
    int ultimateHerz;   // Determina si hay penalidad por usar el ataque
    bool itWorked = false;      // Almacenará el valor arrojado de la poción de escape, si es true, signfica que funcionpo y sale de la pelea

    Weak * weak;
    Strong * strong;
    Ultimate * ultimate;


    srand( time( NULL ) );

    /*
        Condiciones para terminar pelea:
        1. Herz muere
        2. Herz mata al enemigo
        3. La poción de escape funciona
    */
    while( herz->getHp() > 0 || enemy->getHp() > 0 || itWorked == true )
    {
        // Estadisticas de Herz
        gotoxy( 133, 14 );
        cout << "Stats Herz";
        gotoxy( 130, 16 );
        cout << "Vida maxima: " << herz->getHpMax();
        gotoxy( 130, 17 );
        cout << "Vida: " << herz->getHp();
        gotoxy( 130, 18 );
        cout << "Damage: "<< herz->getDmg();

        // Estadísticas del enemigo
        gotoxy( 172, 14 );
        cout << "Stats Enemigo";
        gotoxy( 170, 17 );
        cout << "Vida: " << enemy->getHp();
        gotoxy( 170, 18 );
        cout << "Damage: "<< enemy->getDmg();


        // Si jugador es true, es el turno del jugador
        if( jugador == true )
        {
            if( kbhit() )
            {
                if( key == WEAK_ATTACK )
                {
                    //  herz->attack( , enemy, weak );
                }

                else if( key == STRONG_ATTACK )
                {
                //herz->attack( , enemy, strong );
                }

                // Tiene un 50% de probabilidades de reducir la vida de Herz si usa ultimate
                else if( key == ULTIMATE_ATTACK )
                {
                    ultimateHerz = rand() % 2;
                    if( ultimateHerz == 0 )
                    {
                        // herz->attack( , enemy, ultimate );
                    }
                    else
                    {
                        //herz->attack( , enemy, ultimate );
                        herz->reduceStats();    
                    }
                }

                // Asigna numeros de 1 a 0 para usar items del inventario
                switch( key )
                {
                    case ONE:
                        herz->useItem( 1, enemy );
                        break;
                    case TWO:
                        herz->useItem( 2, enemy );
                        break;
                    case THREE:
                        herz->useItem( 3, enemy );
                        break;
                    case FOUR:
                        herz->useItem( 4, enemy );
                        break;
                    case FIVE:
                        herz->useItem( 5, enemy );
                        break;
                    case SIX:
                        herz->useItem( 6, enemy );
                        break;
                    case SEVEN:
                        herz->useItem( 7, enemy );
                        break;
                    case EIGHT:
                        herz->useItem( 8, enemy );
                        break;
                    case NINE:
                        herz->useItem( 9, enemy );
                        break;
                    case ZERO:
                        herz->useItem( 0, enemy );
                        break;
                    default: 
                        continue;
                    jugador = false;
                }
                // if( std::is_same<decltype(), EscapePotion>::value == 1 )

            }

        jugador = false;    // Después cambia el valor de bool a false 

        }

        // Si es false, entra a bucle para que la máquina ataque
        else
        {
            attackEnemy == rand() % 6;

            Sleep( 20 );

            // Si sale 1,2 o 3 , hará el ataque débil
            if( attackEnemy == 1 || attackEnemy == 2 || attackEnemy == 3 )
            {
                // enemy->attack( , herz, weak );
            }

            // Si sale 4 o 5, hará el ataque fuerte
            else if( attackEnemy == 4 || attackEnemy == 5 )
            {
                // enemy->attack( , herz, strong );
            }

            else
            {
                // enemy->attack( , herz, ultimate );
            }

            jugador = true;
        }


        // Devuelve 1 si Herz muere o 0 si Herz mata al enemigo
        if( herz->getHp() == 0 )
        {
            return 1;
        }
        else if( enemy->getHp() == 0 )
        {
            return 0;
        }
    }
}

// Mensaje de que el usuario ha perdido la partida
void youLost( )
{
    system( "CLS" );
    gotoxy( 42, 15 );
    cout << "Lo sentimos, has perdido!!" << endl;
    gotoxy( 28, 16 );
    cout << "Has muerto intentando salvar tu reino" << endl;

    gotoxy( 28, 20 );
    cout << "Presiona Escape para salir" << endl;

    gotoxy( 28, 23 );
    cout << "Presiona N para un nuevo juego" << endl;
}


int arrowsMovement( int eleccion )
{
    bool isfinish = false;     // Bandera de fin de mapa 
    int x = 9, y = 4;   // Coordenadas de inicio del jugador
    gotoxy( x, y );
    cout << (char) 4;   // "Diseño" del jugador
    int contBoss;   // Contador de bosses para determinar si la persona gana

    if( eleccion == 1 )
    {
        // Valor de bosses cuando se elige la opción fácil
        contBoss =  2;
    }
    else
    {
        // Opción difícil contiene 5 bosses
        contBoss = 5;
    }

    Herz herz( 100, 25 );

    ocultarCursor();

    while( !( isfinish ) )
    {
        if( kbhit() )
        {
            char key = getch();
            gotoxy( x, y );
            cout << " ";

            // Si entra a este bucle, el jugador ha ganado
            if( contBoss == 0 )
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
                if( map[ x-1 ][y] == 3 || map[ x+1 ][y] == 3 || map[x][ y-1 ] == 3 || map[x][ y+1 ] == 3 ||
                    map[ x-1 ][y] == 4 || map[ x+1 ][y] == 4 || map[x][ y-1 ] == 4 || map[x][ y+1 ] == 4 )
                {
                    
                    // Revisa cada posición aledaña a Herz para saber dónde está el enemigo
                    if( /*map[ x-1 ][y] == 3 ||*/ map[ x-1 ][y] == 4 )
                    {
                        // Entra aquí si Herz ha salido victorioso
                        if( fight( &herz, &map3[x-1][y] ) == 0 )
                        {
                            // Mira si la posición pertenecía a un jefe y resta 1 al contador
                            if( map[ x-1 ][y] == 4 )
                                contBoss--;

                            gotoxy( x-1, y );
                            cout << (char) 32;  // Asigna el valor de espacio al punto donde esté el enemigo
                            map[ x-1][y] = 1;  // Asigna el número 1 al espacio para que Herz pueda moverse en esa zona
                            map3[ x-1 ][y].~Character();   // Destruye el objeto 
                            herz.increaseHpMaxDmg();
                        }

                        // Entra aquí si Herz ha perdido 
                        else
                        {
                            youLost();
                        }
                    }

                    else if( map[ x+1 ][y] == 3 || map[ x+1 ][y] == 4)
                    {
                        // Entra aquí si Herz ha salido victorioso
                        if( fight( &herz, &map3[x+1][y] ) == 0 )
                        {
                            // Mira si la posición pertenecía a un jefe y resta 1 al contador
                            if( map[ x+1 ][y] == 4 )
                                contBoss--;

                            gotoxy( x+1, y );
                            cout << (char) 32;  // Asigna el valor de espacio al punto donde esté el enemigo
                            map[ x+1 ][y] = 2;  // Asigna el número 1 al espacio para que Herz pueda moverse en esa zona
                            map3[ x+1 ][y].~Character();   // Destruye el objeto 
                            herz.increaseHpMaxDmg();
                            
                        }

                        // Entra aquí si Herz ha perdido 
                        else
                        {
                            youLost();
                        }
                    }

                    else if( map[x][ y-1 ] == 3 || map[x][ y-1 ] == 4 )
                    {
                        // Entra aquí si Herz ha salido victorioso
                        if( fight( &herz, &map3[x][ y-1 ] ) == 0 )
                        {
                            // Mira si la posición pertenecía a un jefe y resta 1 al contador
                            if( map[x][ y-1 ] == 4 )
                                contBoss--;

                            gotoxy( x, y-1 );
                            cout << (char) 32;  // Asigna el valor de espacio al punto donde esté el enemigo
                            map[x][ y-1 ] = 1;  // Asigna el número 1 al espacio para que Herz pueda moverse en esa zona
                            map3[x][ y-1 ].~Character();   // Destruye el objeto 
                            herz.increaseHpMaxDmg();

                        }

                        // Entra aquí si Herz ha perdido 
                        else
                        {
                            youLost();
                        }
                    }

                    else
                    {
                        // Entra aquí si Herz ha salido victorioso
                        if( fight( &herz, &map3[x][ y+1 ] ) == 0 )
                        {
                            // Mira si la posición pertenecía a un jefe y resta 1 al contador
                            if( map[x][ y+1 ] == 4 )
                                contBoss--;

                            gotoxy( x, y+1 );
                            cout << (char) 32;  // Asigna el valor de espacio al punto donde esté el enemigo
                            map[x][ y+1 ] = 1;  // Asigna el número 1 al espacio para que Herz pueda moverse en esa zona
                            map3[x][ y+1 ].~Character();   // Destruye el objeto 
                            herz.increaseHpMaxDmg();
                        }

                        // Entra aquí si Herz ha perdido 
                        else
                        {
                            youLost();
                        }
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