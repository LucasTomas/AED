#include <iostream>

using namespace std;

struct vendedor {
    int idV;
    char nombreVendedor[21];
};

struct Modelo {
    char idM[5];
    char descripcion[11];
};

struct Ventas{
    int idV;
    char idM[5];
    int fecha;
    char cliente[21];
};

void crearModelos(){
    FILE *f = fopen("vendedores.txt", "rt+");
    Modelo p = {"AF01", "Auto Rojo"};

    fwrite(&p, sizeof(p), 1, f);
    fclose(f);
}

void crearVendedor(){
    FILE *f = fopen("modelos.txt", "rt+");
    vendedor p = {1, "Mario Casas"};

    fwrite(&p, sizeof(p), 1, f);
    fclose(f);
}

void ventas(){
    FILE *f = fopen("ventas.txt", "rt+");
    Ventas p = {1, "AF01" , 1003 , "Pedro Pascal"};

    fwrite(&p, sizeof(p), 1, f);
    fclose(f);
}

void leer() {
    FILE *f = fopen("ventas.txt", "rt+");
    Ventas p;

    fread(&p, sizeof(p), 1, f);
    cout << p.cliente << endl << p.fecha << endl << p.idM << endl << p.idV;
    fclose(f);
}

int main(){

    void crearModelos();
    void crearVendedores();
    void ventas();
    void leer();
}