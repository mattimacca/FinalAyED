#include <iostream>
using namespace std;

struct Alumno{
    int id;
    string nombre;
};

struct Nodo{
    Alumno alumno;
    Nodo* sig;
};

void darDeBaja(Nodo* &listaDeALumnos, int idBuscada){
    Nodo* actual = listaDeALumnos;
    Nodo* anterior = NULL;
    while(actual != NULL and actual->alumno.id != idBuscada){
        anterior = actual;
        actual = actual->sig;
    }

    if(actual == NULL) return;
    else if(anterior== NULL) listaDeALumnos = listaDeALumnos->sig;
    else{
        anterior->sig = actual->sig;
        return;
    }
    delete(actual);
}

