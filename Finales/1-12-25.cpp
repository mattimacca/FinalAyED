#include <iostream>

using namespace std;

/*Punto 1: 
    a) Falso, lo que se muestra es la direccion de memoria, ya que (a) es un puntero al primer elemento del array.
    b)  Falso, en caso de que la lista solo tenga 2 nodos serian un segmentation fault, por otro lado, se pasa una copia del puntero
    pero el puntero sigue apuntando al mismo nodo, pudiendolo modificar
*/

/* Punto 2:
    a) La salida seria a={1, 2, 3, 8, 5, 4, 6}
*/

/* Punto 3: Retorna un error, se ejecuta la primera instruccion del if, e intenta a acceder a un NULL como si fuera un struct, fallando en el intento*/

struct NodoA{
    int a;
    NodoB* slst;
    NodoA* sig;
};

struct NodoB{
    int b;
    NodoB* sig;
};

NodoA* x[5];

int remove(NodoA* x[], int a, int b){
    NodoB* aux = NULL;
    NodoB* anterior = NULL;
    int nodosEliminados = 0;
    for(int i=0; i<5; i++){
        if(x[i]->a == a){
            aux = x[i]->slst;
            while(aux != NULL){
                if(aux->b == b){
                    if(anterior == NULL){
                        if(aux->sig != NULL) x[i]->slst = aux->sig;
                        else x[i]->slst = NULL;
                    }
                    else if(aux->sig == NULL){
                        anterior->sig = NULL;
                    }
                    else{
                        anterior -> sig = aux->sig;
                    }
                    delete aux;
                    nodosEliminados++;
                }
                anterior = aux;
                aux = aux->sig;
            }
        }
    }
}

// FALLAMOS EN LA PARTE DE PROGRAMAR