#ifndef BOSS_H
#define BOSS_H

#include "Character.hpp"
#include "Herz.hpp"

class Boss : public Character
{        
    public:
        Boss() = default;
        Boss( int, int );   // Recibe vida y daño respectivamente
        Boss( Herz * );  // Sobrecarga hecha
        ~Boss() {};
};

#endif