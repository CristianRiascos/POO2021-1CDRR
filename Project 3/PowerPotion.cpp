#include "PowerPotion.hpp"

PowerPotion::PowerPotion( int endurance )
{
    this->endurance = endurance;
}

void PowerPotion::potionEffect( Herz * herz, Character * )
{
    // Incrementa 10 puntos de daño máximo
    herz->dmgIncrease( 15 );
}