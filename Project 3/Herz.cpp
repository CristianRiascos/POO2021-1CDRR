#include "Herz.hpp"

Herz::Herz( int hp, int dmg )
{
    this->hp = hp;
    this->dmg = dmg;

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
}

void Herz::increaseHp( Herz herz)
{
    herz.hp++;
}

