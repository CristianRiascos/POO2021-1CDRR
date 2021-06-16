#ifndef ESCAPEPOTION_H
#define ESCAPEPOTION_H

#include <time.h>
#include <stdlib.h>
#include "Potion.hpp"

class EscapePotion : public Potion
{
    protected:
        identify code = ESCAPE;
    public:
        EscapePotion() = default;
        EscapePotion( int );  //  Int: resistencia
        ~EscapePotion() {};
        
        bool canEscape( );   // Determina si la función falla o no
        void potionEffect( class Herz *, class Character * ); 
};

#endif