#include <iostream>
#include <string>
#define TAM 1000

using namespace std;

#include"meusTipos.h"
#include"meusMetodos.h"

int main(){
Veiculo garagem[TAM];
    int qtdCarros = 0;
    string baseDados = "garagem.csv";
    
     qtdCarros = conectarBaseVeiculos(baseDados, garagem, TAM);
     menuVeiculos(garagem, TAM, qtdCarros, baseDados);

    return 1;
}