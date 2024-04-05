#include <iostream>

using namespace std;

struct jovenes{
    int edad;
    char datosPersonales[100];
    bool partido[200];
}; // Para leer el archivo binario de jovenes

struct jovenesLista{
    jovenes dato;
    jovenesLista *sgte;
};

struct mentores {
    char datosPersonales[100];
    bool partido[200];
}; // Para leer el archivo binario de mentores

struct mentoresLista{
    mentores dato;
    mentoresLista *sgte;
};

struct carga{
    int partido;
    bool puntoDigital;
    int cantidadDeMentores;
    int cantidadDeInscriptos;
    jovenesLista *listaJovenes;
    mentoresLista *listaMentores;
    carga *sgte;
}

bool partidos[200]; //Vector de dsitritos que indicara con true or false si tiene punto digital

void cargarAlumnasMentoresPorPartido(FILE *f, FILE *q){
    jovenes lecturaJovenes;
    mentores lecturaMentores;
    carga listaACargar = new carga();

    while (fread(&lecturaJovenes, sizeof(lecturaJovenes), 1, f)) {
        if (lecturaJovenes.partido[0] == 0) {
            while (fread(&lecturaMentores, sizeof(lecturaMentores), 1, f)) {
                if (lecturaMentores.partido[0] == 0) {
                    listaACargar.partido = 0;
                }  
            }
        }
    }
    
}

int main(){
    FILE *f = fopen("ArchivoJovenes", "rb+");
    FILE *q = fopen("ArchivoMentores", "rb+");
    cargarAlumnasMentoresPorPartido(f, q); // No paso el vector como referencia debido a que lo declare como variable global
}