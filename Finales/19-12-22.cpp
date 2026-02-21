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

Nodo* unificarListas(Nodo* &lista1, Nodo* &lista2, int &fecha, int &codMateria, int &curso){
    cout << "Ingresar fecha en formato AAAAMMDD: ";
    cin >> fecha;

    cout << "Ingresar codigo de materia en formato NNNNNN: ";
    cin >> codMateria;

    cout << "Ingresar curso en formato LNNNN: ";
    cin >> curso;

    Nodo* listaNueva = NULL;

    
}


// SUMAMENTE DIFICIL????? FALTA PRACTICA