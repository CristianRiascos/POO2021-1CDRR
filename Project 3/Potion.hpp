#ifndef POTION_H
#define POTION_H

#include "Item.hpp"
#include "Character.hpp"
#include "Herz.hpp"

using namespace std;

class Potion : public Item
{
    public:
        Potion() {};
        Potion( int );
        ~Potion() {};

        /*
            Parámetros:
            Herz *: Puntero a Herz
            Character *: Puntero al enemigo de Herz
        */
        void potionEffect( class Herz *, class Character * );   // Sobreescritura en hijas
        void printInfoPotion( );    // Sobreescritura en hijas
        string getCode();
};

#endif