#include <iostream>
#include <cmath>
#include <iomanip>

class Circulo
{
    private:
        float radio, pi;        

    public:
        Circulo( float );
        Circulo();
        void calcularArea();
        void calcularPerimetro();
        float getRadio();
};


Circulo::Circulo( float radio )
{
    this -> radio = radio; 
    pi = M_PI;
}


Circulo::Circulo()
{
    radio = 0;    
}


void Circulo::calcularArea()
{
    float area;

    area = ( pow( radio, 2 ) * pi );

    std::cout << "El area del circulo es " << std::fixed << std::setprecision( 3 ) << area << std::endl;
} 


void Circulo::calcularPerimetro()
{
    float perimetro;

    perimetro = ( 2 * pi ) * radio;

    std::cout << "El perimetro del circulo es " << std::fixed << std::setprecision( 3 ) << perimetro << std::endl;    
}


float Circulo::getRadio()
{
    return radio;
}