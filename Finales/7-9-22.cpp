#include <iostream>

using namespace std;

struct Columna{
    int columna;
    int entero;
};

struct Nodo{
    Columna infoColomuna;
    Nodo* sigColumna;
};

Nodo* insertar(int fila, int columna, int valor, Nodo* v[]){
    Nodo* nodoAInsertar = new Nodo();
    nodoAInsertar->infoColomuna.columna = columna;
    nodoAInsertar->infoColomuna.entero = valor;
    nodoAInsertar->sigColumna = NULL;
    Nodo* aux = v[fila];
    Nodo* anterior = NULL;
    while(aux!=NULL and aux->infoColomuna.columna < columna){
        anterior = aux;
        aux = aux->sigColumna;
    }
    if(anterior == NULL){
        nodoAInsertar->sigColumna = v[fila];
        v[fila] = nodoAInsertar;
    }
    else{
        anterior->sigColumna = nodoAInsertar;
        nodoAInsertar->sigColumna = aux;
    }

    return v[fila];
}


int* buscar(int valor, Nodo* v[]){// Asumo que se quiere saber la direccion del primero
    Nodo* aux = NULL;
    for(int i=0; i<4; i++){
        aux = v[i];
        while(aux != NULL){
            if(aux->infoColomuna.entero == valor){
                cout << "La direccion de memoria es: " << &(aux->infoColomuna.entero) << endl;
                return &(aux->infoColomuna.entero);
            }
            else{
                aux = aux->sigColumna;
            }
        }
        cout << "No se encontro el valor en la matriz" << endl;
        
    }
    return NULL;
}

int main(){
    int n, m, valor;


    cout << "Ingrese el numero de filas: ";
    cin>>n;
    
    cout << endl << "Ingrese el numero de columnas: ";
    cin>>m;

    Nodo* matrizEsparcida[n];

    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            cout << "Ingrese valor para la fila " << i+1 << " y columna " << j+1<< ": ";
            cin >> valor;
            if(valor!=0) insertar(i, j, valor, matrizEsparcida); 
        }
    }
}