#include <iostream>
#include <iomanip>

class Triangulo
{
    private:
        float base, altura, lado1, lado2, lado3;
    public:
        Triangulo( float, float );
        Triangulo();
        void calcularArea();
        void calcularPerimetro();
};


Triangulo::Triangulo( float base, float altura )
{
    this -> base = base;
    this -> altura =  altura;
}


Triangulo::Triangulo(){
    base = 0;
    altura = 0;
}


void Triangulo::calcularArea()
{
    float area;

    area = ( base * altura ) / 2;

    std::cout << "El area del triangulo es " << std::fixed << std::setprecision( 3 ) << area << std::endl;
}


void Triangulo::calcularPerimetro()
{
    float perimetro;

    perimetro = lado1 + lado2 + lado3;

    std::cout << "El perimetro del triangulo es " << std::fixed << std::setprecision( 3 ) << perimetro << std::endl;
}



