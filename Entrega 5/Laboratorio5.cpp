#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct mascota{
    int ID, edad; 
    float peso;
    string nombreDueno, raza ;
}; 

struct nodo{
    mascota datos;
    nodo *sig;
};

class ListaCircularVet{
    private:
        nodo *head;

    public: 
        ListaCircularVet();
        void insLista(int, string, string, float ,int);
        void mostrarListaConID(void); 
        void borrarConID(void);
};

ListaCircularVet::ListaCircularVet(void){
    head = nullptr;
}

void ListaCircularVet::insLista(int id, string nom, string raza, float w, int age){ // Inserta al final de la lista siempre.
    nodo *nuevo = new nodo, *actual;

    nuevo->datos.ID = id;
    nuevo->datos.nombreDueno = nom;
    nuevo->datos.raza = raza;   
    nuevo->datos.peso = w;
    nuevo->datos.edad = age;
    
    if(!head){ // Si la lista no contiene nodos.
        head = nuevo;
        head->sig = head;
    } else { //Si la lista ya contiene nodos.
        nuevo->sig = head;
        actual = head;
        while(actual->sig != head)
            actual = actual->sig;
        actual->sig = nuevo;
    }
}

void ListaCircularVet::mostrarListaConID(void){
    nodo *actual = head; 
    bool encontrado = false;
    int aidi = 0; //Este sera la variable que almacena el dato que se quiere mostrar

    if(head != nullptr){
            cout << "\nIngrese el ID que desea buscar: "; cin >> aidi;
        do{
            if(actual->datos.ID == aidi){
                cout << "\nNombre del dueño de la mascota: " << actual->datos.nombreDueno;
                cout << "\nRaza de la mascota: " << actual->datos.raza;
                cout << "\nPeso de la mascota: " << actual->datos.peso << " Lb";
                cout << "\nEdad de la mascota: " << actual->datos.edad;
                encontrado = true;
            }
            actual = actual->sig;
        } while (actual != head && encontrado != true);

        if(!encontrado) cout << "\nNo se ha encontrado informacion con esa ID.\n";
    
    } else cout << "\nNo ha ingresado informacion sobre ninguna mascota.\n\n";

    system("PAUSE");
}

void ListaCircularVet::borrarConID(void){
    nodo *actual = head, *anterior = nullptr; 
    bool encontrado = false;
    int aidi = 0; //Este sera la variable que almacena el dato que se quiere mostrar
    
    if(!head){
        cout << "\nNo ha ingresado informacion sobre ninguna mascota\n\n";
    } else {
        cout << "\nIngrese el ID que desea eliminar: "; cin >> aidi;
        do{
            if(actual->datos.ID == aidi){
                anterior = actual;
                actual = actual->sig;
                encontrado = true;
            }
            actual = actual->sig;
        } while (actual != head && encontrado != true);
        
        if(encontrado == false){
            cout << "\nLa informacion de la mascota no se encuentra en la lista.\n";
        } else if(encontrado == true){
            cout << "\nInformacion eliminada con exito!\n\n";
            delete anterior;
        }
    }
    system("PAUSE");
}

int menu(){
    int opcion = 0;
    cout << " \n1) Ingresar datos de una mascota." << endl;
    cout << "2) Mostrar datos de una mascota ingresando el ID." << endl;
    cout << "3) Borrar informacion de una mascota." << endl;
    cout << "4) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();

    return opcion;
}

int main(){
    ListaCircularVet data;
    int age, aidi;
    float weight;
    string name, raza;
    bool loop = true;


    do{
        switch(menu()){
            case 1:
                cout << endl << "Ingrese un ID para la informacion de esta mascota: "; 
                cin >> aidi; cin.ignore();
                cout << "Ingrese el nombre del dueño de la mascota: ";
                getline(cin, name);
                cout << "Ingrese la raza de la mascota: ";
                getline(cin, raza);
                do{
                    cout << "Ingrese el peso de la mascota en libras (solo el numero): ";
                    cin >> weight; cin.ignore();
                    if (weight < 1){
                        cout << "Por favor escriba un numero positivo y no trollee a la maquina :)" << endl;
                    }
                } while (weight < 1);
                do{
                    cout << "Ingrese la edad de la mascota: ";
                    cin >> age; cin.ignore();
                    if (age < 0 || age > 100 ){
                        cout << "Por favor escriba una edad que este en el rango de 0-100 años" << endl;
                    }
                } while (age < 1 || age > 100);

                data.insLista(aidi, name, raza, weight, age);
                cout << endl;
                break;
            case 2: 
                data.mostrarListaConID();
                break;
            case 3: 
                data.borrarConID();
                break;
            case 4:
                loop = false;
                cout << "\nMuchas gracias por visitarnos, esperamos vuelva pronto :D";
                cout << endl;
                system("PAUSE");
                break;
            default:
                cout << "\nLa opcion ingresada no es valida, favor intente de nuevo. :)" << endl << endl;
                break;
        }
    }while(loop);
}