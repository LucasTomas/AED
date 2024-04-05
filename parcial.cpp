#include <iostream>

using namespace std;

/*void funcion(int *x, int pos, int valor){
    *(x+pos) = valor;
    return;
}

int main(){
    int *p = NULL;
    int x[3] = {5,10,15};
    p=x;
    funcion(p, 1, 50);
    for(int i=0; i<3 ; i++)
        cout << x[i] << endl;
    delete(p);
}*/
/*
struct Nodo{
    int info;
    Nodo *sgte;
};

int main(){
    Nodo *p = NULL;
    Nodo *aux;
    p = new Nodo();
    p->info = 15;
    p->sgte = new Nodo();
    p->sgte->info = 20;
    p->sgte->sgte = NULL;
    aux=p->sgte;
    p->sgte = new Nodo();
    p->sgte->info = 90;
    p->sgte->sgte= aux;
    aux = p;
    while (aux){
        cout << aux->info << endl;
        aux = aux->sgte;
    }
}*/

struct Empleado{
	int nLegajo; //número de lejago para identificar a cada empleado
	char nombres[50];
	char apellidos[50];
	long dni;
	int edad;
	int objetivosLogrados; //este año
	bool recibeBono = false;
};

struct Nodo{
    int fecha;
    int nLegajo;
    Nodo *sgte;
};

Nodo *busarBaja(Nodo *listaBajas, int nLegajo);

void pagarBono(char arch_empleados[], Nodo *listaBajas){
    FILE *f = fopen(arch_empleados[], "rb+");
    Empleado auxEmpleado;
    Nodo *auxBusqueda = listaBajas;

    while (fread(&auxEmpleado, sizeof(Empleado), 1, f)){
        if(auxEmpleado.objetivosLogrados >= 5){
            if (buscarBaja(listaBajas, auxEmpleado.nLegajo) == NULL){
                auxEmpleado.recibeBono = true;
                fseek(f, (-1)*sizeof(Empleado), SEEK_CUR);
                fwrite(&auxEmpleado, sizeof(Empleado), 1, f);
            } 
        } 
    }
    fclose(f);
}

void agregarBaja(Nodo *listaBajas, int nLegajo, int fechaBaja){
    Nodo *auxBusqueda = new Nodo();
    auxBusqueda->nLegajo = nLegajo;
    auxBusqueda->fecha = fechaBaja;
    auxBusqueda->sgte = NULL;

    Nodo *anterior = NULL;
    Nodo *actual = listaBajas;

    while( actual!=NULL && aux->info < nLegajo) {
        anterior = actual;
        actual = actual->sgte;
    }
    
    if( anterior==NULL )
        listaBajas = auxBusqueda;
}
