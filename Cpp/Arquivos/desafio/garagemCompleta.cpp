#include <iostream>
#include <string>
#define TAM 1000

using namespace std;

typedef struct{
    string placa;
    string dataEntrada;
}Veiculo;



#include"meusMetodos.h"

int main(){
Veiculo garagem[TAM];
    int qtdCarros = 0;
    string baseDados = "estacionamento.csv";
    
     qtdCarros = conectarBase(baseDados, garagem, TAM);
     menu(garagem, TAM, qtdCarros, baseDados);

    return 1;
}