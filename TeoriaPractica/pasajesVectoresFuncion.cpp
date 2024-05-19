#include <iostream>

using namespace std;

struct persona{
    int edad;
    int DNI;
};


void mostrar(int *vectorDeEnteros){
    cout << vectorDeEnteros << endl;
    cout << &vectorDeEnteros << endl;
    //cout << &vectorDeEnteros + 1 << endl;
}

void cambiarBusqueda(int &numero){
    numero = 51;
}

int encontrarIndiceR(int *vectorDeEnteros, int valorAEncontrarE){
    int indice = 0;
    while (*vectorDeEnteros != valorAEncontrarE) {
        vectorDeEnteros++;
        indice++;
    }
    return indice;
}

int encontrarIndiceA(int vectorDeEnteros[], int valorAEncontrarE){
    int indice = 0;
    while (vectorDeEnteros[indice] != valorAEncontrarE) {
        indice++;
    }
    return indice;
}

int encontrarEdadS(persona *vectorDePersonas, int valorAEncontrarE){
    while (vectorDePersonas->DNI != valorAEncontrarE) {
        vectorDePersonas++;
    }
    return vectorDePersonas->edad;
}

int *retornarVector(int *vec){
    (*vec)++; // Al valor de la posicion 0 del vector le suma uno
    vec++; // Paso a la siguinte posicion del vector del puntero
    (*vec)++; // Al valor de la posicion 1 del vector le suma uno
    return vec; // retorna el puntero a la segunda posicion del vector
}

int main(){
    int vectorDeEnteros[] = {5,63,28,15,82,51,102};
    persona vectorDePersonas [] = {{18,153153153},{27,426426426},{71, 759759759}};
    int valorAEncontrarE = 82;
    int valorAEncontrarEdad = 426426426;

    mostrar(vectorDeEnteros);
    cambiarBusqueda(valorAEncontrarE);
    cout << encontrarIndiceR(vectorDeEnteros, valorAEncontrarE) << endl;
    cout << encontrarIndiceA(vectorDeEnteros, valorAEncontrarE) << endl;
    cout << encontrarEdadS(vectorDePersonas, valorAEncontrarEdad) << endl; 

    int vectorPruebaRetorno[] = {1,2,3};
    cout << *(retornarVector(vectorPruebaRetorno)) << endl;
    cout << vectorPruebaRetorno[0] << endl;
}