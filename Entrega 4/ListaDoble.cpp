#include <iostream>
#include <stdlib.h>
using namespace std;
//Implementacion de la lista 

struct trabajadores{
    int id;
    string usuario, perfil;
};

class Node {
    //interfaz privada
    private:
        trabajadores data;
        // Tendra un nodo anterior
        Node *previous;
        // Tendra un nodo siguiente
        Node *next;

        //Como las variables son privadas debemos 
        // compartirlas con las funciones
        friend class LinkedList;
};

class LinkedList{
    //Para los elementos de nuestra lista
    //El constructor
    public:
        // constructor
        LinkedList();
        // el destructor
        ~LinkedList();
        // Asigna memoria dinamicamente, el destructor libera memoria
        // funcion que devuelve el numero entero del primer nodo de
        // la lista HEAD
        void addFront(int, string, string);
        // Funcion para el nuevo nodo, que pasa el valor a la funcion
        void addBack(int, string, string);
        //Funcion para eliminar al primer Nodo
        void removeFront();
        //Funcion para eliminar al ultimo Nodo
        void removeBack();
        // Funcion para imprimir la informacion de forma inversa
        void printReverse();
        //Funcion para imprimir la lista del principio al final 
        // Mostrar de forma normal
        void printForward();
    
    private:
        //Declarar los punteros que apuntan a los nodos centinela
        Node *header;
        Node *trailer;
};

int main(){
    //crear un objeto de la lista una instancia
    LinkedList DoubleList;
    // Añadir datos a la lista
    system("cls");
    cout << endl;
    DoubleList.addFront(0001, "Andres27", "Admin");
    //  Anadir al final
    DoubleList.addBack(0002, "Rodrigouu", "Cliente");
    // Para imprimir
    cout << "\nImprimir los datos:" << endl;
    DoubleList.printForward();
    cout << "\nImprimir datos alreves:" << endl << endl;
    DoubleList.printReverse();   
    cout << "Eliminando datos . . ." << endl << endl;
    // Eliminar HEAD
    DoubleList.removeFront();
    // Eliminar TAIL
    DoubleList.removeBack();

    system("PAUSE");
    return 0;
};

LinkedList::LinkedList(){
    // Se define dinamicamente la memoria 
    header = new Node;
    // creamos el trailer (que es el centinela final)
    trailer = new Node;
    //Tenemos que hacer que el header apunte al trailer, 
    // y el trailer al header
    header->next = trailer;
    trailer->previous = header;
    //Como la lista esta vacia se igual a NULL
    header->previous = NULL;
    trailer->next = NULL;
}

//Al final si se puede
LinkedList::~LinkedList(){
    // llama a la funcion removeFront
    //para cuando elimine el elemento de la lista que no este vacia
    //Sera cuando ambos nodos centinela se apunten, es decir no hay head ni tail
    while(header->next!=trailer){
        removeFront();
    }
    //eliminar individualmente
    delete header;
    delete trailer;
}

void LinkedList::addFront(int aidi, string nombre, string tipo){
    // anadir un nuevo nodo a la memoria que se pasa por valor
    Node *nd = new Node;
    //al nodo que tenemos le ponemos el dato
    nd->data.id = aidi;
    nd->data.usuario = nombre;
    nd->data.perfil = tipo;
    nd->previous = header;
    // es decir que ahora esta apuntando al nodo head
    nd->next = header->next; 

    // cambiar los punteros del header, y del nodo head
    // su puntero anterior es el nuevo nodo
    // acceder al nodo head, su puntero previous es 
    // el nuevo nodo anadido a la lista
    header->next->previous = nd;

    // el puntero head 
    header->next = nd;

}
void LinkedList::addBack(int aidi, string nombre, string tipo){
    Node *nd = new Node;
    nd->data.id = aidi;
    nd->data.usuario = nombre;
    nd->data.perfil = tipo;
    nd->previous=trailer->previous;
    nd->next=trailer;

    //actualizar trailer
    // a traves de trailer accedemos a su nodo previo apunta al nuevo nodo
    trailer->previous->next = nd;
    trailer->previous = nd;
}
void LinkedList::removeFront(){
    // Eliminar el nodo del principio
    // Accedemos al nodo siguiente de head
    Node *nd=header->next->next;
    delete header->next;

    // actualizar los punteros del header y del nodo anterior
    header->next=nd;
    nd->previous=header;
}
void LinkedList::removeBack(){
    // Eliminar a final
    // tomar una referencia al nodo anterior al nodo tail
    Node *nd = trailer->previous->previous;

    delete trailer->previous;

    //actualizar el puntero apuntara al 
    //nodo anterior al nodo tail que se elimino
    trailer->previous=nd;
    nd->next=trailer;
}
void LinkedList::printReverse(){
    // Vamos a imprimirlos 
    // Va del final al principio
    //referencia a tail
    Node *nd=trailer->previous;

    //Si el nodo es diferente al centinela inicial
    while (nd!=header){
        // se imprime el nodo
        cout << "Numero de ID: " << nd->data.id << endl;
        cout << "Nombre de usuario: " << nd->data.usuario << endl;
        cout << "Puesto de trabajo: " << nd->data.perfil << endl << endl;
        //actualizar el nodo anterior
        nd=nd->previous;
    }    

}
void LinkedList::printForward(){
    // Vamos a imprimirlos 
    // Va del principio al final
    //referencia a head
    Node *nd=header->next;

    //Si el nodo es diferente al centinela final
    while (nd!=trailer){
        // se imprime el nodo
        cout << "Numero de ID: " << nd->data.id << endl;
        cout << "Nombre de usuario: " << nd->data.usuario << endl;
        cout << "Puesto de trabajo: " << nd->data.perfil << endl << endl;
        //actualizar el nodo al siguiente
        nd=nd->next;
    }    
}