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

NodoLista* ListaSinRepe (FILE *f, NodoLista lista){
    informacion registro;
    //NodoLista *p = new NodoLista();
    NodoLista *q = lista;
    
    fread(&registro, sizeof(registro), 1, f); // Leo un registro del archivo 
    
    // Recorro la lista
    while (q != NULL) {
        // Consulto si hay coincidencia entre el registro y la lista
        if (registro.codP == q->info.codP && registro.Suc == q->info.Suc) { 
            // En caso de coincidencia retorna el puntero a dicha posicion
            return q;
        } else {
            // En caso de que no el puntero va al siguiente registro de la list
            q = q->sgte;
        }
    }

    // En caso de que se haya llegado al final se inserta el registro como ultimo valor de la lista

    //  Se puede optar por cargalo manualmente
    //      p->info.codP = registro.codP;
    //      p->info.Suc = registro.Suc;
    //      p->sgte = NULL;
    //      lista->sgte = p;
    //  Al disponer de la funcion insertarFinal, por ende se podria optar por la implementacion de la misma
    return insertarAlFinal(lista, registro);
}

int main(){
    NodoLista listaLVTA = NULL;
    FILE *f = fopen("fVta.txt", "rt+");

    ListaSinRepe(f, listaLVTA);
}