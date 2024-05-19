#include <iostream>

using namespace std;
/*
Punto Teorico
int queQuiereDecir(int x[], int tam){
 if(tam == 1) return x[0]; else return x[tam-1] + queQuiereDecir(x, tam-1 );
};

int main() {
    const int tamArreglo = 10;
    int a[tamArreglo] = {2,3,4,5,6,6,5,4,3,2};
    int resultado = queQuiereDecir(a, tamArreglo);
    cout<< resultado;
    return 0;
}
*/

struct Alumnos{
    int Legajo;
    char ApellidoYNombre[100];
};

Alumnos vecA[60];   //    Ordenados por Legajo
int vecN[60][7];    //    Relacion 1 a 1 con vecA[]
int vecLegajos[60]; //    Vector 1 a 1 con los legajos de los alumnos -> vecA[1] y vecN[1] u vecLegajos[1] corresponden al mismo alumno

char situacionAcademica(int);
void ordenarPorApellido();
void mostrarSituacionAcademica();

int main(){
    ordenarPorApellido();
    vecA[0].ApellidoYNombre[0] = 'F';
    vecA[0].ApellidoYNombre[1] = 'e';
    vecA[0].ApellidoYNombre[2] = 'p';
    vecA[0].ApellidoYNombre[3] = 'M';
    vecA[0].ApellidoYNombre[4] = 'a';
    vecA[0].Legajo = 2098660;
    vecLegajos[0] = 2098660;
    vecN[0][0] = 8;
    vecN[0][1] = 8;
    vecA[1].ApellidoYNombre[0] = 'A';
    vecA[1].ApellidoYNombre[1] = 'p';
    vecA[1].ApellidoYNombre[2] = 'a';
    vecA[1].ApellidoYNombre[3] = 'J';
    vecA[1].ApellidoYNombre[4] = 'u';
    vecA[1].Legajo = 9035667;
    vecLegajos[1] = 9035667;
    vecN[1][0] = 5;
    vecN[1][1] = 8;
    vecN[1][2] = 6;
    mostrarSituacionAcademica();
}

char situacionAcademica(int Legajo){
    if (((vecN[Legajo][0] >= 8 && vecN[Legajo][1] >= 8) || (vecN[Legajo][0] >= 8 && vecN[Legajo][3] >= 8) || (vecN[Legajo][1] >= 8 && vecN[Legajo][2] >= 8) && (vecN[Legajo][6] >= 8))) {
        return 'p';        
    } else {
        if ((vecN[Legajo][0] >= 6 || vecN[Legajo][2] >= 6 || vecN[Legajo][4] >= 6) && (vecN[Legajo][1] >= 6 || vecN[Legajo][3] >= 6 || vecN[Legajo][5] >= 6) && (vecN[Legajo][6] >= 6)){
            return 'r';
        } else {
            return 'n';
        }   
    }
}

void ordenarPorApellido(){
    int aux;
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            if (vecA[j].ApellidoYNombre[0] < vecA[j+1].ApellidoYNombre[0]) {
                aux = vecLegajos[j];
                vecLegajos[j] = vecLegajos[j+1];
                vecLegajos[j+1] = aux;
            }
        }
    }
}

void mostrarSituacionAcademica(){
    int j;
    for (int i = 0; i < 60; i++) {
        while (vecA[j].Legajo != vecLegajos[i]) {
            j++;
        }
        cout << "Numero de Orden: " << i << "\t";
        cout << "Nombre: ";
        for (int m = 0; m < 100; m++) {
            cout << vecA[j].ApellidoYNombre[m];
        }
        cout << "\t";
        if (situacionAcademica(j) == 'p') {
            cout << "Situacion Academica: Promocionado" << endl;
        } else {
            if (situacionAcademica(j) == 'r') {
                cout << "Situacion Academica: Regularizada" << endl;
            } else {
                cout << "Situacion Academica: No Aprovado" << endl;
            }
            
        }
    }
}