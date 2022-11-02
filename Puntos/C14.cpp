#include <iostream>
#include <cassert>
#include <cmath>

// Tipo de dato: Punto
struct Punto{double x,y;};
// Distancia R²XR² ---> R / d(punto1, punto2) = |punto2 - punto1|
double distancia(Punto, Punto);
// Donde Esta R² ---> N / d(punto(x,y))= { 0            si x=0&&y=0
//                                       { 1            si x>0&&y>0
//                                       { 2            si x<0&&y>0 
//                                       { 3            si x<0&&y<0
//                                       { 4            si x>0&&y<0
//                                       { 5            si x=0&&y!=0
//                                       { 6            si x!=0&&y=0
enum struct Lugar{origen, cuadrante1,cuadrante2, cuadrante3, cuadrante4, ejeY, ejeX};
Lugar dondeEsta(Punto);
bool AreNear(double, double, double = 0.001);

int main(){
assert(AreNear(distancia({1,-2},{1,2}),4));
assert(AreNear(distancia({1,2},{1,-2}),4));
assert(AreNear(distancia({5,0},{0,9}),10.3,0.2));
assert(AreNear(distancia({-1,2},{-1,-2}),4));
assert(AreNear(distancia({1,2},{-1,2}),2));
assert(AreNear(distancia({1,-2},{-1,-2}),2));
assert(AreNear(distancia({1,-2},{-1,2}),4.5,0.05));
assert(AreNear(distancia(Punto{0.6,0.4},Punto{0.6,0.6}),0.5));
assert(dondeEsta({1,-2})==Lugar::cuadrante4);
assert(dondeEsta({1,2})==Lugar::cuadrante1);
assert(dondeEsta({0,0})==Lugar::origen);
assert(dondeEsta({5,0})==Lugar::ejeX);
assert(dondeEsta({0,9})==Lugar::ejeY);
assert(dondeEsta({-1,2})==Lugar::cuadrante2);
assert(dondeEsta({-1,-2})==Lugar::cuadrante3);


std::cout<<"ok";
}

bool AreNear(double c, double d, double e){return abs(c - d) <= abs(e);}

double distancia(Punto a, Punto b){
    return sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2));
}

Lugar dondeEsta(Punto f){
    return  AreNear(f.x,0)&&AreNear(f.y,0)? Lugar::origen: 
            AreNear(f.x,0)? Lugar::ejeY: 
            AreNear(f.y,0)? Lugar::ejeX: 
            f.x>0&&f.y>0? Lugar::cuadrante1: 
            f.x<0&&f.y>0? Lugar::cuadrante2: 
            f.x<0&&f.y<0? Lugar::cuadrante3: Lugar::cuadrante4;
}