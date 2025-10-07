#include <string>
#include <iostream>
using namespace std;

#include "uteis.h"

int main(){
    string lista[TAM];
    string base = "base.dat";
    int quantidade = cadastrarNomes(base, lista, TAM);
    
    return (quantidade >= 0) ? 0 : 1;

}
