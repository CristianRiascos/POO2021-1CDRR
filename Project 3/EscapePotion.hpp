#ifndef ESCAPEPOTION_H
#define ESCAPEPOTION_H

#include <time.h>
#include <stdlib.h>
#include "Potion.hpp"

class EscapePotion : public Potion
{
    protected:
        string code = "572364";     // Código hexadecimal morado
    public:
        EscapePotion() = default;
        EscapePotion( int );  //  Int: resistencia
        ~EscapePotion() {};
        
        bool canEscape( );   // Determina si la función falla o no
};

#endif