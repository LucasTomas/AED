#include<iostream>
#include<fstream>

using namespace std;

struct informacion{
    int CodP;
    float Fact;
};

struct Nodolista{
    informacion info;
    Nodolista *sgte;
};

informacion vector[1000];

void Vtas100200(Nodolista listaLVta, informacion vector[]){
    int i;
    Nodolista *p = listaLVta;
    Nodolista *q;
    
    while (p != NULL){
        if ((p->info.Fact >= 100) && (p->info.Fact <= 200)){
            vector[i].CodP = p->info.CodP;
            vector[i].Fact = p->info.Fact;
            i++;
            q = p;
            p = p->sgte;
            delete(q);
        } else {
            p = p->sgte;
        }
    }
}

int main(){
    Nodolista listaLVta = NULL;
    
    Vtas100200(listaLVta, vector);
}