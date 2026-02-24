// https://raw.githubusercontent.com/mattimacca/FinalAyED/refs/heads/main/FinalesNuevos/2024/WhatsApp%20Image%202026-02-22%20at%206.06.57%20PM.jpeg

#include <iostream>

using namespace std;

/* Punto 1
    a) Falso, se incrementa la direccion de memoria de p
    b) Falso, se pasa una copia del puntero al primer nodo, pero ese puntero sigue apuntando al primer nodo, permitiendole modificarla
*/

/* Punto 2
    a) Compila y devuelve: 10, 10 y 19(19 porque acordate que se modifican los valores dentro del vector, tene cuidado con eso)
    b) Compila, imprime el numero 5, pero despues el programa falla, ya que entra en un while infinito
*/

// Punto 4

struct NodoA{
    int legajo;
    string nya;
    float promedio;
    NodoA* sig;
};

NodoA* x[5][10];

NodoA* alumnosBuenos(NodoA* x[5][10]){

    NodoA* listaDeAlumnosBuenos = NULL;
    NodoA* listaDeBusqueda = NULL;

    for(int i=0; i<5; i++){

        for(int j=0; j<10; j++){

            NodoA* listaMateria = x[i][j];
            

            while(listaMateria != NULL){
                listaDeBusqueda = listaDeAlumnosBuenos;

                if(listaMateria->promedio > 6 && listaMateria->promedio < 10){
                    
                    while(listaDeBusqueda != NULL){
                        if(listaMateria->legajo == listaDeBusqueda->legajo) break;
                        listaDeBusqueda = listaDeBusqueda->sig;
                    }

                    if(listaDeBusqueda == NULL){
                        NodoA* alumnoBueno = new NodoA();
                        *alumnoBueno = *listaMateria;
                        alumnoBueno->sig = listaDeAlumnosBuenos;
                        listaDeAlumnosBuenos = alumnoBueno;
                    }
                    
                }

                listaMateria = listaMateria->sig;
            }

        }

    }

    return listaDeAlumnosBuenos;
}

// Sin abstraer la logica a los nodos

struct NodoAlumno{
    string nombre;
    int legajo;
    int CantDeMateriasAprobadas;
    NodoAlumno* sigAlumno;
    NodoMateria* lstMaterias;
};

struct NodoMateria{
    int codMateria;
    float notadeAprobacion;
    NodoMateria* sigMateria;
};

struct NodoPila{
    int legajo;
    int codMateria;
    float nota;
    NodoPila* sig;
};

NodoAlumno* listaAlumnos;

NodoPila* pila;

