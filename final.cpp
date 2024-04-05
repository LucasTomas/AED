#include <iostream>

using namespace std;

struct nodoCola{
    int prioridad;
    char nombreDelPaciente[40];
    nodoCola* sgte;
};


struct colaDePrioridades{
    int nodoCola->prioridad;
    colaDePrioridades *sgte;
};

colaDePrioridades* crearColaPrioridad();

void insertarEnPrioridad(char*, int);

int main(){

}