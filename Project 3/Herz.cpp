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


void Herz::usePotion( Potion * potion, int posInventory, Herz * herz , Character * enemy )
{
    potion->potionEffect(  herz, enemy );
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