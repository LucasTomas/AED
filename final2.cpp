#include <iostream>

using namespace std;

struct sSaldos {
    int nCuenta;
    int cTransacciones;
    float saldo;
};

struct uTransacciones {
    int nCuenta;
    float monto;
    uTransacciones *sgte;
};

sSaldos SALDOS[150];
uTransacciones *m = new uTransacciones;

int main(){
    uTransacciones *p = NULL;
    p=m;
    while (p->sgte != NULL) {
        int i=0;
        while (p->nCuenta != SALDOS[i].nCuenta) {
            i++;
        }
        
        SALDOS[i].saldo -= p->monto;
        SALDOS[i].cTransacciones++;
    }
}

/* 
    Ejercicio 1
void proc (int v[], int len){
    *v=10;
}

int main(){
    int *p = NULL;
    int x = 30;
    p = new int[3];
    p[1] = x;
    proc(p, 3);
    p[2] = *(p+1)+x;
    for (int i = 0; i < 3; i++) {
        cout << *(p+i) << " " << endl;
    }
    delete[]p;
    return 0;
}
*/
/*
    Ejercicio 2
int main(){
    int *p;
    int x = 10;
    p = new int[10];
    p[0] = 20;
    p[1] = 21;
    p[2] = *p; //20
    p[3] = *(p+1);//21
    p[4] = *p + *(p+1); //20+21=41
    cout<<*(p+4)<<endl;
    return 0;
}
*/