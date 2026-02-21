#include <iostream>
#include <cstring>

using namespace std;

struct Pasajero{
    char nombreYapellido[40];
    char destino[30];
    char vuelo[6];
    int asiento;
    int salida;
    int llegada;
};

struct Nodo{
    Pasajero info;
    Nodo* sig;
};
// PRECONDICIONES: La lista prevista siempre empezara(apuntara) al ultimo elemento de la lista
void ingresarPasajero(Nodo* &lista, Pasajero pasajero){
    Nodo* nuevoPasajero = new Nodo();
    nuevoPasajero->info = pasajero;
    Nodo* aux = lista;
    if(lista == NULL){ 
        // CASO 1: Lista vacía. El nodo se apunta a sí mismo.
        nuevoPasajero->sig = nuevoPasajero;
        lista = nuevoPasajero;
    }
    else{ 
        // CASO 2: Ya hay 1 o más elementos. (Tu lógica intacta)
        nuevoPasajero->sig = lista->sig; // El nuevo apunta al PRIMERO
        lista->sig = nuevoPasajero;      // El viejo ÚLTIMO apunta al nuevo
        lista = nuevoPasajero;           // Actualizamos el ÚLTIMO
    }
    
}

void visualizarPasajero(Nodo* lista, char nombre[]){
    Nodo* aux = lista;
    while(aux->sig != lista){
        if(strcmp(nombre, aux->info.nombreYapellido) == 0){
            Pasajero pasajero = aux->info;
            cout << pasajero.nombreYapellido<< endl;
            cout << pasajero.destino<< endl;
            cout << pasajero.vuelo<< endl;
            cout << pasajero.asiento<< endl;
            cout << pasajero.salida<< endl;
            cout << pasajero.llegada<< endl;
            return;
        }
        aux = aux->sig;
    }
    cout << "No existe pasajero con ese nombre" << endl;
}

void eliminarPasajero(Nodo*& lista, char nombre[]){ // No se tiene un orden de los pasajeros por lo que cambiar el ultimo no afectaria
    Nodo* aux = lista;
}