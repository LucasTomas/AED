#include <iostream>
using namespace std;


struct Nodo{
    int info;
    Nodo *sgte;
};


void push(Nodo*&pila, int x){
    Nodo*p = new Nodo();
    p->info = x; 
    p->sgte = pila; 
    pila = p; 

};

int pop(Nodo*&pila){ 
    int x; 
    Nodo*p = pila; 
    x = pila->info; 
    pila = pila->sgte; 
    delete p;
    return x; 
};

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
};

int unqueue(Nodo*&frente,Nodo*&fin){ 
    Nodo*p = frente; 
    int x = p->info; 
    frente = p->sgte; 

    if (frente ==NULL) {
        fin = NULL;
    }
    
    delete p; 
    return x; 
};


void anidarColas (Nodo*&frenteA, Nodo*&finA, Nodo*&frenteB, Nodo*&finB, Nodo*&frenteAB, Nodo*&finAB) {
    
    while ((frenteA != NULL) && (frenteB != NULL)){
        if (frenteA->info < frenteB->info){
            queue(frenteAB, finAB, frenteA->info);
            unqueue(frenteA, finA);
        } else {
            queue(frenteAB, finAB, frenteB->info);
            unqueue(frenteB, finB);
        }
    }
    
    /*
    Funciona si se le pasan los valores de cada fila
             |             |                            Estos valores son los que necesitas saber
    int vecA[3] = {}, vecB[3] = {}, i = 0, j = 0, t = 0, m=0, n=0, aux1;
    
    while (frenteA != NULL) {
		vecA[i] = unqueue (frenteA, finA);
        i++;
	}
    
    while (frenteB != NULL) {
		vecB[j] = unqueue (frenteB, finB);
        j++;
	}

    aux1 = i + j;

    for (t = 0; t < aux1; t++){
        if ((m != i) && (n != j)) {
            if (vecA[m] < vecB[n]){
                queue(frenteAB, finAB, vecA[m]);
                m++;
            } else {
                queue(frenteAB, finAB, vecB[n]);
                n++;
            }
        } else {
            if (m == i) {
                queue(frenteAB, finAB, vecB[n]);
                n++;
            } else {
                queue(frenteAB, finAB, vecA[m]);
                m++;
            }
        }
    }
    */

	//frenteAB = frenteA;
	//finA->sgte = frenteB;
	//finAB = finB;
	
	frenteA = NULL;
	finA = NULL;
	frenteB = NULL;
	finB = NULL;
};

int main() {
	
	Nodo*frenteA = NULL;
	Nodo*finA = NULL;
	Nodo*frenteB = NULL;
	Nodo*finB = NULL;
	Nodo*frenteAB = NULL;
	Nodo*finAB = NULL;
	
	int x;
	
	//Cargamos los nodos de A
	queue (frenteA, finA, 1);
	queue (frenteB, finB, 4);
    queue (frenteA, finA, 6);
	
	//Cargamos los nodos de B
	queue (frenteB, finB, 3);
	queue (frenteB, finB, 5);
    queue (frenteB, finB, 10);

	anidarColas(frenteA, finA, frenteB, finB, frenteAB, finAB);
	
	while (frenteAB != NULL) {
		x = unqueue (frenteAB, finAB);
		cout<<x<<endl;
	}

	return 0;
}