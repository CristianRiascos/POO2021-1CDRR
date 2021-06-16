#ifndef POTION_H
#define POTION_H

#include "Item.hpp"

using namespace std;

class Potion : public Item
{
    public:
        Potion() {};
        Potion( int );
        ~Potion() {};

        void printInfoPotion( );    // Sobreescritura en hijas
};

#endif