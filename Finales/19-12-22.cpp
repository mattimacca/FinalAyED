#include <iostream>

using namespace std;

struct Alumno{
    int legajo;
    char apellidoYNombre[30];
    int nota;
};

struct Nodo{
    Alumno info;
    Nodo* sig;
};

struct Final{
    int fecha;
    int materia;
    int curso;
    int legajo;
    char apellidoYNombre[30];
    int nota;
};

struct NodoFinal{
    Final info;
    NodoFinal* sig;
};

int strcmp(char nombre[30], char otroNombre[30]);
void strcpy(char cosaACopiar[30], char destino[30]);

NodoFinal* unificarListas(Nodo* &lista1, Nodo* &lista2, int &fecha, int &codMateria, int &curso){
    cout << "Ingresar fecha en formato AAAAMMDD: ";
    cin >> fecha;

    cout << "Ingresar codigo de materia en formato NNNNNN: ";
    cin >> codMateria;

    cout << "Ingresar curso en formato LNNNN: ";
    cin >> curso;

    NodoFinal* listaNueva = NULL;

    while(lista1 != NULL and lista2 != NULL){
        if(strcmp(lista1->info.apellidoYNombre, lista2->info.apellidoYNombre) > 0) insertarEnLista(lista1, listaNueva, fecha, codMateria, curso);

        else if(strcmp(lista1->info.apellidoYNombre, lista2->info.apellidoYNombre) < 0) insertarEnLista(lista2, listaNueva, fecha, codMateria, curso);
        else{
            insertarEnLista(lista1, listaNueva, fecha, codMateria, curso);
            insertarEnLista(lista2, listaNueva, fecha, codMateria, curso);
        }
    }

    if(lista1 == NULL) insertarEnLista(lista2, listaNueva, fecha, codMateria, curso);
    else if(lista2 == NULL) insertarEnLista(lista1, listaNueva, fecha, codMateria, curso);

    
}

void insertarEnLista(Nodo* &lista, NodoFinal* &listaNueva, int fecha, int codMateria, int curso){
    NodoFinal* plantilla = new NodoFinal();
    plantilla->info.fecha = fecha;
    plantilla->info.materia = codMateria;
    plantilla->info.curso = curso;
    plantilla->sig = NULL;

    NodoFinal* ultimoEnLaLista = NULL;


    NodoFinal* nuevoNodoFinal = plantilla;
    strcpy(lista->info.apellidoYNombre, nuevoNodoFinal->info.apellidoYNombre);
    nuevoNodoFinal->info.legajo = lista->info.legajo;
    nuevoNodoFinal->info.nota = lista->info.nota;
    Nodo* auxEliminacion = lista;
    lista = lista->sig;
    auxEliminacion->sig = NULL;
    delete auxEliminacion;

    if(ultimoEnLaLista == NULL){
        listaNueva = nuevoNodoFinal;
        ultimoEnLaLista = nuevoNodoFinal;
    }
    else{
        ultimoEnLaLista->sig = nuevoNodoFinal;
        ultimoEnLaLista = nuevoNodoFinal;
    }

}


void actualizarArchivo(NodoFinal* lista){
    FILE* arch = fopen("archivoMaestro.dat", "wb");
    NodoFinal* aux = lista;
    while(aux != NULL){
        Final datos = aux->info;
        fwrite();
    }
}