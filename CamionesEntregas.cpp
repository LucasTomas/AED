#include <iostream>

using namespace std;

struct Nodo{
   Envios info;
   Nodo *sgte;
};

struct data{
   int CP;
   Nodo *frente;
   Nodo *fin;
};

struct Hora {
   int hora;
   int minutos;
};

struct Camiones {
   int idCamion;
   int CP;
};

struct Envios {
   char codigoPaquete[25];
   char direccion[50];
   int CP;
   int idCamion;
   Hora horaEntrega;
};

struct lista {
   data info;
   lista *sgte;
};


lista v[100];

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

Nodo* insertarOrdenadoCamiones(lista*& l, data p){
   lista* nuevo = new lista();
   nuevo.info = v;
   nuevo->sig = NULL;
   lista* ant = NULL;
   lista* actual = l;
   while( actual!=NULL && aux->info<v ) {
      ant = actual;
      actual = actual->sig;
   }
 
 if( ant==NULL )
   l = nuevo;
}

Nodo* insertarOrdenadoEnvios(Nodo*& l, Envios p){
   Nodo* nuevo = new Nodo();
   nuevo->info.CP
   nuevo->sig = NULL;
   Nodo* ant = NULL;
   Nodo* actual = l;
   while( actual!=NULL && aux->info<v ) {
      ant = actual;
      actual = actual->sig;
   }
 
 if( ant==NULL )
   l = nuevo;
}

lista vectorDeListas[100];

//void leerVehiculos(vectorCamiones, FILE *)

void leerVehiculos(void){
   FILE *f = fopen("Camiones.dat", "rb+");
   Camiones registro;
   int i=0;

   while (fread(&registro, sizeof(Camiones), 1, f)) {
      lista p = new Nodo();
      p.CP = registro.CP;
      p.frente = NULL;
      p.fin = NULL;
      insertarOrdenado(v[registro.idCamion], p);
   }
   fclose(f);
}

void cargarPaquete(void){
   FILE *f = fopen("Envios.dat", "rb+");
   Envios registro;
   int i=0;

   while (fread(&registro, sizeof(Envios), 1, f)) {
      Nodo p = new Nodo();
      p.info.codigoPaquete = registro.codigoPaquete;
      p.info.CP = registro.CP;
      p.info.direccion = registro.direccion;
      p.info.horaEntrega.hora = registro.horaEntrega.hora;
      p.info.horaEntrega.minutos = registro.horaEntrega.minutos;
      p.info.idCamion = registro.idCamion;
      
      queue(v[registro.idCamion].frente, v[registro.idCamion].fin);
   }
   fclose(f);
}

void entregarPaquete(int ID, int CP){
   FILE *f = fopen("Camiones.dat", "rb+");
   int i=0;
}

int main(){

}