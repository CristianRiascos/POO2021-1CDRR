#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
    protected:
        int hp; // Health
        int dmg;    // Damage

    public:
        Character() {};

        void virtual attack() {};
};

#endif