#include <iostream>

using namespace std; // Rodrigo Andrés Mena Caballero - 00078421.

struct node{
    int dato;
    node *subLeft;
    node *subRight;
};

class ArbolDeBusqueda{
    private:
        node *root;
    public:
    ArbolDeBusqueda();
    ~ArbolDeBusqueda();
    void insertar(void);
    void insertarBST(node **, int);
    void showPreorder(node *);
    void showInorder(void);
    void showIn(node *);
    void showPost(node *);
    void showPostOrder(void);
    void showPreorder(void);
    void showPre(node *);
    void search(int);
    void searchNode(node *, int);
    void deleteN(int);
    void deleteNode(node **, int);
    bool empty(void);
};

ArbolDeBusqueda::ArbolDeBusqueda(void){
    root = NULL;
}

ArbolDeBusqueda::~ArbolDeBusqueda(){
    cout << "Program Execution" << endl;
}

void ArbolDeBusqueda::insertar(void){
    int dato;
    char resp;

    do{
        cout << "Escriba y si desea continuar ingresando datos." << endl;
        cout << "Desea digitar un dato? ";
        cin >> resp;
        if(resp == 'y'){
            cout << "Elemento que desea ingresar: ";
            cin >> dato;
            insertarBST(&root, dato);
        }

    }while(resp == 'y');
}

void ArbolDeBusqueda::insertarBST(node **p, int dato){
    if(!(*p)){
        *p = new node;
        (*p)->dato = dato;
        (*p)->subLeft = NULL;
        (*p)->subRight = NULL; 
    }
    else{
        if(dato < (*p)->dato)
            insertarBST(&((*p)->subLeft), dato);
        else
            if(dato > (*p)->dato)
                insertarBST(&((*p)->subRight), dato);
            else
                cout << "El dato ya esta ingresado" << endl << endl;
    }
}

void ArbolDeBusqueda::showInorder(void){
    showIn(root);
}

void ArbolDeBusqueda::showIn(node *p){
    if(p){
        showIn(p->subLeft);
        cout << p->dato << " ";
        showIn(p->subRight);
    }
    cout << endl;
}

void ArbolDeBusqueda::showPreorder(void){
    showPre(root);
}

void ArbolDeBusqueda::showPre(node *p){
    if(p){
        cout << p->dato << " ";
        showPre(p->subLeft);
        showPre(p->subRight);
    }
    cout << endl;
}

void ArbolDeBusqueda::showPostOrder(void){
    showPost(root);
}

void ArbolDeBusqueda::showPost(node *p){
    if(p)
    {
        showPost(p->subLeft);
        showPost(p->subRight);
        cout << p->dato << " ";
    }
    cout << endl;
}

void ArbolDeBusqueda::search(int dato){
    searchNode(root, dato);
}

void ArbolDeBusqueda::searchNode(node *p, int dato){
    if(!p)
        cout << "El dato no se encuentra registrado en el arbol" << endl << endl;
    else
        if(dato < p->dato)
            searchNode(p->subLeft, dato);
        else
            if(dato > p->dato)
                searchNode(p->subRight, dato);
            else
                cout << "Dato encontrado" << endl << endl;
}

void ArbolDeBusqueda::deleteN(int dato){
    deleteNode(&root, dato);
}

void ArbolDeBusqueda::deleteNode(node **r, int dato){
    node *p;

    if(!(*r))
        cout << "El dato NO esta en el arbol" << endl << endl;
    else
        if(dato < (*r)->dato)
            deleteNode(&((*r)->subLeft), dato);
        else
            if(dato > (*r)->dato)
                deleteNode(&((*r)->subRight), dato);
            else{
                if(!((*r)->subLeft) && !((*r)->subRight)){
                    p = *r;
                    *r = NULL;
                }
                else
                    if(!((*r)->subLeft) && (*r)->subRight){
                        p = *r;
                        *r = (*r)->subRight;
                    }
                    else
                        if((*r)->subLeft && !((*r)->subRight)){ 
                            p = *r; 
                            *r = (*r)->subLeft; 
                        }
                        else
                            if((*r)->subLeft && (*r)->subRight){ 
                                p = (*r)->subLeft;
                                if(!p->subRight){
                                    (*r)->dato = p ->dato;
                                    (*r)->subLeft = p->subLeft;
                                }
                                else{
                                    node *q;
                                    while(p->subRight){
                                        q = p;
                                        p = p->subRight;
                                    }
                                    (*r)->dato = p->dato;
                                    q->subRight = p->subLeft;
                                }
                            }
                delete p;
            }
}

bool ArbolDeBusqueda::empty(void){
    return root == NULL;
}

int main(void){

    ArbolDeBusqueda objBinarySearchTree;
    bool continuar = true;

    int opcion_menu=0;
	do{
		cout << "\n|-------------------------------------|";
		cout << "\n|                 MENU                |";
		cout << "\n|------------------|------------------|";
		cout << "\n| 1. Insertar      | 5. Buscar Nodo   |";
		cout << "\n| 2. Pre-orden     | 6. Eliminar      |";
		cout << "\n| 3. In-orden      | 7. Salir         |";
		cout << "\n| 4. Post-orden    |                  |";
		cout << "\n|------------------|------------------|";
		cout << "\n\n Escoja una Opcion: ";
		cin >> opcion_menu;

        switch(opcion_menu){
		case 1:
            objBinarySearchTree.insertar();
			break;
		case 2:
            objBinarySearchTree.showPreorder();
            cout << endl;
			break;
        case 3:
            objBinarySearchTree.showInorder();
            cout << endl;
			break;
        case 4:
            objBinarySearchTree.showPostOrder();
            cout << endl;
			break;
        case 5:
            int data;

            cout << "Digite el dato que quiere buscar: ";
            cin >> data;
            objBinarySearchTree.search(data);
			break;
        case 6:
            cout << "Digite el dato que quiere borrar: ";
            cin >> data;
            objBinarySearchTree.deleteN(data);
			break;
		case 7:
            continuar = false;
            system ("cls");
			break;
		default:
			cout << "\n\n Opcion No Valida WINDOWS ERROR . . . .\n\n DESCONECTE SU PC.";
		}
	} while (opcion_menu != 7);

    return 0;
}