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
int dondeEsta(Punto);
bool AreNear(double, double, double = 0.001);
enum Lugar{origen, cuadrante1,cuadrante2, cuadrante3, cuadrante4, ejeY, ejeX};

int main(){
Punto u{1,-2};
Punto l{1,2};
Punto o{0,0};
Punto x{5,0};
Punto y{0,9};
Punto m{-1,2};
Punto n{-1,-2};
assert(AreNear(distancia(u,l),4));
assert(AreNear(distancia(l,u),4));
assert(AreNear(distancia(x,y),10.3,0.2));
assert(AreNear(distancia(m,n),4));
assert(AreNear(distancia(l,m),2));
assert(AreNear(distancia(u,n),2));
assert(AreNear(distancia(u,m),4.5,0.05));
assert(AreNear(distancia(Punto{0.6,0.4},Punto{0.6,0.6}),0.5));
assert(dondeEsta(u)==4);
assert(dondeEsta(l)==1);
assert(dondeEsta(o)==0);
assert(dondeEsta(x)==6);
assert(dondeEsta(y)==5);
assert(dondeEsta(m)==2);
assert(dondeEsta(n)==3);


std::cout<<"ok";
}

bool AreNear(double c, double d, double e){return abs(c - d) <= abs(e);}

double distancia(Punto a, Punto b){
    return sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2));
}

int dondeEsta(Punto f){
    return AreNear(f.x,0)&&AreNear(f.y,0)? origen: AreNear(f.x,0)? ejeY: AreNear(f.y,0)? ejeX: f.x>0&&f.y>0? cuadrante1: f.x<0&&f.y>0? cuadrante2: f.x<0&&f.y<0? cuadrante3: f.x>0&&f.y<0?: cuadrante4;
}