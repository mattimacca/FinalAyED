#include <iostream>
#include <cassert>
using namespace std;

struct Nodo{
    int dato;
    Nodo* sig;
};

int extraer(Nodo* &cola){
    assert(cola != nullptr);
    Nodo* aux = cola;
    while(aux->sig != NULL){
        aux = aux->sig;
    }
    int valor = aux->dato;
    delete aux;
    return valor;
}

Nodo* unionPilayCola(Nodo* &pila, Nodo* &cola){
    Nodo* listaDeUnion = new Nodo();
    while(pila != NULL){
        int valorDeLaPila = pop(pila);
        insertarOrdenado(valorDeLaPila, listaDeUnion);
    }
    while(cola != NULL){
        int valorDeLaCola = pop(cola);
        insertarOrdenado(valorDeLaCola, listaDeUnion);
    }
}

void insertarOrdenado(int datoAInsertar, Nodo* &lista){
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = datoAInsertar;

    Nodo* actual = lista;
    Nodo* anterior = NULL;

    if(actual == NULL) {
        lista = nuevoNodo;
        return;
    }

    while(actual != NULL and actual->dato < datoAInsertar){
        anterior = actual;
        actual = actual->sig;
    }

    if(anterior == NULL){
        nuevoNodo->sig = actual;
        lista = nuevoNodo;
    }
    else{
        anterior->sig = nuevoNodo;
        nuevoNodo->sig = actual;
    }


}

int pop(Nodo* &pila)
{
	assert(pila != nullptr); //precondición de pop
	int valor = pila->dato;
	Nodo* aux_elim = pila;
	pila = pila->sig;
	delete aux_elim;
	return valor;
}

void eliminarDuplicados(Nodo* &lista){
    Nodo* actual = lista;
    Nodo* anterior = NULL;
    if(actual == NULL) return;
    else if(actual->sig == NULL) return;
    else{
        anterior = actual; // Dejo a anterior en el primer elemento de la lista
        actual = actual->sig;
    }
    while(actual != NULL){
        if(anterior->dato == actual->dato){
            anterior->sig = actual->sig;
            delete actual;
            actual = anterior->sig;
        }
        else{
            anterior = actual;
            actual = actual->sig;
        }
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Cliente {
    int id;
    char nombre[50];
    int cantProductos;
    // Otros datos...
};

struct Caja {
    int numero;
    char nombreCajero[50];
    bool abierta;
    // Otros datos...
};

// NODO DE LA SUBLISTA (La fila de gente)
struct NodoCliente {
    Cliente info;      // <--- Aquí va la entidad Cliente completa
    NodoCliente* sig;  // Puntero al siguiente cliente en la fila
};

// NODO DE LA LISTA PRINCIPAL (Las cajas del súper)
struct NodoCaja {
    Caja info;         // <--- Aquí va la entidad Caja completa
    NodoCliente* fila; // <--- PUNTERO AL INICIO DE LA SUBLISTA (Primer cliente)
    NodoCaja* sig;     // Puntero a la siguiente caja del supermercado
};

int obtenerCajaCliente(NodoCaja* &cajas, int dniCliente){
    NodoCaja* aux = cajas; // Damos por hecho que existen cajas(al menos una)
    while(aux != NULL){
        NodoCliente* clientesCaja = aux->fila;
        while(clientesCaja != NULL){
            if(clientesCaja->info.id == dniCliente) return aux->info.numero;
            else clientesCaja = clientesCaja->sig;
        }
        aux->sig;
    }
    return -1;
}

NodoCliente* sacarClienteDeLaFila(NodoCaja* &cajas, int dniCliente){
    NodoCaja* aux = cajas; // Damos por hecho que existen cajas(al menos una)
    NodoCliente* posteriorEnLaFila = NULL;
    while(aux != NULL){
        NodoCliente* clientesCaja = aux->fila;

        while(clientesCaja != NULL){
            if(clientesCaja->info.id == dniCliente){
                if (posteriorEnLaFila == NULL) {
                    aux->fila = clientesCaja->sig; 
                } 
                else {
                    posteriorEnLaFila->sig = clientesCaja->sig; 
                }

                clientesCaja->sig = NULL; 
                return clientesCaja;
            }
            else{
                posteriorEnLaFila = clientesCaja;
                clientesCaja = clientesCaja->sig;
            }
        }
        aux = aux->sig;
    }
    return;
}

NodoCliente* obtenerUbicacionCliente(NodoCaja* &cajas, int dniCliente){
    NodoCaja* aux = cajas; // Damos por hecho que existen cajas(al menos una)
    while(aux != NULL){
        NodoCliente* clientesCaja = aux->fila;
        while(clientesCaja != NULL){
            if(clientesCaja->info.id == dniCliente) return clientesCaja;
            else clientesCaja = clientesCaja->sig;
        }
        aux = aux->sig;
    }
}

void reunificarFamilia(NodoCaja* &cajas, int dniHijo, int dniMadre){
    NodoCliente* punteroHijo = sacarClienteDeLaFila(cajas, dniHijo);
    NodoCliente* punteroMadre = obtenerUbicacionCliente(cajas, dniMadre);

    punteroHijo->sig = punteroMadre->sig;
    punteroMadre->sig = punteroHijo;

}

// Tu misión:
void separarLista(Nodo* &origen, Nodo* &menores, Nodo* &mayores, int pivote) {
    // Inicializamos las listas destino
    menores = NULL;
    mayores = NULL;
    
    Nodo* ultimoMenor = NULL;
    Nodo* ultimoMayor = NULL;
    
    while (origen != NULL) {
        if(origen->dato > pivote){
            ultimoMayor;
    }
}
