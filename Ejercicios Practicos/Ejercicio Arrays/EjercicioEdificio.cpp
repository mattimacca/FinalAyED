#include <iostream>
#include <cstring> // Para strcmp
using namespace std;

struct Habitacion {
    int numero;
    char huesped[20];
};

struct Nodo {
    Habitacion info;
    Nodo* sig;
};

// TU MISIÓN: Completar esta función
int buscarHuesped(Nodo* hotel[], char nombreBuscado[]) {
    // Pista: Necesitas un FOR para los pisos (0 a 4)
    // Y adentro del FOR, un WHILE para recorrer la lista de ese piso.
    Nodo* aux;
    // ... tu código aquí ...
    for(int i=0; i < 5; i++){
        aux = hotel[i];
        while(aux != NULL){
            if(!strcmp(aux->info.huesped, nombreBuscado)) return aux->info.numero;
            else                                          aux = aux->sig;
        }
    };
    
    return -1; // Si recorrió todo y no salió antes, no lo encontró.
}