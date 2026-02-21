#include <iostream>
using namespace std;

struct Nodo{ // Nodo para pila y cola
    int dato;
    Nodo* sig;
};

// Punto 1(5/10)
int pop(Nodo* pila);

void insertarOrdenado(Nodo* &listaPrincipal, int datoEs){
    Nodo* nodoaINsertar = new Nodo();
    nodoaINsertar->dato = datoEs;
    Nodo* aux = listaPrincipal;
    Nodo* anterior = NULL;
    while(aux != NULL and aux->dato > datoEs){
        anterior = aux;
        aux = aux->sig;
    }
    if(anterior == NULL){
        // CASO A: Va al principio (o la lista estaba vacía)
        nodoaINsertar->sig = listaPrincipal;
        listaPrincipal = nodoaINsertar;
    }
    else{
        anterior->sig = nodoaINsertar;
        nodoaINsertar->sig = aux;
    }
}

Nodo* unionPilaYCola(Nodo* &cola, Nodo* &pila){
    Nodo* listaUnion = NULL;
    while(pila != nullptr){
        int dato = pop(pila);
        insertarOrdenado(listaUnion, dato);
    }
    while(cola != nullptr){
        int dato = pop(cola);
        insertarOrdenado(listaUnion, dato);
    }

    return listaUnion;

}

//Punto 2 (10/10)

struct Nota{
    int legajo;
    float notaPrimerParcial;
    float notaSegundoParcial;
};

struct NotaRecuperatorio{
    int legajo;
    float notaRecuperatorio;
};

struct NodoRecuperatorio{
    NotaRecuperatorio recuperatorio;
    NodoRecuperatorio* sig;
};

const int MAX_ALUMNOS = 1500;

Nota notas[MAX_ALUMNOS];

void actualizarNotas(NodoRecuperatorio* recuperatorios, Nota notas[]){ //Asumimos que hay un registro por alumno si hizo el recu
    NodoRecuperatorio* aux = recuperatorios;
    int i=0;
    while(aux != NULL){
        i = 0;
        while(aux->recuperatorio.legajo != notas[i].legajo){
            i++;
        }
        if(aux->recuperatorio.notaRecuperatorio >= 6){
            notas[i].notaSegundoParcial = aux->recuperatorio.notaRecuperatorio;
        }
        aux = aux->sig;   
    }
}


//Punto 3 (5/10)

//Punto 4 (0/10)