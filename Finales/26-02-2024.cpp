#include <iostream>

using namespace std;


// Punto 1 (6/10)
struct Nodo{
    int dato;
    Nodo* sig;
};

int pop(Nodo* estructura);

void insertarOrdenado(Nodo* &lista, int valor){
    Nodo* aux = lista;
    Nodo* anterior = NULL;
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->sig = NULL;

    while(aux != NULL && aux->dato > valor){
        anterior = aux;
        aux = aux->sig;
    }
    if(anterior == NULL){
        nuevo->sig = lista;
        lista = nuevo;
    }
    else{
        anterior->sig = nuevo;
        nuevo->sig = aux;
    }
}

Nodo* listaInterseccion(Nodo* pila, Nodo* lista){// Asumimos que no queremos modificar las estructuras originales y que no contienen datos repetidos
    Nodo* listaInterseccion = NULL;
    Nodo* auxPila = pila;
    Nodo* auxLista = NULL;
    while(auxPila != nullptr){
        auxLista = lista;
        while(auxLista != NULL){
            if(auxLista->dato == auxPila->dato){
                insertarOrdenado(listaInterseccion, auxLista->dato);
                break;
            }
            auxLista = auxLista->sig;
        }
        auxPila = auxPila->sig;
    }
    return listaInterseccion;
}


// Punto 2

struct Cuenta{
    int numCuenta;
    int cantTransacciones;
    float saldo;
};

struct Transaccion{
    int numCuenta;
    float monto;
};

struct NodoTransaccion{
    Transaccion info;
    NodoTransaccion* sig;
};

const int MAX_CUENTAS = 150;

Cuenta saldos[MAX_CUENTAS];

void actualizarSaldos(NodoTransaccion* transacciones, Cuenta saldos[]){
    NodoTransaccion* aux= transacciones;
    while(aux != NULL){
        for(int i=0; i < MAX_CUENTAS; i++){ // Recorremos el vector varias veces ya que es mas eficiente que recorrer la lista de transacciones
            if(saldos[i].numCuenta == aux->info.numCuenta){
                saldos[i].cantTransacciones++;
                saldos[i].saldo -= aux->info.monto;
                break;
            }
        }
        aux = aux->sig;
    }
}

int main(){
    int *p;
    int x=10;
    p=new int [10];
    p[0]=20;
    p[1]=23;
    p[2]=*p;
    p[3]=*(p+1);
    p[4]=*p+*(p+1);
    p[9] = 100;
    cout << *(p+9) << endl;
    cout << *p+1 << endl;
    cout << *(p+1) << endl;
    cout<<*(p+*(p+1))<<endl;
    cout<<*(p+4)<<endl;
    return 0;
}
