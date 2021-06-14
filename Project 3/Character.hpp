#ifndef CHARACTER_H
#define CHARACTER_H

#include "Weapon.hpp"
#include "AttackType.hpp"

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

        void attack(  Weapon *, Character *, AttackType *  );  

};

#endif