#include <iostream>

using namespace std;

enum Provincia{
    BuenosAires, CABA, Catamarca, Chaco, Chubut, Cordoba, Corrientes, EntreRios, Formosa, Jujuy, LaPampa, Rioja, Mendoza, Misiones, Neuquen, RioNegro, Salta, SanJuan, SanLuis, SantaCruz, SantaFe, SgoEStero, TdelFuego, Tucuman
};

struct archVotos {
    Provincia provincia; 
    int partido;
    int localidad; 
    int padron; 
    int blancos; 
    int impugnados; 
    int listas[5]; 
};

struct matrizVotos{
    int padron; 
    int blancos; 
    int impugnados; 
    int listas[5];
};

struct formulasPresidenciales{
    char nombresYapellidos[30];
};

matrizVotos Votos[24][10][20];

float votosAusentes(archVotos);
float votosEnBlanco(archVotos);
float votosImpugnados(archVotos);

char *presidente(FILE *, FILE *);
void cargarVotos(FILE *);
int gobernador(Provincia);

int main(){
    
    FILE *f = fopen("ArchivoDeVotos.txt", "rt+");
    FILE *q = fopen("ArchivoFormulas.txt", "rt+");
    cout << presidente(f,q);
}


char *presidente(FILE *f, FILE *q){
    archVotos registroVotos;
    formulasPresidenciales registroNombres;
    int vec[5], aux, aux1, aux2, fst = 0, snd = 1;

    while (fread(&registroVotos,sizeof(registroVotos), 1, f)) {
        vec[0] += registroVotos.listas[0];
        vec[1] += registroVotos.listas[1];
        vec[2] += registroVotos.listas[2];
        vec[3] += registroVotos.listas[3];
        vec[4] += registroVotos.listas[4];
        aux += registroVotos.padron;
    }

    for (int i = 0; i < 5; i++) {
        if (vec[fst] > vec[i+1]) {
            fst = fst;
            if(snd > vec[i+1]){
                snd = snd;
            } 
            else{
                snd = i+1;
            }
        } else {
            if (vec[fst] < vec[i+1]) {
                snd = fst;
                fst = i+1;
            } else {
                snd=fst;
            }
        }   
    }
    
    fseek(q, fst * sizeof(registroNombres), SEEK_SET);

    aux1 = 100*(vec[fst]/aux);
    aux2 = 100*(vec[snd]/aux);

    if ((aux1 > 45.0) || (((aux1-aux2) > 10) && (aux1 > 40.0))) {
        fread(&registroNombres, sizeof(registroNombres), 1, q);
        return registroNombres.nombresYapellidos;
    } else {
        return "Hay empate";
    }
};

void cargarVotos(FILE *f){
    archVotos registroVotos;
    
    while (fread(&registroVotos, sizeof(registroVotos), 1, f)) {
        for (int i = 0; i < 5; i++) {
            Votos[registroVotos.provincia][registroVotos.partido][registroVotos.localidad].listas[i] = registroVotos.listas[i];
        }
        Votos[registroVotos.provincia][registroVotos.partido][registroVotos.localidad].blancos = registroVotos.blancos;
        Votos[registroVotos.provincia][registroVotos.partido][registroVotos.localidad].padron = registroVotos.padron;
        Votos[registroVotos.provincia][registroVotos.partido][registroVotos.localidad].impugnados = registroVotos.impugnados;
    }
}

int gobernador(Provincia provincia){
    int vec[5];
    int aux = 0;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            for (int m = 0; m < 5; m++) {
                vec[m] += Votos[provincia][i][j].listas[m];
            }
        }
    }
    
    for (int t = 1; t < 5; t++) {
        if (vec[aux] < vec[t]) 
            aux = t;   
    }
    return aux;
}

// Archivo con registros de votos pro provincia y localidad

// Archivo para comparar el numero de la lista de candidatos con un numero Va a terner como maximo 5 registros, osea uno por cada lista