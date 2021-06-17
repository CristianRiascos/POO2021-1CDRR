#ifndef WEAPON_H
#define WEAPON_H

#include "Item.hpp"

class  Weapon : public Item
{
    protected:
    public:
        Weapon() = default;
        Weapon( int );     // Parametros que recibe: daño, resistencia
        ~Weapon() {};
        
        void attack();
};

#endif