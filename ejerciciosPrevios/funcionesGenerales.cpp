/*
struct Nodo{
    int info;
    Nodo *sgte;
};

struct datoArchivo{
    int dato1;
    int dato2;
};

int vector[10] = {0};
int vectorArchivo[10][10] = {{0;0}};

void push(Nodo*&pila, int x) { 
    Nodo*p = new Nodo(); 
    p->info = x; 
    p->sgte = pila;  
    pila = p; 
};

int pop(Nodo*&pila){ 
    int x; 
    Nodo*p = pila;
    x = pila->info; 
    pila = pila->sgte; 
    delete p; 
    return x; 
};

void queue(Nodo*&frente,Nodo*&fin,int x){ 
    Nodo*p=new Nodo();
    p->info = x;
    p->sgte = NULL; 
    if(frente == NULL) { 
        frente = p; 
    } else { 
        fin->sgte = p; 
    }
    fin = p;
};

int unqueue(Nodo*&frente,Nodo*&fin){ 
    Nodo*p = frente;
    int x = p->info; 
    frente = p->sgte; 

    if (frente ==NULL) {
        fin = NULL; 
    }
    
    delete p;
    return x;
};

void cargarVector(int vec[]){
    for (int j = 0; j < 10; j++){
        cout << "ingrese valor: " << endl;
        cin >> vec[j];
    }
}

int buscarValorVector(int vec[], int valor){
    int aux;
    for (int i = 0; i < 10; i++) {
        if(valor == vec[i])
            aux = i;
    }    
    return aux;
}

void leerArchivoCompleto(FILE *f, int vectorArchivo[][]){
    datoArchivo dato;
    int aux;
    fseek(f, 0, SEEK_SET);
    while (fread(&dato, sizeof(dato), 1, f)){
        vectorArchivo[aux][0] = dato.dato1;
        aux++;
    }
}

void leerArchivoEspecifico(FILE *f) {
    datoArchivo dato;
    fseek(f, 0, SEEK_SET);
    fread(&dato, sizeof(dato), 1, f);
}
*/