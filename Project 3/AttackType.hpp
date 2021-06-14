#ifndef ATTACKTYPE_H
#define ATTACKTYPE_H

#include "Character.hpp"

class AttackType
{
    protected:
        int dmg;    // Daño base del ataque

    public:
        AttackType();
        ~AttackType() {};

        int getDmg( );  
};

#endif 