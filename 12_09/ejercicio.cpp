#include <iostream>

using namespace std;

struct vendedor {
    int idV;
    char nombreVendedor[21];
};

struct modelo {
    char idM[5];
    char descripcion[11];
};

struct venta{
    int idV;
    char idM[5];
    int fecha;
    char cliente[21];
};

// Declaracion de variables globales
vendedor vendedores[10];
modelo modelos[15];

// Declaracion de apertura de archivos
FILE * vendedorFile = fopen("vendedores.dat", "rb+");
FILE * modelosFile = fopen("modelos.dat", "rb+");
FILE * ventasFile = fopen("ventas.dat", "rb+");

// Declaracion de funciones auxiliares:
void cargasVendedores(vendedor vendedores[]);
void cargarModelos(modelo modelos[]);
int  buscarModelo(modelo modelos[], char idModelo[5]);
void imprimirListado(FILE * ventasFile, vendedor vendedores[], modelo modelos[]);

int main(){

}

void cargasVendedores(vendedor vendedores[]){
    vendedor ven;
    int i;
    for (i = 0; i < 10; i++) {
        fread(&ven, sizeof(ven), 1, vendedorFile);
        vendedores[i-1] = ven;
    }
}

void cargasModelos(modelo modelos[]){
    fread(modelos, sizeof(modelos), 15, modelosFile);
}

int buscarModelo(modelo modelos[], char idModelo[5]){
    int j = 0;
    while((j < 15) && (modelos[j].idM != idModelo)) {

    }
}

void imprimirListado(FILE * ventasFile, vendedor vendedores[], modelo modelos[]){
    venta ventaRegistros;
    int i, j, k=0;

    while (fread(&ventaRegistros, sizeof(ventaRegistros), 1, ventasFile)){
        i = buscarModelo(modelos, ventaRegistros.idM);
        j = ventaRegistros.idV-1;
        k++;
        cout << k << "  " << ventaRegistros.cliente << "  " << modelos[i].descripcion << "  " << vendedores[j].nombreVendedor << endl;
    }
    
}