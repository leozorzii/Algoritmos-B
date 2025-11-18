#include <iostream>
#include <string>
#include <fstream>
#define TAM 1000
using namespace std;

#include"uteis16.h"

//CRUD COM ARQUIVO

int main(){
Jogador vetor[TAM];
    int qtdJogadores = 0;
    string baseDados = "jogadores.csv";
    
     qtdJogadores = conectarBase(baseDados, vetor, TAM);
     menuJogadores(vetor, TAM, qtdJogadores, baseDados);
    
    return 0;


}