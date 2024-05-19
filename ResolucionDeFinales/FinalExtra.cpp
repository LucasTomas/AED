#include<iostream>

using namespace std;

struct Nodo {
    int info;
    Nodo*sgte;
};

struct ultimasTrasacciones {
    int numeroCuenta;
    int monto;
    ultimasTrasacciones*sgte;
};


struct Saldos {
    int numeroCuenta;
    int cantTransacciones;
    int saldo;
};

void proc(int v[], int len) {
    *v=10;
}

Nodo*interseccionListas(Nodo*&, Nodo*&);
void actualizarSaldos(Saldos [], ultimasTrasacciones*&);

int pop(Nodo *&pila){
    Nodo *aux = pila;   //Copio la pila en un nodo auxiliar
    int x;
    pila = aux -> sgte;
    x = aux -> info;
    delete aux;
    return x;
}

int main(){
    /*
    int *p = NULL; // se inicia un puntero a un entero
    int x = 30; // se inicia una variable x con el valor de 30
    p = new int[3]; // se determina que p va a un puntero al primer elemento de un vector de enteros
    p[1] = x; // determina que el segundo valor va a ser 30
    proc(p,3); // se llama a la funcion que hara que el primer valor va a ser 10
    p[2] = *(p+1)+x; // suma el puntero al segundo elemento es lo mismo que llamar a p[1] que es 30 y se le suma x que es 30
    for (int i = 0; i < 3; i++) {
        cout << *(p+i) << endl;
    }
    delete []p;
    return 0;
    Da 10   30  60
    */ 
   /*
   int *p;
   int x=10;
   p = new int[10];
   p[0] = 20;
   p[1] = 21;
   p[2] = *p; //p apunta al primer valor del vector por ende es igual a 20
   p[3] = *(p+1); // p+1 apunta al segundo valor por ende es igual a 21
   p[4] = *p + *(p+1); // suma el primer valor al vector y el su segundo valor
   cout << *(p+4) << endl; 
   return 0; 
   Da 41
   */
   // No es la manera correcta de pasarlo, se pasa o int v[] o se pasa int *v
   // Se pueden aparear tanto las listas como los vectores
}

void actualizarSaldos(Saldos vectorSaldos[], ultimasTrasacciones*&listaTransacciones){
    ultimasTrasacciones*aux = listaTransacciones;
    int auxVS;
    while (aux->sgte != NULL){
        for (int i = 0; i < 150; i++) {
            if (aux->numeroCuenta != vectorSaldos[i].numeroCuenta){
                auxVS++;
            }
        }
        vectorSaldos[auxVS].cantTransacciones++;
        vectorSaldos[auxVS].saldo -= aux->monto;
    }
    
}

Nodo*interseccionListas(Nodo*&lista, Nodo*&pila){
    Nodo*listaAnidada = new Nodo();
    Nodo*auxL = lista;
    Nodo*auxP = pila;
    int auxPI;
    while ((auxL->sgte != NULL) || (auxL->sgte != NULL)) {
        if (auxL->info < auxP->info) {
            
        } else {
            auxPI = pop()
        }
    }
    return listaAnidada;
}