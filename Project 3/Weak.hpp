#ifndef WEAK_H
#define WEAK_H

#include "AttackType.hpp"

class Weak : public AttackType
{
    public:
        Weak() = default;    
        ~Weak( ) {}; 

        int getDmg( int );  // Sobreescritura
};

#endif