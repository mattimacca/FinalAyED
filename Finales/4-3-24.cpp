#include <iostream>

using namespace std;

struct Lenguaje{
    int cantPython;
    int cantCPP;
    int cantJava;
    int otros;
};

struct NodoLenguaje{
    Lenguaje info;
    NodoLenguaje* sig;
};

struct Encuesta{ // Necesaria??, creo que no.
    int actividad;
    int institucion;
    int lenguaje;
};

int unaEncuesta(int &act, int &inst,int &len, char* cual);

void cargarMatriz(Lenguaje matriz[2][2], int act, int inst, int len, char* otro){
    
}

int main(){
    int act, inst, len;
    char otro[50];

    Lenguaje encuestas[2][2];

    while(unaEncuesta(act, inst, len, otro) != 0){
        cargarMatriz
    }
}