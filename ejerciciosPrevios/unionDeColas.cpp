#include <iostream>
using namespace std;

/*Desarrollar un programa que reciba los punteros de 2 colas: cola a y cola b y que genere una cola a,b en los que primero esten los nodos de la cola a 
y en la continuacion los de la cola b*/

//Declaracion de la estructura del NODO.
struct Nodo{
    int info;
    Nodo *sgte;
};
//Desarrollo de las funciones de pila y cola con datos simples

void push(Nodo*&pila, int x){ //Carga un nodo al tope de la pila. (pila de enteros y el valor "x" lo pone en la 1era posicion)
// Se pasa el puntero a la pila por referencia y el nodo creado siempre modifica el valor de la pila. 
    Nodo*p = new Nodo(); //Se utiliza un puntero auxiliar "p" para crear un nuevo nodo a traves de "new".
    p->info = x; //Se almacena el valor "x" en el campo "info" del nodo recien creado que esta apuntado por "p".
    p->sgte = pila; //El campo "sgte" de "p" apunta al que era primero antes y la direccion esta en pila. 
    pila = p; // pila debe apuntar a p y es este el nuevo primero y por la linea anterior pasa a ser segundo el que era primero antes

};

int pop(Nodo*&pila){ //Esta funcion elimina el primer nodo de la pila y retorna el valor almacenado en ese nodo (en este caso un entero)
    int x; //Se declara un entero para contener el valor que esta en el campo de la informacion del primer nodo
    Nodo*p = pila; //Se declara un puntero "p" y se lo hace apuntar al comienzo de la pila para luego eliminar este nodo
    x = pila->info; //Al entero "x" se le asigna el campo "info" del registro apuntado por "p" que tambien es un entero
    pila = pila->sgte; //El nodo apuntado por "p" lo vamos a eliminar, por lo que la pila tiene que apuntar al nodo que le sigue
    delete p; //Se elimina el nodo apuntado por "p" que es el que era primero antes. La pila se preserva porque en la linea anterior la hicimos avanzar.
    return x; //Retornamos "x" que es el valor que estaba en el primer nodo de la pila. 

};

void queue(Nodo*&frente,Nodo*&fin,int x){ //Cargar nodos en una cola, lo pone despues del ultimo, por lo que tiene referencia al primer nodo con "frente" y al segundo con "fin"
//"frente" es un puntero al comienzo de la cola y "fin" es un puntero al final de la cola. En una cola, el fin siempre se modifica. "Fin" pasa a apuntar simpre al nodo nuevo
//frente se modifica solamente en el caso de que la cola este vacia y se agregue el primer nodo
    Nodo*p=new Nodo(); //Con un puntero auxiliar "p" se crea un nuevo nodo
    p->info = x; //Al campo "info" del registro apuntado por "p" se le agrega el parametro "x"
    p->sgte = NULL; //El "sgte" del registro creado siempre es NULL porque el nodo creado va a ser el ultimo, por lo que no tiene siguiente.
    if(frente == NULL){ //el unico caso en que el "frente" se modifica es cuando la cola esta vacia. Eso se controla si "frente es igual  a NULL
        frente = p; //Si "frente" era NULL, ahora deja de serlo y pasa a apuntar a nodo creado.
    }else{ //En el caso de que la cola no este vacia, se agrega un nodo nuevo despues del ultimo.
        fin->sgte = p; //Como la cola no esta vacia, el "sgte" de "fin" es el nuevo nodo para enlazarlo con la estructura.

    }
    fin = p; //El puntero "fin" apunta al nodo creado porque este va a ser, a partir de ahora, el ultimo.

};

int unqueue(Nodo*&frente,Nodo*&fin){ //Elimina el nodo que esta en la primera posicion de la cola y retorna el valor que esta en el campo "info".
//Los punteros son "frente" y "fin". Como se saca de la primera posicion, el frente siempre se modifica. El fin soo se modifica cuando sacamos el ultimo nodo.
    Nodo*p = frente; //A un puntero auxiliar "p" se le asigna el comienzo de la cola apuntado por "frente"
    int x = p->info; //Declaramos "x" con un tipo de dato igual al campo de la informacion y le asignamos el valor del campo "info" que esta en el primer nodo
    frente = p->sgte; //Como el primer nodo lo vamos a eliminar y lo tenemos apuntado por "p", corremos el "frente" al nodo siguiente

    if (frente ==NULL) //Solo se debe controlar si la queda vacia, es decir, si al avanzar "frente" apunta a NULL
    {
        fin = NULL; //De ocurrir que frente apunta a NULL se debe hacer que fin tambien apunte a NULL
    }
    
    
    delete p; //Borramos la instancia del puntero "p"

    return x; //Retornamos el valor que esta en el primer nodo

};


void unirColas (Nodo*&frenteA, Nodo*&finA, Nodo*&frenteB, Nodo*&finB, Nodo*&frenteAB, Nodo*&finAB) {
	frenteAB = frenteA;
	finA->sgte = frenteB;
	finAB = finB;
	
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
	queue (frenteA, finA, 2);
	queue (frenteA, finA, 3);
	
	//Cargamos los nodos de B
	queue (frenteB, finB, 4);
	queue (frenteB, finB, 5);
	queue (frenteB, finB, 6);
	
	unirColas (frenteA, finA, frenteB, finB, frenteAB, finAB);
	
	while (frenteAB != NULL) {
		x = unqueue (frenteAB, finAB);
		cout<<x<<endl;
	}
	
	
	return 0;
}
