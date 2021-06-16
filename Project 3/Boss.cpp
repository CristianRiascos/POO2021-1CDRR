#include "Boss.hpp"

Boss::Boss( int hp, int dmg  )
{
    this->hp = hp;
    this->dmg = dmg;
}

// Un boss especial que se basa en la vida y daño inicial de Herz + el 70% de sí mismo
Boss::Boss( Herz * herz  )
{
    this->hp = herz->getHpMax() + ( ( herz->getHpMax() * 80) / 100 ) ;
    this->dmg = herz->getDmg() + ( ( herz->getDmg() * 80 ) / 100 );
}
