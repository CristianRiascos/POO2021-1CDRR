#include "Herz.hpp"

Herz::Herz( int hp, int dmg )
{
    this->hp = hp;
    this->dmg = dmg;
    hpMax = hp;

}

Herz::~Herz()
{
}

void Herz::pickItem( Item item)
{
    if( contInventory == 10 )
    {
        std::cout << "\nEl inventario esta lleno";
    }
    else
    {
        inventory[ contInventory ] = item;
        contInventory++;
    }
    return;
}
 
// Herz ganará 5 puntos de vida máxima por cada pelea que gane
void Herz::increaseHpMax(  )
{
    hpMax += 5;
    return;
}


int Herz::getHpMax()
{
    return hpMax;
}


void Herz::useItem( int posInventory, Character * enemy )
{   
    // Revisa el código del item ingresado para revisar qué hacer dependiendo de qué objeto sea
    switch( inventory[ posInventory ].getCode() )
    {
        /* 
            Si la vida del jugador sumada la poción es mayor a la vida máxima, herz recuperará la diferencia
            entre la vida que tenga y la vida máxima. Si el jugador tiene los puntos de vida máximos y usa la 
            poción, no se le sumará ningún punto de vida y perderá la poción.

            Si la vida del jugador sumada la poción es menor a la vida máxima, suma 100 puntos de vida
        */
        case HEALTH:
            if( ( hp + 100 ) >= hpMax )
                heal( hp - hpMax );
            else
                heal( 100 );

        case POWER:
            dmgIncrease( 15 );  // Incrementa 15 puntos de daño al usar poción de poder
        
        case INSTANT_DMG:
            enemy->reduceHealt( ( dmg * 80 ) / 100 );   // Inflige el 80% del daño de Herz como daño instantaneo al enemigo
        
        
    }

    
    return;     
}


// Si la balanza no está a favor, pierde 3 puntos de vida, tanto máximos como vida actual de Herz
void Herz::reduceStats( )
{
    hp -= 3;
    hpMax = -3;
    return;
}

// Al usar la poción de vida, incrementa la vida
void Herz::heal( int hpHeal )
{
    hp += hpHeal;
    return;
}

// Al usar la poción de poder, incrementa el daño
void Herz::dmgIncrease( int dmgIncrement )
{
    dmg += dmgIncrement;
    return;
}