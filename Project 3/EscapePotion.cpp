#include "EscapePotion.hpp"

<<<<<<< HEAD
=======
EscapePotion::EscapePotion(  int endurance )
{
    this->endurance = endurance;
}

/*
>>>>>>> dd93c1afa9a3d9414c520b274104dbc1dff15c8b
bool EscapePotion::canEscape()
{
    srand( time ( NULL ) );
    
    // Si el número es 0, la poción toma el valor de false y falla
    if( rand()%2 == 0 )
    {   
        // Si es 0, falla
        return false;
    }
    else
    {
        // Si es 1, funciona
        return true;;  
    }
}

// Método con un 50% de probabilidad de que la pocion funcione o falle
void EscapePotion::potionEffect( Herz * herz, Character * character )
{
    if( canEscape() == false )
        herz->reduceHealt( ( herz->getHpMax() * 10 ) / 100 );
}
*/