/*Questão 1) Construir um programa em que o usuário insira/digite 10 nomes completos de pessoas 
(validar se o nome lido tem duas palavras no mínimo). 
Esses nomes devem ser transformados para maiúsculo e armazenados em um vetor de tamanho 10 (ou TAM 10). 
Ao final, esses nomes devem ser exibidos. Contudo, o programa deve ser composto por métodos (com ou sem retorno).*/
#include <cctype>
#include <fstream>
#include <sstream>
#include <filesystem> 
#include <string>
#include <algorithm>
#include <iostream>
#define tam 10
using namespace std;

int contarPalavras(string nome){
         stringstream contada(nome);
    string palavra;
    int cont = 0;
    while (contada >> palavra) cont++;
    return cont;
}

void lerNomes(string nomes[], int tamanho){
    for(int i=0;i<tamanho;i++){
    do{
        cout << "digite o nome " << i + 1 << ": " << endl;
        getline(cin, nomes[i]);
        if(contarPalavras(nomes[i]) < 2){
            cout << "nome muito curto, digite novamente" << endl;
        }   
        
        }while(contarPalavras(nomes[i]) < 2);
    }
}

void paraMaiusculo(string nomes[]){
    for (int i = 0; i < nomes[i].size(); i++) {
        for(int j=0;i<nomes[i].size();j++){
        nomes[i][j] = toupper(nomes[i][j]);
        }
    }
}
void exibirNomes(string nomes[], int tamanho){
    for(int i=0;i < tamanho;i++){
        cout << "nomes prontos em maiusculo: " <<  endl;
        cout << nomes[i] << endl;
    }
}

int main(){
string nomes[tam];
lerNomes(nomes, tam);
paraMaiusculo(nomes);  
exibirNomes(nomes, tam);
    return 0;
}