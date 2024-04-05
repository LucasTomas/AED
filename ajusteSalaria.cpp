#include <iostream>

using namespace std;

struct empleado
{
    char nombre[40];
    int sueldo;
    int antiguedad;
};

struct Nodo
{
    empleado info;
    Nodo *sgte;
};
/*
Nodo *CargarListaEmpleados(FILE *f){
    empleado registro;
    Nodo *p;
    Nodo *q = new Nodo;


    while (fread(&registro, sizeof(empleado), 1, f)) {
        p = listaDeEmpleados;
        
        while (registro.sueldo <= p->info.sueldo) {
            p = p->sgte;
        }

        q->info.sueldo = registro.sueldo;
        q->info.antiguedad = registro.antiguedad;
        q->info.nombre = registro.nombre;
        q->sgte = p->sgte;
        p->sgte = q;
    }

    return p;
}
*/
Nodo *CargarListaEmpleados(FILE *f){
    empleado registro;
    
    Nodo *p = new Nodo();
    Nodo *q;
    Nodo *m;
    m = p;

    while (fread(&registro, sizeof(empleado), 1, f)) {
        if (p = NULL) {
            p->info.nombre = registro.nombre;
            p->info.antiguedad = registro.antiguedad;
            p->info.sueldo = registro.sueldo;
            p->sgte = NULL;
        } else {
            while (registro.sueldo <= p->info.sueldo) {
                p = p->sgte;
            }
            
            q= new Nodo();
            q->info.sueldo = registro.sueldo;
            q->info.antiguedad = registro.antiguedad;
            q->info.nombre = registro.nombre;
            q->sgte = p->sgte;
            p->sgte = q;
            p = m;
        }
    }

    return m;
}

Nodo* reconocimientoSalarial(Nodo*& listaDeEmpleados ,int P1, int P2, int X1, int X2, int X3, int Años ){
    Nodo *p = listaDeEmpleados;
    Nodo *q;
    Nodo *m;
    q = p;

    while (p != NULL) {
        if (p->info.sueldo < P1) {
            p->info.sueldo *= X1;
        } else {
            if (p->info.sueldo > P2) {
                p->info.sueldo *= X2;
            } else {
                p->info.sueldo *= X3;
            }
            m = new Nodo();
            if (m = NULL) {
                m->info.sueldo = p->info.sueldo;
                m->info.antiguedad = p->info.antiguedad;
                m->info.nombre = p->info.nombre;
                m->sgte = NULL;
                m = q;
            } else {
                while(m != NULL){
                    m->info.sueldo = p->info.sueldo;
                    m->info.antiguedad = p->info.antiguedad;
                    m->info.nombre = p->info.nombre;
                    m->sgte = NULL;
                    m = q;
                }
            }
        }   
    } 
}

int main(){
    FILE *f = fopen("ListadosEmpleados.dat", "rb+");
    CargarListaEmpleados(f);
}