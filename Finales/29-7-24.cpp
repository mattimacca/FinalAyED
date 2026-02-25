#include <iostream>

using namespace std;

struct NodoTrabajo{
    char titulo[50];
    int categoria;
    char correoResponsable[50];
    int evaluadores[3];
    int dictamen[40][3];

    NodoTrabajo* sig;
};

NodoTrabajo* trabajos[5];


void dictamen(NodoTrabajo* trabajos[5], int resultadosEvaluador[12], int idEvaluador, int categoria, char titulo[50]){
    int aspFormales = 0;
    int cienciaTecnologia = 0;
    int autores = 0;
    for(int i=0; i < 5; i++){
        NodoTrabajo* listaTrabajos = trabajos[i];
        while(listaTrabajos!=NULL && listaTrabajos->titulo != titulo && listaTrabajos->categoria != categoria) listaTrabajos = listaTrabajos->sig;
        if(listaTrabajos!=NULL){

        }
    }
}
