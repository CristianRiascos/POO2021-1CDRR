#include "Character.hpp"


int Character::getDmg()
{
    return dmg;
}


int Character::getHp()
{
    return hp;
}


void Character::attack( Weapon * weapon, Character * attacked, AttackType * attackType )
{
    int dmgDone;
    
    // El daño que realiza es igual a la suma del daño del arma más el daño de attackType
    dmgDone = weapon->getDmg() + attackType->getDmg();
    attacked->hp -= dmgDone; // Se le resta dmgDone a la vida del atacado
}

void Character::reduceHealt( int dmgReceived )
{
    hp -= dmgReceived; 
}