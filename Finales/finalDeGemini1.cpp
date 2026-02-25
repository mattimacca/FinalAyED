#include <iostream>

using namespace std;

struct Nodo{
    int valor;
    Nodo* sig;
};

Nodo* pop(Nodo* &estructura){
    Nodo* elemento = estructura;
    estructura = estructura->sig;
    elemento->sig = NULL;
    Nodo* primerNodo = new Nodo();
    *primerNodo = *elemento;
    delete elemento;
    return primerNodo;
}

void insertar(Nodo* nodoInsertar, Nodo* &lista){
    nodoInsertar->sig=lista;
    lista = nodoInsertar;
}

Nodo* unir(Nodo* &pila, Nodo* &cola, int vector[], int longArray){
    Nodo* listaUnion = NULL;
    Nodo* nodoAInsertar = NULL;

    while(pila != NULL){
        nodoAInsertar = pop(pila);
        insertar(nodoAInsertar, listaUnion);
    }
    while(cola != NULL){
        nodoAInsertar = pop(cola);
        insertar(nodoAInsertar, listaUnion);
    }
    for(int i=0; i<longArray;i++){
        nodoAInsertar = new Nodo();
        nodoAInsertar->valor = vector[i];
        nodoAInsertar->sig = NULL;
        insertar(nodoAInsertar, listaUnion);
        vector[i] = NULL;
    }
    return listaUnion;
}