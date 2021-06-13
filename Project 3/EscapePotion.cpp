#include "EscapePotion.hpp"

EscapePotion::EscapePotion(  int endurance )
{
    this->endurance = endurance;
}

// Método con un 50% de probabilidad de que la pocion funcione o falle
bool EscapePotion::canEscape()
{
    srand( time ( NULL ) );
    
    // Si el número es 0, la poción toma el valor de false y falla
    if( rand()%2 == 0 )
    {
        return false;
    }
    else
    {
        return true;    // Si es true, la poción funciona
    }
}