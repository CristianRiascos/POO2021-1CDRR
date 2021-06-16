#include "InstantDmgPotion.hpp"

<<<<<<< HEAD
void InstantDmgPotion::potionEffect( Herz * herz, Character *  character )
{
    // Inflige el 80% del daño de Herz como daño instantaneo al enemigo
    character->reduceHealt( ( herz->getDmg() * 80 ) / 100 );
}
=======

InstantDmgPotion::InstantDmgPotion( int endurance)
{
    this->endurance = endurance;
}

>>>>>>> dd93c1afa9a3d9414c520b274104dbc1dff15c8b
