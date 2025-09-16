/*2) Contrua um programa(com metodo) que leia n nomes de pessoas completos 
e os adicione em um vetor de n possiçoes em que deve ser armazenado 
nome completo e o sobrenome, usa a seguinte estrutura 

typedef struct{
    string nomeCompleto;
    string sobrenome;
}pessoa;

dica: sera preciso fazer uma função que extraia o sobrenome de um nome completo.*/

#include<iostream>
#include<string>
#include <vector>
#include <limits>
#include <algorithm>
#include <cctype>

using namespace std;

#define TAM 5
 typedef struct{
    string nomeCompleto;
    string sobrenome;
}pessoa;

string extrairSobrenome(string nome){
    string sobrenome;
    size_t pos = nome.find_last_of(' ');
    if(pos != string::npos){
        sobrenome = nome.substr(pos+1);
    }else{
        sobrenome = nome;
    }
    return sobrenome;
}
void lerNomes(pessoa nome[],  int n){
    string nomeCompleto;
    string sobrenome;
    for(int i = 0;i < n;i++){
    cout << "digite seu nome " << i + 1 << endl;
    getline(cin, nomeCompleto);

     sobrenome = extrairSobrenome(nomeCompleto);
     
     vetor[i].nomeCompleto = nomeCompleto;
     vetor[i].sobrenome = sobrenome;
        }
    }

void exibir(pessoa nome[], int n){
    for(int i=0;i<n;i++){
        cout << "nome Completo: " << vetor[i].nomeCompleto << "Sobrenome: " << vetor[i].sobrenome;
    }
}


int main(){

pessoa nome[TAM];
lerNomes(nome, TAM);
exibir(nome, TAM);


    return 1;
}