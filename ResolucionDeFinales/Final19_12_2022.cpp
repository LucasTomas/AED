#include<iostream>

using namespace std;

struct hisopado {
    int DNI;
    char nombreApellido[100];
    int fechaDeNacimiento;  // formato DDMMAAAA
    char domicilio[50];
    char centroDeTesteo[50];
    int tipoDeTest; // 0 -> antigenico y 1 -> PCR
    char obraSocial[50];
    int cantDeDosis;
    int fechaTetativaDeContacto; // formato DDMMAAAA
    bool resultadoTest;
};

struct Paciente {
    int DNI;
    char nombreApellido[100];
    int fechaDeNacimiento;  // formato DDMMAAAA
    char domicilio[50];
};

struct NodoResultadosPositivos {
    int tipoDeTesteo;
    Paciente paciente;
    NodoResultadosPositivos *sgte;
};

struct NodoResultadoNegativos {
    Paciente paciente;
    NodoResultadoNegativos *sgte;
};

struct NodoObraSocial {
    char obraSocial[50];
    int cantTesteos;
    int cantPos;
    int cantNeg;
    NodoResultadoNegativos pacientesNegativos;
    NodoResultadosPositivos pacientesPositivos;
    NodoObraSocial *sgte;
};

void push(NodoResultadosPositivos*&pila, Paciente x, int tipoDeTesteo){
    NodoResultadosPositivos*p = new NodoResultadosPositivos();
    p->tipoDeTesteo = tipoDeTesteo;
    p->paciente.DNI = x.DNI; 
    p->paciente.fechaDeNacimiento = x.fechaDeNacimiento;
    for (int j = 0; j < 50; j++){
        q->paciente.domicilio[j] = x.domicilio[j];
    }
    for (int t = 0; t < 100; j++){
        q->paciente.nombreApellido[t] = x.nombreApellido[t];
    }
    p->sgte = pila; 
    pila = p; 
};

void push(NodoResultadoNegativos*&pila, Paciente x){
    NodoResultadoNegativos*p = new NodoResultadoNegativos();
    p->paciente.DNI = x.DNI; 
    p->paciente.fechaDeNacimiento = x.fechaDeNacimiento;
    for (int j = 0; j < 50; j++){
        q->paciente.domicilio[j] = x.domicilio[j];
    }
    for (int t = 0; t < 100; j++){
        q->paciente.nombreApellido[t] = x.nombreApellido[t];
    }
    p->sgte = pila; 
    pila = p; 
};

Paciente pop(NodoResultadosPositivos*&pila){ 
    Paciente x; 
    NodoResultadosPositivos*p = pila; 
    x = pila->paciente; 
    pila = pila->sgte; 
    delete p;
    return x; 
};

void cargarResultados(FILE *f){
    hisopado registroHisopado;

    NodoResultadoNegativos*p = new NodoResultadoNegativos;
    NodoResultadosPositivos*q = new NodoResultadosPositivos;
    NodoObraSocial *m = new NodoObraSocial; 

    while (fread(&registroHisopado, sizeof(registroHisopado), 1, f)) {
        m = listaObrasSociales;
        Paciente auxPaciente;

        for (int i = 0; i < 50; i++) {
            if (registroHisopado.obraSocial[i] != m->obraSocial[i]) {
                i=0;
                m->sgte;
                while (registroHisopado.obraSocial[i] != m->obraSocial[i]) {
                    m->sgte;
                }
            }
        }

        m->cantTesteos++;

        auxPaciente.DNI = registroHisopado.DNI;
        auxPaciente.fechaDeNacimiento = registroHisopado.fechaDeNacimiento;
        for (int j = 0; j < 50; j++){
            auxPaciente.domicilio[j] = registroHisopado.domicilio[j];
        }
        for (int t = 0; t < 100; j++){
            auxPaciente.nombreApellido[t] = registroHisopado.nombreApellido[t];
        }

        if (registroHisopado.resultadoTest == true) {
            push(m->pacientesPositivos, auxPaciente, registroHisopado.tipoDeTest);
            m->cantPos++;
        } else {
            push(m->pacientesNegativos, auxPaciente);
            m->cantNeg++;
        }
    }
}

void mostrarPorObra (NodoObraSocial *& listado){
    NodoObraSocial*l = new NodoObraSocial;
    int auxP, auxN, auxAp, auxPCRp, auxAn, auxPCRn;
    l = listado;
    cout << "En la Obra Social \'";
    for (int i = 0; i < 50; i++) {
        cout << l->obraSocial[i]
    }
    cout << "\' se hicieron: " << l->cantTesteos << endl;
    while (l->pacientesPositivos->sgte != NULL) {
        if (l->pacientesPositivos->tipoDeTesteo = 0) {
            auxAp++;
        } else {
            auxPCRp++;
        }
        auxP++;
    }
    while (l->pacientesNegativos->sgte != NULL) {
        if (l->pacientesPositivos->tipoDeTesteo = 0) {
            auxAn++;
        } else {
            auxPCRn++;
        }
        auxN++;
    }
    l = listado;
    cout << "Casos Positivos " << l->cantPos << endl;
    cout << "\t "


}

NodoObraSocial listaObrasSociales;
NodoResultadoNegativos resultadosNegativos;

int main(){
    FILE *f = fopen("hisopados.dat", "rt+");
    cargarResultados(f);
}