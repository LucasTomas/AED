#include<iostream>

using namespace std;

struct paises {
    char paisesOrigen[20];
    paises *sgte;
};

typedef int cantBuzos;
typedef int cantBuceos;

struct buzos {
    char nombreOperadora[20];
    int DNIbuzo;
    int edad;
    char paisOrigen[20];
    int fechaDeSalida; // DDMMAAAA
    char sitioDeBuceo[20];
    char nivelDificultad; // 'A' -> Alta / 'M' -> Media / 'B' -> Baja
    int profundidadMAX;
    int tiempoDeBuceo;
    int horaInicio; // Dice -> Hora y contabiliza de 1hs en 1hs
    buzos *sgte;
};

void cargarEstructura(FILE* ,buzos*&);
void listarEstadisticas(buzos*&);
paises* BuscarEnLista(paises*&, char[]);

int main(){
    FILE *f = fopen("buceosGalapagos2022.dat", "rb+");
    buzos *buzo = new buzos();
    cargarEstructura(f, buzo);
    listarEstadisticas(buzo);
}

void cargarEstructura(FILE* archivoRegistro,buzos*& listaBuzos){
    buzos*registro = new buzos();

    while (fread(&registro, sizeof(registro), 1, archivoRegistro)) {
        if (listaBuzos == NULL) {
            listaBuzos = registro;
        } else {
            registro->sgte = listaBuzos;
            listaBuzos = registro;
        }
    }
}

void listarEstadisticas(buzos*&listaBuzos){
    cantBuzos cantBuzosMas30;
    cantBuceos buceosNocturnos;
    buzos *aux = listaBuzos;
    paises*listadoPaises = new paises();
    paises*aux1 = listadoPaises;

    while (aux->sgte != NULL) {
        
        aux1->paisesOrigen = aux->paisOrigen;
        aux1->sgte = NULL;
        if (BuscarEnLista(listaBuzos,aux->paisOrigen) != NULL) {
            if (listadoPaises == NULL) {
                listadoPaises->paisesOrigen = aux1->paisesOrigen;
            } else {
                aux1->sgte = listadoPaises;
                listadoPaises = aux1;
            }    
        }        

        if (aux->profundidadMAX >= 30){
            cantBuzosMas30++;
        }
        
        if (aux->horaInicio >= 1900); {
            buceosNocturnos++;
        }
    }
    cout << "Los paises de origen de los buzos son: ";
    while (listadoPaises->sgte !=NULL) {
        for (int j = 0; j < 20; j++) {
            cout << listadoPaises->paisesOrigen[j];
        }
        cout << " - ";
    }
    cout << endl << "La cantidad de buzos que nadaron mas de 30 metros fueron : " << cantBuzosMas30 << endl;
    cout << "La cantidad de buceos nocturnos fueron: " << buceosNocturnos << endl;
}

paises* BuscarEnLista(paises *&lista, char pais[]){
    paises* aux = lista;
    while(aux->sgte != NULL){
        for (int i = 0; i < 20; i++) {
            if(aux->paisesOrigen[i] == pais[i]){
                return aux;
            }
        }
        aux = aux->sgte;
    }
    return NULL;
}