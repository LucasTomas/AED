#include <iostream>
#include <stdio.h>
using namespace std;

struct Nodo {
	exEmpleado info;
	Nodo* sig;
};

struct Empleado {
	int nLegajo; //número de lejago para identificar a cada empleado
	char nombres[50];
	char apellidos[50];
	long dni;
	int edad;
	int objetivos_logrados; //este año
	bool recibeBono = false;
};

struct exEmpleado {
	int nLegajo;
	int fechaBaja; // AAAAMMDD
};

Nodo buscarBaja(Nodo* listaBajas, int nLegajo){
	Nodo* aux = listaBajas;
	
	while (aux != nullptr) {
		if (aux->info.nLegajo == nLegajo) {
			return aux;
		}
		else {
			aux = aux->sig;
		}
	}
	
	return NULL;
}

void agregarBaja(Nodo* &listaBajas, int nLegajo, int fechaBaja) {
	// debe pasarse la lista por referencia para poder modificar el puntero de la lista en caso de tener que ponerlo en la primera posicion
	Nodo* actual = listaBajas;
	Nodo* anterior = nullptr;
	
	Nodo* baja = new Nodo();
	baja->info.nLegajo = nLegajo;
	baja->info.fechaBaja = fechaBaja;
	baja->sig = nullptr;
	
	while (actual != nullptr) {
		
		if (actual->info.nLegajo > nLegajo) {
			
			baja->sig = actual;
			
			if (anterior != nullptr) {
				anterior->sig = baja;
			}
			else {
				listaBajas = baja;
			}
			
			return;
		}
		anterior = actual;
		actual = actual->sig;	
	}
	
	anterior->sig = baja;
	return;
}

void pagarBono(char arch_empleados[], Nodo* listaBajas) {
	FILE* archivoEmpleados = fopen(arch_empleados, "rb+");
	Empleado registro;
	while (fread(&registro, sizeof(registro), 1, archivoEmpleados)) {
		
		if (!registro.recibeBono && registro.objetivos_logrados >= 5 && buscarBaja(listaBajas, registro.nLegajo) == NULL) {
			
			registro.recibeBono = true;
			fseek(archivoEmpleados, sizeof(registro) * (-1), SEEK_CUR);
			fwrite(&registro, sizeof(registro), 1, archivoEmpleados);
			
		}	
	}
	
	fclose(archivoEmpleados);
	return;
}

int main() {
		
	return 0;
}
