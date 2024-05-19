#include<iostream>

using namespace std;

struct NodoCola{
    char nombrePaciente[40];
    NodoCola *sgte;
}

struct NodoLista {
    NodoCola *frente;
    NodoCola *fin;
    NodoLista *sgte;
};

void queue(NodoCola*&frente,NodoCola*&fin, char nombre[40]){ 
    NodoCola*p=new NodoCola(); 
    p->nombrePaciente = nombre; 
    p->sgte = NULL; 
    if(frente == NULL){ 
        frente = p; 
    } else { 
        fin->sgte = p; 

    }
    fin = p; 
};

int unqueue(NodoCola*&frente,NodoCola*&fin){ 
    NodoCola*p = frente; 
    char nombre[40] = p->nombrePaciente; 
    frente = p->sgte; 
    if (frente == NULL) {
        fin = NULL; 
    }
    delete p;
    return nombre;
};

void crearColaPrioridad(NodoLista*&,NodoCola*&, NodoCola*&); // Inicializa la estructura sin elementos según prioridad
void instertarEnPrioridad(NodoCola*&frente, NodoCola*&fin, char nombre[40]); // Añade un elemento según prioridad
char *elementoMinimo(NodoCola*&frente, NodoCola*&fin); // Retorna el elemento de la cola con mas alta prioridad, según cat.
void quitarMinimo(NodoCola*&frente, NodoCola*&fin); // Quita de la cola el elemento con mas alta prioridad
bool colaVacia(NodoCola*&frente, NodoCola*&fin); // Comprueba si una cola determinada no tiene elementoz
bool prioridadVacia(NodoLista*&lista); // Comprueba si todas las colas de la estructura estan vacial

int main(){
    char nombrePaciente[40];
    NodoLista*listaDePrioridad = NULL;
    NodoCola*frenteColaPorPrioidad = NULL;
    NodoCola*finColaPorPrioidad = NULL;
    char *consultaNombrePaciente;
    
    crearColaPrioridad(listaDePrioridad, frenteColaPorPrioidad, finColaPorPrioidad);
    instertarEnPrioridad(frenteColaPorPrioidad, finColaPorPrioidad, nombrePaciente);
    consultaNombrePaciente = elementoMinimo(frenteColaPorPrioidad, finColaPorPrioidad);
    cout << *consultaNombrePaciente;
    quitarMinimo(frenteColaPorPrioidad, finColaPorPrioidad);
    cout << "La cola de prioridad esta " << colaVacia(frenteColaPorPrioidad, finColaPorPrioidad) ? "vacia" : "no esta vacia" << endl;
    cout << "La prioridad esta " << prioridadVacia(listaDePrioridad) ? "vacia" : "no esta vacia" << endl;
    
}

void crearColaPrioridad(NodoLista*&lista,NodoCola*&frente, NodoCola*&fin){
    NodoLista*nuevaLista = new NodoLista();
    nuevaLista->frente = frente;
    nuevaLista->fin = fin;
    nuevaLista->sgte = lista;
    lista = nuevaLista;
}

void instertarEnPrioridad(NodoCola*&frente, NodoCola*&fin, char nombre[40]){
    queue(frente, fin, nombre);
}

char *elementoMinimo(NodoCola*&frente, NodoCola*&fin){
    char nombre[40];
    
    frente->nombrePaciente = nombre;
    return nombre;
}

void quitarMinimo(NodoCola*&frente, NodoCola*&fin){
    unqueue(frente, fin);
}

bool colaVacia(NodoCola*&frente, NodoCola*&fin){
    if (frente->sgte != NULL) {
        return false
    } else {
        if ((frente->sgte == NULL) && (frente->nombrePaciente == fin->nombrePaciente)) {
            return false;
        } else {
            return true;
        }
        
    }
}

bool prioridadVacia(NodoLista*&lista) {
    if((lista ->fin->nombrePaciente == NULL) && (lista->frente->nombrePaciente == NULL)){
        return true;
    } else {
        return false;
    }
}
