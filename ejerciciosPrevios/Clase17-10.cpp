//Dado un archivo de registros, en el que cada registro contiene las ventas de un mes, el archivo est� 
//desordenado y cada registro tiene el dia de la compra y el importe de la misma
//Se pide un listado ordenado por dia con el total de las compras de cada dia 
#include <iostream>
using namespace std;

//Declarar el tipo registro

struct venta{
	int dia;
	int importe;
};

struct nodo{
	venta info;
	nodo* sgte;
};

nodo* insertarOrdenado(nodo* &lista, venta x){
	nodo*p = new nodo(); 
	p->info = x;
	if (lista==NULL || x.dia < lista->info.dia) { 
		p->sgte = lista;
		lista = p; 
	} else { 
		nodo*q = lista; 
		While (q->sgte != NULL && x.dia > q->sgte->info.dia) {
			q = q->sgte;		
		}
		p->sgte=q->sgte;
		q->sgte=p;
	
	}
	
}


int main{

	FILE* f = fopen("ventas.dat","rb+");
	
	int i,vector[31]={0};
	
	venta r;
	
	nodo* lista=NULL;//inicializar la lista
	
	//cargar el archivo en un vector
	while(fread(&r,sizeof(r),1,f))//lectura registro por registro del archivo
		vector[r.dia]+=r.importe;//carga directa segun el dia acumulando el importe
		
	//mostrar los datos de un vector
	for(i=0;i<31;i++)//Se muestra el contenido del vector, i+1 representa el dia
		cout<< i+1 <<" "<< vector[i] << endl;
		
	//cargar el archivo en una lista ordenada
	fseek(f,0,SEEK_SET); // volver a poner el puntero al archivo en el inicio el mismo
	while(fread(&r,sizeof(r),1,f))
		insertarOrdenado(lista,r);
		
	//mostrar los datos cargados en la lista
	while(lista != NULL){
		r = pop(lista);
		cout<< r.dia << " " << r.importe << endl;
	}
	
	fclose (f);
	
	return 0;
}
//Usamos la estructura auxiliar de 31 posiciones con acceso directo ordenada por un campo

//se dispone de un archivo de reserva de pasajes para los 7 dias de una semana a 10 destinos diferentes
//el archivo contiene el dia de la semana de 0 a 6, los destinos de 1 a 10 y los pasajes reservados
// un dato del tipo entero. se requiere un listado ordenado por dia y destino con el total de las
//reservas.
/*struct reservas{
	int dias;
	int destinos;
	int pasajes;
};
int main{
	
	int matriz[7][10]={{0,0}};//la estructura auxiliar es una matriz porque tiene 2 indices de acceso
	
	FILE* f=fopen("pasajes.dat","rb+");
	
	reservas registro;

	while(fread(&registro,sizeof(registro),1,f))
		matriz[registro.dias][registro.destinos-1] += registro.pasajes;
	
	//for(int i=0;i<7;i++)

	for(int j=0;j<10;j++)
		cout<< i << " " << j << " " << matriz[i][j] << endl;
		//muestra los datos de la matriz recorriendola por fila
		
}*/



