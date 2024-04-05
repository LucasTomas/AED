#include<iostream>
#include<fstream>

using namespace std;

struct informacion{
    int codP;
    int Suc;
};

struct NodoLista{
    informacion info;
    NodoLista *sgte;
};

NodoLista* ListaSinRepe(NodoLista lista, informacion registro){

    NodoLista *q = lista;

    while (q != NULL) { 
        if (registro.codP == q->info.codP && registro.Suc == q->info.Suc) { 
            return q; 
        } else {
            q = q->sgte; 
        }
    }

    return insertarAlFinal(lista, registro);
}

int main(){
    informacion registro;
    NodoLista listaLVTA = NULL;
    FILE *f = fopen("fVta.txt", "rt+");

    while (fread(&registro, sizeof(registro), 1, f)) {
        NodoLista* nodoEncontrado = ListaSinRepe(listaLVTA, registro);

        if (nodoEncontrado != NULL) {
            cout << "Venta encontrada o agregada en la lista." << endl;
        }
    }
}