#include <iostream>
using namespace std;
// Rodrigo Andrés Mena Caballero. 00078421.
void conteoX(int, int);

int main(){
    int n;

    cout << endl << endl;
    do{
        cout << "Ingrese el numero hasta el que se hara el conteo ascendente y luego descendente desde 1: "; cin >> n;
        if(n < 2){
            cout << "\nDebe ser un numero mayor que uno :)" << endl << endl;
        }
    } while (n < 2); // Bucle para que no deje pasar hasta que ingrese como minimo un 2.

    conteoX(1, n); 
    cout << endl;
    return 0;
}
void conteoX(int i, int n)
{
    if(i <= n){ // Este if permite ir desde 1 hasta el numero que se ingreso de uno en uno.
        cout << i << endl;
        i = i + 1;
        conteoX(i, n);
    } else if(n >= 1){ // Este else if permite descender desde el numero ingresado hasta uno.
        n = n - 1;
        cout << n << endl;
        if(n != 1){
            conteoX(i, n);
        }
    }
}