#include <iostream>

using namespace std;

struct acciones{
    int fecha;
    char especie[4];
    int precioMinimo;
    int precioMaximo;
    int cantOperada;
};

struct nodoPorAccion{
    int fecha;
    int precioMinimo;
    int precioMaximo;
    int cantOperada;
    nodoPorAccion *sgte;
};

struct vectorPorAccion{
    char especie[4];
    nodoPorAccion *accion;
};

vectorPorAccion ResumenOperaciones[25];

void agregarOperacion(FILE *f){
    fseek(f, 0, SEEK_SET);

    int i;
    nodoPorAccion *x = NULL;
    acciones *accionArchivo;

    while(fread(&accionArchivo, sizeof(acciones), 1, f)) {
        while (accionArchivo->especie != ResumenOperaciones[i].especie) {
            i++;
        }
        x = new nodoPorAccion;
        x->fecha = accionArchivo->fecha;
        x->precioMaximo = accionArchivo->precioMaximo;
        x->precioMinimo = accionArchivo->precioMinimo;
        x->cantOperada = accionArchivo->cantOperada;
        ResumenOperaciones[i].accion->sgte = x;
        i=0;
    }
}

void Promedio(int especie){
    int contador, aux;
    while (ResumenOperaciones[especie].accion->fecha == ResumenOperaciones[especie].accion->sgte->fecha){
        aux = (ResumenOperaciones[especie].accion->precioMaximo + ResumenOperaciones[especie].accion->precioMaximo) / ResumenOperaciones[especie].accion->cantOperada;
        aux += aux;
    }
    
    cout << "El valor promedio de \"" << ResumenOperaciones[especie].especie << "\" en el dia " << ResumenOperaciones[especie].accion->fecha << " es de $" << aux << endl;
}

int main(){
    
}