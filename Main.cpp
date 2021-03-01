#include <iostream>
#include <stdlib.h>
#include "Circulo.h"
#include "Rectangulo.h"
#include "Triangulo.h"

const int POSICIONES = 10;

void menu()
{
    std::cout << "MENU\n\n";
    std::cout << "1. Circulo" << std::endl;
    std::cout << "2. Rectangulos" << std::endl;
    std::cout << "3. Triangulos" << std::endl;
    std::cout << "0. Salir\n" << std::endl;
}


int excepcionArray( int contador )
{
    if ( contador >= POSICIONES )
    {
        return 1;
    }

    return 0;
}


int main()
{
    Circulo arregloCirculos[ POSICIONES ];
    Rectangulo arregloRectangulos[ POSICIONES ];
    Triangulo arregloTriangulos[ POSICIONES ];

    int opc = 20000, contCirculos = 0, contRectangulos = 0, contTriangulos = 0;
    float radio, base, altura;

    while( opc != 0 )
    {
        system( "CLS()" );
        menu();
        std::cout << "Que deseas hacer? "; 
        std::cin >> opc;

        switch( opc ){
            case 1:

                system( "CLS()" );

                if( excepcionArray( contCirculos ) == 1 )
                {
                    std::cout << "ERROR: Ha alcanzado la capacidad maxima en Circulos\n\n";
                    system( "PAUSE()" );
                    break;
                }

                std::cout << "Digite el radio del circulo: ";
                std::cin >> radio;
                std::cout << '\n';

                arregloCirculos[ contCirculos ] = ( Circulo( radio ) );
                arregloCirculos[ contCirculos ].calcularArea();
                arregloCirculos[ contCirculos ].calcularPerimetro();

                contCirculos++;

                std::cout << '\n';
                system( "PAUSE()" );

                break;

            case 2:
                system( "CLS()" );

                if( excepcionArray( contRectangulos ) == 1 )
                {
                    std::cout << "ERROR: Ha alcanzado la capacidad maxima en Rectangulos\n\n";
                    system( "PAUSE()" );
                    break;
                }

                std::cout << "Digite la base del rectangulo: ";
                std::cin >> base;

                std::cout << "Digite la altura del rectangulo: ";
                std::cin >> altura;
                std::cout << '\n';

                arregloRectangulos[ contRectangulos ] = ( Rectangulo( base, altura ) );
                arregloRectangulos[ contRectangulos ].calcularArea();
                arregloRectangulos[ contRectangulos ].calcularPerimetro();
                
                contRectangulos++;

                std::cout << '\n';
                system( "PAUSE()" );
                
                break;

            case 3:
                system( "CLS()" );

                if( excepcionArray( contTriangulos ) == 1 )
                {
                    std::cout << "ERROR: Ha alcanzado la capacidad maxima en Triangulos\n\n";
                    system( "PAUSE()" );
                    break;
                }

                std::cout << "Digite la base del triangulo: ";
                std::cin >> base;

                std::cout << "Digite la altura del triangulo: ";
                std::cin >> altura;
                std::cout << '\n';

                arregloTriangulos[ contTriangulos ] = ( Triangulo( base, altura ) );
                arregloTriangulos[ contTriangulos ].calcularArea();
                arregloTriangulos[ contTriangulos ].calcularPerimetro();
                
                contTriangulos++;

                std::cout << '\n';
                system( "PAUSE()" );       

                break;

            case 0:
                break;

            default:
                std::cout << "ERROR: Opcion invalida intente de nuevo.\n";
                break;
        } 
    }
    
    return 0;
}