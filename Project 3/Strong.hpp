#ifndef STRONG_H
#define STRONG_H

#include "AttackType.hpp"

class Strong : public AttackType
{
    public:
        Strong();
        ~Strong( ) {}; 

        int getDmg( int );      // Sobreescritura
};

#endif