#include <iostream>
using namespace std;
// Rodrigo Andrés Mena Caballero. 00078421.
int emcidi(int, int);

int main(){
    int menor = 0, mayor = 0;

    cout << "Calcular el MCD de dos numeros por Euclides" << endl << endl;

    cout << "Ingrese el numero mayor: "; cin >> mayor; 
    cout << "Ingrese el numero menor: "; cin >> menor;
    cout << endl;

    cout << "El resultado del MCD por Euclides es: " << emcidi(mayor, menor) << endl;
}

int emcidi (int mayor, int menor){
    if (mayor % menor == 0){ // Retorna el MCD.
        return menor;
    }
    if (mayor % menor != 0){
        int remp;
        remp = mayor;
        mayor = menor % mayor;
        menor = remp;
        emcidi(mayor, menor); // Volvera a llamar a la función hasta que se cumpla que el residuo es 0.
    }
}