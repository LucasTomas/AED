#include<iostream>

using namespace std;

struct Electrodomestico {
	char codigoElectrodomestico[6 + 1];
	char nombreElectrodomestico[250 + 1];
	float precioUnitario;
};

struct Venta {
	char codigoElectrodomestico[6 + 1];
	int diaDelMes; // valores entre 1 y 31
	int cantidadVendida;
	int dniCliente;
	char nombreCliente[100 + 1];
};

struct Nodo {
    int dniCliente;
    char nombreCliente[101];
    Nodo *sgte;
};

struct matriz {
    int cantidad;
    Nodo Lista;
};

Electrodomestico detalleElectrodomesticos[2500];
matriz matrizDeElectrodomesticos[31][2500];

int obtenerPosFilaEnMatriz(int diaDelMes){
    return diaDelMes-1;
} 

int obtenerPosColumnaEnMatriz(Electrodomestico electrodomesticos[], char codigoElectrodomestico[6 + 1]) {
    int i;
    for (int j = 0; j < 6; j++) {
        if (electrodomesticos[i].codigoElectrodomestico[j] != codigoElectrodomestico[j]) {
            j=0;
            i++;
            while (electrodomesticos[i].codigoElectrodomestico[j] != codigoElectrodomestico[j] ) {
                i++;
            }
        }
    }
    return i;
}

void cargarMatriz(FILE *f, Electrodomestico electrodomesticos[], matriz matrizDeElectrodomesticos[]){
    
    Venta registro;
    int auxDia, auxCodigo;
    
    while (fread(&registro, sizeof(Venta), 1, f)) {
        auxDia = obtenerPosFilaEnMatriz(registro.diaDelMes);
        auxCodigo = obtenerPosColumnaEnMatriz(detalleElectrodomesticos,registro.codigoElectrodomestico);
        matrizDeElectrodomesticos[auxDia][auxCodigo].cantidad += registro.cantidadVendida;
        matrizDeElectrodomesticos[auxDia][auxCodigo].Lista->dniCliente = registro.dniCliente;
        for (int i = 0; i < 100; i++) {
            matrizDeElectrodomesticos[auxDia][auxCodigo].Lista->nombreCliente[i] = registro.nombreCliente[i];
        }
        matrizDeElectrodomesticos[auxDia][auxCodigo].Lista->sgte = NULL;
        matrizDeElectrodomesticos[auxDia][auxCodigo].Lista = registro;
    }   
}

void mostrarCliente(matriz matrizDeElectrodomesticos[], int diaDelMes, int numeroElectrodomesticoOrden){
    cout << "La cantidad de electrodomesticos vendidos fue :" << matrizDeElectrodomesticos[diaDelMes][numeroElectrodomesticoOrden].cantidad << endl << "Los DNI de los que compraron dichos Elecrodomesticos fueron: " << endl;
    while (matrizDeElectrodomesticos[diaDelMes][numeroElectrodomesticoOrden].Lista->sgte != NULL) {
        cout << "DNI : " << matrizDeElectrodomesticos[diaDelMes][numeroElectrodomesticoOrden].Lista->dniCliente;
    }
}

int main(){
    FILE *f = fopen("ventas.dat", "rt+");

}