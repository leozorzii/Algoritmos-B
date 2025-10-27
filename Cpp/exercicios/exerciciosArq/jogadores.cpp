/*8. Sistema de pontuação de jogadores
Crie uma struct Jogador com nome, pontuacao e nivel. Implemente:

Função para cadastrar jogadores em um vetor.
Função para ordenar o vetor por pontuação (usando Bubble Sort ou qualquer algoritmo).
Função que grave o ranking em um arquivo texto.
*/  
#include "tipos.h"
#include "includes.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include<vector>

#define tam 5
using namespace std;

int main(){
    Player vet[tam];
    registerPlayers(vet, tam);

    ordenarPlayers(vet,tam);

     gravarPlayerArquivo(vet,tam);
    return 0;
}