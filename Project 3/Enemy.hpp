#ifndef enemy_H
#define enemy_H

#include "Character.hpp"

class Enemy : public Character
{
    public:
    Enemy( ) {};
    Enemy( int, int );
    ~Enemy();
};

#endif