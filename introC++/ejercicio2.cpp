#include <iostream>
using namespace std;

void leerImprimir( int edadF, char sexoF[ 15 ], float alturaF ){
    cout << "\nDigite su edad: "; cin >> edadF;
    cout << "Digite su sexo: "; cin >> sexoF;
    cout << "Digite su altura en metros: "; cin >> alturaF;

    cout << "\nSu edad es "<< edadF << ", su sexo es "<< sexoF << " y su altura es "<< alturaF << endl;
    return;
}

int main(){
    int edad;
    char sexo[ 15 ];
    float altura;
    
    cout << "EJERCICIO 2\n";
    leerImprimir( edad, sexo, altura );

    return 0;
}