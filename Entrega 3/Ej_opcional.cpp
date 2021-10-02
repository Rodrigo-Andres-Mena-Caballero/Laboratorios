#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct pedido{
    int cantP, n;
    string ingredientes, masa, bebida;
};

struct nodo{
    pedido datos;
    nodo *sig;
};

class ListaPedido{
    private: 
        nodo *head;
    public:
        ListaPedido();
        void insFinal(int, string, string, string, int);
        void mostrarPedido(void);

};

ListaPedido::ListaPedido(void){
    head = nullptr;
}

void ListaPedido::insFinal(int d1, string d2, string d3, string d4, int n){
    nodo *nuevo = new nodo;

    nuevo->datos.cantP = d1;
    nuevo->datos.ingredientes = d2;
    nuevo->datos.masa = d3;
    nuevo->datos.bebida = d4;
    nuevo->datos.n = n;
    nuevo->sig = head;
    head = nuevo;
}

void ListaPedido::mostrarPedido(void){
    nodo *recorre = head;
    if(!recorre){
        cout << "\nNO HA REALIZADO NINGUN PEDIDO" << endl;
        system("PAUSE");
    }
    cout << endl;

    while(recorre != nullptr){
        cout << "PEDIDO NUMERO " << recorre->datos.n << endl;
        cout << "Cantidad de pupusas: " << recorre->datos.cantP << endl;
        cout << "Ingredientes: " << recorre->datos.ingredientes << endl;
        cout << "Tipo de masa: " << recorre->datos.masa << endl;
        cout << "Bebida: " << recorre->datos.bebida << endl << endl;
        recorre = recorre->sig;
    }
}

int menu(){
    int opcion = 0;
    cout << "1) Realizar un pedido." << endl;
    cout << "2) Mostrar el pedido." << endl;
    cout << "3) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();

    return opcion;
}

int main(void){
    cout << "\nBienvenido a la pupuseria twilight, si gusta puede ver el menu de opciones y seleccionar una de ellas." << endl << endl;
    ListaPedido pedido;

    int c, opcn, numero = 0;
    string i = "", m = "", b = "";
    bool loop = true;

    do{
        switch(menu()){
            case 1:
                cout << endl << "Ingrese cuantas pupusas desea en su pedido: "; 
                cin >> c; cin.ignore();
                cout << "Ingrese los ingredientes para sus pupusas, si es mas de uno ingrese cuantas quiere con ese ingrediente: ";
                getline(cin, i);
                cout << "Ingrese el tipo de masa entre arroz o maiz para sus pupusas: ";
                getline(cin, m);
                cout << "¿Desea agregar una Coca-cola de 2.5 Litros para compartir en familia?" << endl;
                cout << "1. Si" << endl;
                cout << "2. No" << endl;
                cout << "Opcion: "; cin >> opcn; cin.ignore();
                if(opcn = 1){
                    b = "Con Coca-cola";
                } else if (opcn = 2){
                    b = "Sin Coca-cola";
                }
                numero++;
                pedido.insFinal(c, i, m, b, numero);
                cout << endl;
                break;
            case 2: 
                pedido.mostrarPedido();
                break;
            case 3:
                loop = false;
                system("PAUSE");
                break;
            default:
                cout << "\nLa opcion ingresada no es valida, favor intente de nuevo. :)" << endl << endl;
                break;
        }
    }while(loop);

    return 0;
}
