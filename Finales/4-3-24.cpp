#include <iostream>

using namespace std;

struct Lenguaje{
    int cantPython;
    int cantCPP;
    int cantJava;
    int otros;
};

struct NodoLenguajeNuevo{
    char otro[50];
    int cant;
    NodoLenguajeNuevo* sig;
};
    


struct NodoLenguaje{
    Lenguaje info;
    NodoLenguajeNuevo* nuevosLenguajes;  
};

struct Encuesta{ // Necesaria??, creo que no.
    int actividad;
    int institucion;
    int lenguaje;
};

int unaEncuesta(int &act, int &inst,int &len, char* cual);

void cargarMatriz(Lenguaje matriz[3][3], int act, int inst, int len, char* otro){
    for(int i=0; i<4; i++){
        for(int j=0; j<4;j++){
            
        }
    }
}

int main(){
    int act, inst, len;
    char otro[50];

    Lenguaje encuestas[3][3];

    while(unaEncuesta(act, inst, len, otro) != 0){
        //cargarMatriz();
    }
}