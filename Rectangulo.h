#include <iostream>
#include <iomanip>

class Rectangulo
{
    private:
        float  base, altura;

    public:
        Rectangulo( float, float );
        Rectangulo();
        void calcularArea();
        void calcularPerimetro();
};


Rectangulo::Rectangulo( float base, float altura)
{
    this -> base = base;
    this -> altura = altura;
}


Rectangulo::Rectangulo()
{
    base = 0;
    altura = 0;
}


void Rectangulo::calcularArea()
{
    float area;

    area = base * altura;

    std::cout << "El area del rectangulo es de " << std::fixed << std::setprecision( 3 ) << area << std::endl;
}


void Rectangulo::calcularPerimetro()
{
    float perimetro;

    perimetro = ( base + altura ) * 2;

    std::cout << "El perimetro del rectangulo es de " << std::fixed << std::setprecision( 3 ) << perimetro << std::endl;
}

