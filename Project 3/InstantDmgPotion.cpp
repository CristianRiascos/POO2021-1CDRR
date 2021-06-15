#include "InstantDmgPotion.hpp"


InstantDmgPotion::InstantDmgPotion( int endurance)
{
    this->endurance = endurance;
}

void InstantDmgPotion::potionEffect( Herz * herz, Character *  character )
{
    // Inflige el 80% del daño de Herz como daño instantaneo al enemigo
    character->reduceHealt( ( herz->getDmg() * 80 ) / 100 );
}