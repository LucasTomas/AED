#include <iostream>

using namespace std;

struct nodoActividad
{   
    bool alumno;
    bool docente;
    bool egresado;
    nodoActividad *sgte;
};

struct nodoInstitucion
{   
    bool uPublica;
    bool uPrivada;
    bool iTerceario;
    nodoInstitucion *sgte;
};

struct nodoLenguajes
{   
    bool Python;
    bool C;
    bool Java;
    bool PythonC;
    bool PythonJava;
    bool CJava;
    nodoLenguajes *sgte;
};

struct nodoformulario
{
    nodoActividad *Actividad;
    nodoInstitucion *Institucion;
    nodoLenguajes *Lenguajes;
    nodoformulario *sgte;
};


int main(){

}