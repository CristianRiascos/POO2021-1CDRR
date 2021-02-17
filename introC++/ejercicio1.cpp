#include <iostream>
using namespace std;

int main() {
    float producto = 0, precioFinal = 0, iva = 0.19;

    cout << "EJERCICIO 1\n";
    cout << "\nDigite el costo del producto: "; cin >> producto;
    precioFinal = ( producto * iva ) + producto;
    cout << "\nEl precio del producto con IVA incluido es " << precioFinal << endl; 
    
    return 0;
}