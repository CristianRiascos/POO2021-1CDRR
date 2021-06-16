#ifndef HERZ_H
#define HERZ_H

#include <iostream>
#include <string>

#include "Item.hpp"
#include "Potion.hpp"
#include "Character.hpp"
#include "Enemy.hpp"

using namespace std;

class Herz : public Character 
{
    private:
        int hpMax = hp;     // Vida que será incrementada con poción
        class Item inventory[ 10 ];     // Inventario de Herz
        int contInventory = 0;      // Sirve para saber cuantas posiciones del inventario de Herz están llenas

    public:
        Herz();
        Herz( int, int );   // Parámetros que recibe: vidaMax, daño
        ~Herz();
        
        void pickItem( Item );    // Levantar item del suelo
        void usePotion( class Potion *, int, Herz *, Character * );     // Parámetros strin para un código y numero de posicion de dicho item en el inventario
        void increaseHpMax( );  // Cuando Herz esté en combate, aumenta sus puntos de vida máxima y normal
        bool checkInventory( );   // Revisa el inventario para saber si está o no, lleno
        int getHpMax( );
        void reduceStats();     // Para cuando use ultimate, si la balanza no está a su favor, pierde vida
        void heal( int );    // Al usar pociones, sirve para curarse 
        void dmgIncrease( int );     // Al usar pociones, sirve para aumentar daño 
};

#endif