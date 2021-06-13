#ifndef WEAPON_H
#define WEAPON_H

#include "Item.hpp"

class  Weapon : public Item
{
    protected:
        int dmg;
    public:
        Weapon( int, int );     // Parametros que recibe: daño, resistencia
        ~Weapon();
        
};

#endif