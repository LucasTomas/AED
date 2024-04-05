#include <iostream>

using namespace std;

int* retornaVector(int v[]){

    int m[5];

    for (int i = 0; i < 5; i++){
        if ((v[i] % 2) == 0){
            m[i] = 1;
        } else {
            m[i] = 0;
        }
    }
    return m;
}


int main(){

    int vector[5]= {2,25,32,51,50};
    int c[5];

    c = retornaVector(vector);

    for (int i = 0; i < 5; i++){
        if (c[i] == 1) {
            cout << "El valor " << vector[i] << " es multiplo de 2." << endl;
        } else {
            cout << "El valor " << vector[i] << " no es multiplo de 2." << endl;
        }
    }
}