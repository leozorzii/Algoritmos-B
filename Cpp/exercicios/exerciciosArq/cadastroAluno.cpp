/*1. Cadastro simples de alunos
Crie uma struct Aluno com os campos: nome, 
matricula e nota. Faça um programa que leia 5 alunos, armazene-os em um vetor de structs e exiba todos na tela.*/
#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#include "includes.h"
#include "tipos.h"
 using namespace std;
    #define tam 5


 int main(){
    Aluno vetor[tam];
    lerAlunos(vetor, tam);
    exibirAlunos(vetor, tam);

    return 0;
 }