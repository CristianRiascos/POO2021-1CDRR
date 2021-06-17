#ifndef CHARACTER_H
#define CHARACTER_H

#include "AttackType.hpp"
#include "Item.hpp"

class Character
{
    protected:
        int hp; // Health
        int dmg;    // Damage

    public:
        Character() {};
        ~Character() {};

        int getHp();
        int getDmg();

        /*
            Parámetros:
            Weapon *: Arma que usa
            Character *: Personaje atacado
            AttackType *: Tipo de ataque usado
        */

        void attack(  Item *, Character *, class AttackType *  );   
        void reduceHealt( int );        // Al usar pociones, cuando el enemigo reciba daño

};

#endif