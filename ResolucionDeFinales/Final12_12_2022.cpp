#include <iostream>
using namespace std;

struct paises{
 char país[61];
 char resultado[4];//0 – octavos; 1 – cuartos; 2 – semifinal; 3 – final. Contenido G si ganó; P si perdió
};
struct partido{
 char país1[61];
 char país2[61];
 int instancia;
 char resultado;//0 – octavos; 1 – cuartos; 2 – semifinal; 3 – final. Contenido G si ganó; P si perdió
};

void asignarResultado(paises [], partido);
void mostrarPaisesPorInstancia(paises []);

/*
struct pLista {
    int nro;
    pLista *sgte;
};

void push(pLista*&pila, int x){

    pLista*p = new pLista();
    p->nro = x;
    p->sgte = pila;
    pila = p;
}

int pop(pLista*&pila){
    int x;
    pLista*p = pila;
    x = pila->nro;
    pila = pila->sgte;
    delete p;
    return x;
}

int sumaLimpia(pLista *& l){
    int x;
    if (l!=NULL) {
        x = l->nro + sumaLimpia(l->sgte);
        delete l;
        l = NULL;
    } else {
        x = 0 ;
    };
    return x;
};

int main() {
    pLista *l=NULL;
    push(l, 3); push(l, 5); push(l, 7); push(l, 11);
    cout<<"Resultado = "<<sumaLimpia(l)<<endl;
    return 0;
}
*/

int main(){
    paises vectorPaises[16];
    partido partido;
    asignarResultado(vectorPaises, partido);
    mostrarPaisesPorInstancia(vectorPaises);
}

void asignarResultado(paises vectorPaises[], partido partido){
    int p1, p2, j;
    for (j = 0; j < 61; j++) {
        if (vectorPaises[p1].país[j] != partido.país1[j]){
            j=0;
            p1++;
            while (vectorPaises[p1].país[j] != partido.país1[j]) {
                p1++;
            }
        }
    }
    for (j = 0; j < 61; j++) {
        if (vectorPaises[p2].país[j] != partido.país1[j]){
            j=0;
            p2++;
            while (vectorPaises[p2].país[j] != partido.país1[j]) {
                p2++;
            }
        }
    }

    if (partido.resultado == 'G'){
        vectorPaises[p1].resultado[partido.instancia] = 'G';
        vectorPaises[p2].resultado[partido.instancia] = 'P';
    } else {
        vectorPaises[p2].resultado[partido.instancia] = 'G';
        vectorPaises[p1].resultado[partido.instancia] = 'P';
    }
}

void mostrarPaisesPorInstancia(paises vectorPaises[]){
    cout << endl << "Los paises que jugaron cuartos fueron : ";
    for (int i = 0; i < 16; i++){
        if (vectorPaises[i].resultado[1] != '\n') {
            for (int j = 0; j < 61; j++) {
                cout << vectorPaises[i].país[j];
            }
            cout << " - ";
        }       
    }
    cout << endl << "Los paises que jugaron semis fueron : ";
    for (int i = 0; i < 16; i++){
        if (vectorPaises[i].resultado[2] != '\n') {
            for (int j = 0; j < 61; j++) {
                cout << vectorPaises[i].país[j];
            }
            cout << " - ";
        }       
    }
    cout << endl << "Los paises que jugaron la final fueron : ";
    for (int i = 0; i < 16; i++){
        if (vectorPaises[i].resultado[3] != '\n') {
            for (int j = 0; j < 61; j++) {
                cout << vectorPaises[i].país[j];
            }
            cout << " - ";
        }       
    }
}