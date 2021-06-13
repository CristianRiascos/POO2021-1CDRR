#ifndef ATTACKTYPE_H
#define ATTACKTYPEE_H

class AttackType
{
    protected:
        int dmg;    // Daño base del ataque
        int uses;  // se refiere a cuantas veces se puede usar dicho ataque
    public:
        AttackType();
        ~AttackType();
};

#endif 