#include<iostream>

using namespace std;

struct camion{
	int idCamion;
	int CP;
};

struct envios{
	char codigoPaquete[25];
	char direccion[50];
	int CP;
	int idCamion;
	int HoraEntrega;
};

struct cola{
	envios EN;
	cola *sgt;
	cola *frente;
	cola *fin;
};

struct Nodo{
	camion CA;
	Nodo *sgt;
	cola *queue;
};

Nodo *vecCamiones[100] = {NULL};

void LeerVehiculos(Nodo *&vecCamiones){
	FILE *camiones = fopen("camiones.dat","rb");
	camion C;
	
	while(fread(&C,sizeof(C),1,camiones)){//si lee el archivo 
		Nodo *NVN = new Nodo();
		NVN->CA = C;//creo un nodo con los datos
		NVN->queue = NULL;
		NVN->sgt = NULL;//igualamos la lista y la cola a NULL
		
		vecCamiones[C.idCamion-1] = insertarSinRepetir(vecCamiones[C.idCamion-1],NVN);
	}
	fclose(camiones);
}

void planifiqueEntregas(Nodo *&vecC){
	FILE *envios = fopen("envios.dat","rb");
	envios E;
	
	while(fread(&E,sizeof(E),1,envios)){
		cola *NVN = new cola();
		NVN->EN = E; //cargamos el Nodo con los datos de envios 
		
		
		queue(vecCamiones[E.idCamion-1]->queue->frente,vecCamiones[E.idCamion-1]->queue->fin,NVN);	
	}
	fclose(envios);
}

void entregarPaquete(int id,int CP,Nodo *&vec){
	
	Nodo *aux = buscarEnLista(vec[id-1],CP);
	
	unQueue(aux->queue->frente,aux->queue->fin);
	
}
 