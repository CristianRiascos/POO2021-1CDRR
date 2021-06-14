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
 
// Herz ganará 5 puntos de vida máxima por cada pelea que gane
void Herz::increaseHp(  )
{
    hpMax += 5;
}


int Herz::getHpMax()
{
    return hpMax;
}


void Herz::useItem( string code,int posInventory )
{

    // Entra a la poción de vida
    if( code == "008f39" ) 
    {
        /* 
            Si la vida del jugador sumada la poción es mayor a la vida máxima, Herz recuperará la diferencia
            entre la vida que tenga y la vida máxima. Si el jugador tiene los puntos de vida máximos y usa la 
            poción, no se le sumará ningún punto de vida y perderá la poción
        */
        if( ( hp + 100 ) >= hpMax )
        {   
            int sum = hp - hpMax;
            hp += sum;
        }
        
        // Si la vida del jugador sumada la poción es menor a la vida máxima, suma 100 puntos de vida
        else if( ( hp + 100 ) < hpMax ) 
        {
            hp += 100;
        }
    }


    // Entra a la poción de daño
    else if( code == "FF0000" )
    {
        dmg += 10;      // El jugador obtiene 10 puntos de daño adicionales
    }


    // Entra a la poción de daño instantaneo 
    else if( code == "ff8000" )
    {
        // AQUI HACE DAÑO AL ENEMIGO PERO DEBE DE ESTAR EN COMBATE
    }
    

    // Entra a la poción de escape
    else if( code == "572364" )
    {   
        /* 
            Variable entera cuyo número será asignado entre 0 y 1 por medio del azar.
            Si sale 1: La posción de escape funcionará
            Si sale 0: La poción de escape hará que Herz pierda 10 puntos de vida máximos
        */
        int choice;
        srand( time ( NULL ) );
        choice = rand() % 2;

        if( choice == 0 )
        {
            hpMax -= 10;    
        }
        else
        {
            // AQUI SERVIRÁ PARA QUE HERZ ESCAPE DE UNA BATALLA
        }
    }

}