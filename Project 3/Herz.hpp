#ifndef HERZ_H
#define HERZ_H

#include <iostream>
#include <string>

#include "Item.hpp"
#include "Character.hpp"
#include "Enemy.hpp"

using namespace std;

class Herz : public Character 
{
    private:
        int hpMax = hp;     // Vida que será incrementada con poción
        int contInventory = 1;      // Sirve para saber cuantas posiciones del inventario de Herz están llenas

    public:
        class Item inventory[ 10 ];     // Inventario de Herz
        Herz();
        Herz( int, int );   // Parámetros que recibe: vidaMax, daño
        ~Herz();
        
        void pickItem( Item );    // Levantar item del suelo
        void useItem( int, Character * );     // Int para posición item y character * en caso de que se use la poción de daño instantáneo
        void increaseHpMaxDmg( );  // Cuando Herz gane un combate, aumenta sus puntos de vida máxima, normal y el daño
        bool checkInventory( );   // Revisa el inventario para saber si está o no, lleno
        int getHpMax( );    // Devuelve la vida máxima
        void heal( int );    // Al usar pociones, sirve para curarse 
        void dmgIncrease( int );     // Al usar pociones, sirve para aumentar daño 
        Item equipWeapon();
};

#endif