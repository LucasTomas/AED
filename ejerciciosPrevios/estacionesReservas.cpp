#include<iostream>
#include<fstream>

using namespace std;

struct fecha{
    int dia;
    int mes;
    int anio;
};

struct estacionesDelAnio{
    char zona;
    string calificacionTemporada;
    fecha comienzo;
    fecha finalizacion;
};

struct reservasCatalogadas{
    char zona;
    fecha diaReserva;
    int cantReservas;
};

//int crearReserva(FILE *, estacionesDelAnio);
estacionesDelAnio elegirTemporada(char, fecha);
void leerReservas(FILE *);

int main(){
    char zonaE;
    int aux;
    fecha fecha1;
    estacionesDelAnio temporada;
    FILE *f = fopen("reservasCatalogadas.txt", "rt+");

    cout << "Ingrese zona" << endl;
    cin >> zonaE;
    cout << "Ingrese dia:" << endl;
    cin >> fecha1.dia;
    cout << "Ingrese mes:" << endl;
    cin >> fecha1.mes;
    cout << "Ingrese Anio" << endl;
    cin >> fecha1.anio;

    temporada = elegirTemporada(zonaE, fecha1);
    
    cout << "La temporada selecta es: Zona-" << temporada.zona << ". Calificacion-" << temporada.calificacionTemporada << ". Comienzo-" << temporada.comienzo.dia << "/" << temporada.comienzo.mes << "/" << temporada.comienzo.anio << ". Finalizacion-" << temporada.finalizacion.dia << "/" << temporada.finalizacion.mes << "/" << temporada.finalizacion.anio << endl;

    /*aux = crearReserva(f, temporada);
    if (aux == 1){
        cout << "El Archivo se creo correctamente" << endl;
    } else {
        cout << "El Archivo no se pudo crear" << endl;
    }*/
    
    
    leerReservas(f);
}

estacionesDelAnio elegirTemporada(char zonaX, fecha fechaReserva){
    estacionesDelAnio seleccionDeTemp;
    fecha fechaTemp;
    if(zonaX == 'A'){
        if((fechaReserva.mes == 12 && fechaReserva.dia > 20) || fechaReserva.mes == 1 || fechaReserva.mes == 2 || (fechaReserva.mes == 3 && fechaReserva.dia < 21)){
            if(fechaReserva.mes == 12 && fechaReserva.dia > 20){
                seleccionDeTemp = {zonaX, "Alta", {21,12,fechaReserva.anio},{20,3,fechaReserva.anio+1}};
            } else {
                seleccionDeTemp = {zonaX, "Alta", {21,12,fechaReserva.anio-1},{20,3,fechaReserva.anio}};
            }
        } else {
            if((fechaReserva.mes == 3 && fechaReserva.dia > 20) || (fechaReserva.mes <= 8  && fechaReserva.mes >= 4) || (fechaReserva.mes == 9 && fechaReserva.dia < 21)){
                if(fechaReserva. mes == 3 || fechaReserva.mes == 4 || fechaReserva.mes == 5 || (fechaReserva.dia < 21 && fechaReserva.mes == 6)){
                    seleccionDeTemp = {zonaX, "Baja", {21,3,fechaReserva.anio},{20,6,fechaReserva.anio}};
                } else{
                    seleccionDeTemp = {zonaX, "Baja", {21,6,fechaReserva.anio},{20,9,fechaReserva.anio}};
                }
            } else {
                seleccionDeTemp = {zonaX, "Media", {21,9,fechaReserva.anio},{20,12,fechaReserva.anio}};
            }
        }
        
    } else {
        if((fechaReserva.mes == 12 && fechaReserva.dia > 20) || fechaReserva.mes == 1 || fechaReserva.mes == 2 || (fechaReserva.mes == 3 && fechaReserva.dia < 21)){
            if(fechaReserva.mes == 12 && fechaReserva.dia > 20){
                seleccionDeTemp = {zonaX, "Baja", {21,12,fechaReserva.anio},{20,3,fechaReserva.anio+1}};
            } else {
                seleccionDeTemp = {zonaX, "Baja", {21,12,fechaReserva.anio-1},{20,3,fechaReserva.anio}};
            }
        } else {
            if((fechaReserva.mes == 6 && fechaReserva.dia > 20) || fechaReserva.mes == 7 || fechaReserva.mes == 8 || (fechaReserva.mes == 9 && fechaReserva.dia < 21)){
            seleccionDeTemp = {zonaX, "Alta", {21,6,fechaReserva.anio},{20,9,fechaReserva.anio}};
            } else {
                if(3 <= fechaReserva.mes <= 6){
                    seleccionDeTemp = {zonaX, "Media", {21,3,fechaReserva.anio},{20,6,fechaReserva.anio}};
                } else {
                    seleccionDeTemp = {zonaX, "Media", {21,9,fechaReserva.anio},{20,12,fechaReserva.anio}};
                } 
            }
        }
    }

    return seleccionDeTemp;
}

/*crearReserva(FILE *f, estacionesDelAnio temporada){
    
    reservasCatalogadas enviarA;
    int aux, aux1;

    enviarA.zona = temporada.zona;
    enviarA.diaReserva.dia = temporada.comienzo.dia;
    enviarA.diaReserva.mes = temporada.comienzo.mes;

    if(temporada.zona == 'A'){
        fseek(f, 0, SEEK_SET);
        aux = temporada.comienzo.dia * temporada.comienzo.mes;
        fseek(f, aux * sizeof(reservasCatalogadas), SEEK_SET);
        fread(&enviarA, sizeof(enviarA), 1, f);
        enviarA.cantReservas = enviarA.cantReservas + 1;
        fwrite(&enviarA, sizeof(enviarA), 1, f);

        return 1;
    } else {
        fseek(f, 360 * sizeof(enviarA), SEEK_SET);
        aux = temporada.comienzo.dia * temporada.comienzo.mes;
        fseek(f, aux * sizeof(reservasCatalogadas), SEEK_CUR);
        fread(&enviarA, sizeof(enviarA), 1, f);
        enviarA.cantReservas = enviarA.cantReservas + 1;
        fwrite(&enviarA, sizeof(enviarA), 1, f);

        return 1;
    }

    return 0;
}*/

void leerReservas(FILE *f){
    reservasCatalogadas mostrarR;
    fseek(f, 0, SEEK_SET);
    fread(&mostrarR, sizeof(mostrarR), 1, f);
    while((mostrarR.diaReserva.mes < 4 && mostrarR.diaReserva.dia < 21) || (mostrarR.diaReserva.mes == 12 && mostrarR.diaReserva.dia > 20)){
        cout << "Zona: " << mostrarR.zona << endl << "Fecha: " << mostrarR.diaReserva.dia << "/" << mostrarR.diaReserva.mes << endl << "Cantidad de Reservas: " << mostrarR.cantReservas << endl;
        fread(&mostrarR, sizeof(mostrarR), 1, f);
    }
}