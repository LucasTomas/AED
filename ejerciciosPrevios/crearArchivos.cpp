#include<iostream>

using namespace std;

struct fecha{
    int dia;
    int mes;
    int anio;
};

struct reservasCatalogadas{
    char zona;
    fecha diaReserva;
    int cantReservas;
};

int main(){
    FILE *m = fopen("reservasCatalogadas.txt", "rb+");
    reservasCatalogadas a =  {'A', {29,12,23}, 22}, b = {'A', {13,02,23}, 5}, c = {'M', {19,05,23}, 8}, d = {'M', {10,10,23}, 17},t,l;
    int aux;

    fwrite(&a, sizeof(a), 1, m);
    fwrite(&b, sizeof(b), 1, m);
    fwrite(&c, sizeof(c), 1, m);
    fwrite(&d, sizeof(d), 1, m);

    fclose(m);
}