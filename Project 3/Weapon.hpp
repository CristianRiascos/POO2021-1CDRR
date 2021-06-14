#ifndef WEAPON_H
#define WEAPON_H

#include "Item.hpp"

class  Weapon : public Item
{
    protected:
        int dmg;
    public:
        Weapon() = default;
        Weapon( int, int );     // Parametros que recibe: daño, resistencia
        ~Weapon();
        
        int getDmg();
        virtual void attack() = 0;
};

#endif