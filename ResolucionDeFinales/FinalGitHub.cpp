#include<iostream>

using namespace std;

typedef int cantPaisesMaximo;
cantPaisesMaximo cantPaises = 200;

struct casos {
    int cantCasos[12];
    char tipoDeCaso; // H -> Hisopados / I -> Infectados / R -> Recuperados
};


struct MAX_PAIS {
    char nombrePais[50];
    int cantHabitantes;
    casos casos[3];
};

MAX_PAIS paises[cantPaises];

struct registroArchivo{
    char nombrePais[50];
    int numeroDeMes;
    int numeroDelDia;
    int cantCasos;
    char tipoDeCaso; // H -> Hisopados / I -> Infectados / R -> Recuperados
}; // Para leer los registros de un archivo

/*
    Cuento con archivo "ParteDiario.dat"
*/

void Cargar(FILE *, MAX_PAIS[]);
void listar(MAX_PAIS[], char[], int, char);

int main(){
    FILE *f = fopen("ParteDiario.dat", "rt+");
    MAX_PAIS paises[cantPaises];
    Cargar(f, paises);
}

void Cargar(FILE *f, MAX_PAIS paises[]){
    registroArchivo registro;
    int aux;

    while (fread(&registro, sizeof(registro), 1, f)) {
        for (int i = 0; i < 50; i++) {
            if (registro.nombrePais[i] != paises[aux].nombrePais[i]) {
                i=0;
                aux++;
                while (registro.nombrePais[i] != paises[aux].nombrePais[i]) {
                    aux++;
                }
            }   
        }
        if (registro.tipoDeCaso == 'H') {
            paises[aux].casos[0].cantCasos[registro.numeroDeMes] += registro.cantCasos;
            paises[aux].casos[0].tipoDeCaso = registro.tipoDeCaso;
        } else {
            if (registro.tipoDeCaso == 'I') {
                paises[aux].casos[1].cantCasos[registro.numeroDelDia] += registro.cantCasos;
                paises[aux].casos[1].tipoDeCaso = registro.tipoDeCaso;
            } else {
                paises[aux].casos[2].cantCasos[registro.numeroDelDia] += registro.cantCasos;
                paises[aux].casos[2].tipoDeCaso = registro.tipoDeCaso;
            }
        }
    }
}

void listar(MAX_PAIS paises[], char nombrePais[], int mes, char tipoDeCaso){
    // funcionalidad de listar
};