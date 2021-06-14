#ifndef HERZ_H
#define HERZ_H

#include <iostream>
#include <string>

#include "Item.hpp"
#include "Potion.hpp"
#include "HealthPotion.hpp"
#include "PowerPotion.hpp"
#include "EscapePotion.hpp"
#include "InstantDmgPotion.hpp"
#include "Character.hpp"

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
        void useItem( string, int );     // Parámetros strin para un código y numero de posicion de dicho item en el inventario
        void increaseHp( );  // Cuando Herz esté en combate, aumenta sus puntos de vida
        int checkInventory( );   // Revisa el inventario para saber si está o no, lleno
        int getHpMax( );

};

#endif