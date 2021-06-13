#ifndef HERZ_H
#define HERZ_H

#include <iostream>

#include "Item.hpp"
#include "Character.hpp"

using namespace std;

class Herz : public Character 
{
    protected:
        class Item inventory[ 10 ];     // Inventario de Herz
        int contInventory = 0;

    public:
        Herz();
        Herz( int, int );   // Parámetros que recibe: vida, daño
        ~Herz();
        
        void pickItem( Item );    // Levantar item del suelo
        void useItem( Item );     // Usar item 
        void increaseHp( Herz );  // Cuando Herz esté en combate, aumenta sus puntos de vida

};

#endif