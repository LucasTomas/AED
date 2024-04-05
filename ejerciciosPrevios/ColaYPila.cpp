#include <iostream>

using namespace std;

//declarar el nodo
struct Nodo{
    int info;
    Nodo *sgte;
};

struct tipoInfo{
    int campo1;
    int campo2;
};

struct Nodo1{
    tipoInfo info;
    Nodo1 *sgte;
};

// Declarar las funciones push y pop enteros
void push(Nodo*&pila, int x){

    Nodo*p = new Nodo();
    p->info = x;
    p->sgte = pila;
    pila = p;

}

int pop(Nodo*&pila){
    int x;
    Nodo*p = pila;
    x = pila->info;
    pila = pila->sgte;
    delete p;
    return x;

}

// Declarar las funciones push y pop registros
tipoInfo r1 = {1, 2};
tipoInfo r2 = {3, 4};
tipoInfo r3 = {5, 6};
tipoInfo r4 = {7, 8};
tipoInfo r;

void push(Nodo1*&pilaR, tipoInfo r){

    Nodo1*p = new Nodo1();
    p->info.campo1 = r.campo1;
    p->info.campo2 = r.campo2;
    p->sgte = pilaR;
    pilaR = p;

}

tipoInfo pop(Nodo1*&pilaR){
    tipoInfo rAux;
    Nodo1*p = pilaR;
    rAux.campo1 = pilaR->info.campo1;
    rAux.campo2 = pilaR->info.campo2;
    pilaR = pilaR->sgte;
    delete p;
    return rAux;
}

void queue(Nodo*&frente,Nodo*&fin,int x){
    Nodo*p=new Nodo();
    p->info = x;
    p->sgte = NULL;
    
    if(frente == NULL){
        frente = p;
    } else {
        fin->sgte = p;
    }
    
    fin = p;
}

int unqueue(Nodo*&frente,Nodo*&fin){
    Nodo*p = frente;
    int x = p->info;
    frente = p->sgte;

    if (frente ==NULL) {
        fin = NULL;
    }
    
    delete p;
    return x;
}


//dada una pila y un valor x, colocar el valor x en la 3er posicion de la pila
/*void tercervalor(Nodo*&pila, int x){
    Nodo*aux = NULL;
    int i,a;
    for ( i = 0; i < 2; i++)
    {
        a = pop(pila);
        push(aux,a);
    }
    push(pila,x);
    while (aux !=NULL)
    {
        a = pop(aux);
        push(pila,a);
    }
    

}*/

int main(){
    // Se declaran los valores inciales de punteros y "x"
    int x;
    Nodo*pila = NULL;
    Nodo*frente = NULL;
    Nodo*fin = NULL;

    // Se ingresan valores a la pila
    push(pila,1);
    push(pila,2);
    push(pila,4);
    push(pila,5);
    
    // Se vacia la pila y a medida que se vacia se muestran en pantalla
    cout << "Los valores de la pila son: " << endl;
    while(pila!=NULL){
        x = pop(pila);
        cout<<x<<endl;
    }

    // Se ingresan valores a la cola
    queue(frente,fin,1);
    queue(frente,fin,2);
    queue(frente,fin,3);
    queue(frente,fin,4);
    queue(frente,fin,5);

    // Se vacia la cola y a medida que se vacia se muestran en pantalla
    cout << "Los valores de la cola son: " << endl;
    while (frente!=NULL)
    {
        x = unqueue(frente,fin);
        cout<<x<<endl;
    }

    /*
        Consigna:
            Dadas dos colas, cola A y cola B de enteros ordenadas de forma creciente. desarrolar una funcion que aparee(las mezcle) las mismas y las muestre 

    */
}