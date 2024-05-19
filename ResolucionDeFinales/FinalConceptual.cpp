#include<iostream>

using namespace std;

struct registrosUnicaModalidad {
    int hora; // formato HHMMSS
    char patente[6];
    int tipoVehiculo[10];
};


struct registroBiModalidad {
    int hora; // formato HHMMSS
    char patente[6];
    int tipoVehiculo[10];
    char modalidad;
};

void apelarArchivos(FILE*, FILE*, FILE*, FILE*, FILE*, FILE*);

int main(){
    FILE *f = fopen("TelePase1.txt", "rt+");
    FILE *q = fopen("TelePase2.txt", "rt+");
    FILE *m = fopen("CobroManual1.txt", "rt+");
    FILE *t = fopen("CobroManual2.txt", "rt+");
    FILE *n = fopen("PagoMixto1.txt", "rt+");
    FILE *l = fopen("PagoMixto2.txt", "rt+");
    
    apelarArchivos(f, q, m, t, n, l);
}

void apelarArchivos(FILE*TelePase1, FILE*TelePase2, FILE*CobroManual1, FILE*CobroManual2, FILE*PagoMixto1, FILE*PagoMixto2){
    registrosUnicaModalidad registroUnico1;
    registrosUnicaModalidad registroUnico2;
    registroBiModalidad registroBi1;
    registroBiModalidad registroBi2;
    FILE *archivoFinal;
    fread(&registroUnico1, sizeof(registroUnico1), 1, TelePase1);
    fread(&registroUnico2, sizeof(registroUnico2), 1, TelePase2);
    while (feof(TelePase1)) {
        if (!feof(TelePase2)) {
            registroBi1.hora = registroUnico1.hora;
            for (int i = 0; i < 6; i++) {
                registroBi1.patente[i] = registroUnico1.patente[i];
            }
            for (int j = 0; j < 10; j++) {
                registroBi1.tipoVehiculo[j] = registroUnico1.tipoVehiculo[j];
            }
            registroBi1.modalidad = 'M';
            fwrite(&registroBi1, sizeof(registroBi1), 1, archivoFinal);
        } else {
            if (registroUnico1.hora < registroUnico2.hora) {
                registroBi1.hora = registroUnico1.hora;
                for (int i = 0; i < 6; i++) {
                    registroBi1.patente[i] = registroUnico1.patente[i];
                }
                for (int j = 0; j < 10; j++) {
                    registroBi1.tipoVehiculo[j] = registroUnico1.tipoVehiculo[j];
                }
                registroBi1.modalidad = 'M';
                fwrite(&registroBi1, sizeof(registroBi1), 1, archivoFinal);
                fread(&registroUnico1, sizeof(registroUnico1), 1, TelePase1);
            } else {
                registroBi1.hora = registroUnico2.hora;
                for (int i = 0; i < 6; i++) {
                    registroBi1.patente[i] = registroUnico2.patente[i];
                }
                for (int j = 0; j < 10; j++) {
                    registroBi1.tipoVehiculo[j] = registroUnico2.tipoVehiculo[j];
                }
                registroBi1.modalidad = 'M';
                fwrite(&registroBi1, sizeof(registroBi1), 1, archivoFinal);
                fread(&registroUnico2, sizeof(registroUnico2), 1, TelePase2);
            }
        }
    }
    if (!feof(TelePase2)) {
        while (fread(&registroUnico2, sizeof(registroUnico2), 1, TelePase2)) {
            registroBi1.hora = registroUnico1.hora;
            for (int i = 0; i < 6; i++) {
                registroBi1.patente[i] = registroUnico1.patente[i];
            }
            for (int j = 0; j < 10; j++) {
                registroBi1.tipoVehiculo[j] = registroUnico1.tipoVehiculo[j];
            }
            registroBi1.modalidad = 'M';
        }
    }
}