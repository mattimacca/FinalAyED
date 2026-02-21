#include<iostream>
using namespace std;
//EJERCICIO 1 B

struct Nodo{
    int dato;
    Nodo* sig;
};

void insertarSinOrdenar(Nodo* &lista, Nodo* &datoAInsertar){
    datoAInsertar->sig = lista;
    lista = datoAInsertar;
}

Nodo* interseccionListas(Nodo* lista1, Nodo* lista2){ 
    Nodo* listaInterseccion = NULL;
    Nodo* aux1 = lista1;
    Nodo* aux2 = lista2;
    Nodo* dato = NULL;
    while(aux1 != NULL){
        while (aux2 != NULL){
            if(aux1->dato == aux2->dato){
                dato = aux2;
                aux2 = aux2->sig;
                insertarSinOrdenar(listaInterseccion, dato);
            }
            else aux2 = aux2->sig;
        }
        aux1=aux1->sig;
    }
    return listaInterseccion;
}

// PUNTO 2

struct ReservaPorHotel{
    int codigoHotel;
    int cantReservas;
    int cantDiasDisponibles;
};

struct Reserva{
    int codigoHotel;
    int cantDiasReservados;
};

struct NodoReserva{
    Reserva datoReserva;
    NodoReserva* sig;
};

const int cantMaxHoteles = 50;

// Punto 3

struct Bulto{
    int codigo;
    int peso;
    char tipo;
    int cantStock;
};

struct NodoBulto{
    Bulto bulto;
    NodoBulto* sig;
};

int main(){
    ReservaPorHotel detalles[cantMaxHoteles];
}

void actualizarReservas(NodoReserva* listaDeReservas, ReservaPorHotel detalles[], int cantHoteles){
    NodoReserva* aux = listaDeReservas;
    while(aux != NULL){
        for(int i; i < cantHoteles ; i++){
            if(aux->datoReserva.codigoHotel == detalles[i].codigoHotel){
                detalles[i].cantReservas++;
                detalles[i].cantDiasDisponibles -= aux->datoReserva.cantDiasReservados;
                break;
            }
        }
        aux = aux->sig;
    }
}
