#include <iostream>
using namespace std;

struct Factura{
    int id{};
    int fecha{};
    int monto{};
};

int calcularTotal(Factura listaDeFacturas[]){
    int i = 0;
    int total = 0;
    while(i < sizeof(listaDeFacturas)){
        total =+ listaDeFacturas[i].monto;
        i++;
    }
}