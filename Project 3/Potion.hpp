#ifndef POTION_H
#define POTION_H

#include "Item.hpp"
#include <string>

using namespace std;

class Potion : public Item
{
    protected:
        string code;   // Codigo de cada poción para su identificación posterior
    public:
        Potion() {};
        Potion( int );
        ~Potion() {};

        string getCode();
        void printInfoPotion( Potion );
};

#endif