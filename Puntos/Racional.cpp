#include <iostream>
#include <cassert>

// Tipo de datos : Racional
// Racional = Q = {q=(numerador,denominador)/ numerador, denominador e Z, d =/= 0}
struct Racional{int numerador,denominador;};

bool operable(Racional);
double numeroRacional(Racional);
bool AreNear(double, double, double = 0.001);

int main(){
assert(operable({1,5})==true&&AreNear(numeroRacional({1,5}),0.25));
assert(operable({5,2})==true&&AreNear(numeroRacional({5,2}),2.5));
assert(operable({-3,-8})==true&&AreNear(numeroRacional({-3,-8}),0.375));
assert(operable({-11,-8})==true&&AreNear(numeroRacional({-11,-8}),1.375));
assert(operable({2,-6})==true&&AreNear(numeroRacional({2,-6}),-3));
assert(operable({-9,5})==true&&AreNear(numeroRacional({-9,5}),-1.8));
assert(operable({1,0})==false&&AreNear(numeroRacional({1,0}),0));

std::cout<<"Ok";
}

bool AreNear(double c, double d, double e){return abs(c - d) <= abs(e);}

bool operable(Racional b){
    return b.denominador!=0? true : false;
}

double numeroRacional(Racional b){
    return b.numerador/b.denominador;
}