/*3. Busca por matrícula
Implemente uma função com retorno que receba o vetor de alunos e um número de matrícula. 
A função deve retornar o índice do aluno, caso encontrado, ou -1, caso contrário.
 No main, permita que o usuário digite uma matrícula e exiba os dados do aluno correspondente.*/
#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#include "tipos.h"
#include "includes.h"

 using namespace std;

#define tam 5

 int main(){
    Aluno vetor[tam];
    lerAlunos(vetor, tam);
    exibirAlunos(vetor, tam);
    
    cout << "digite uma matricula para busca: " << endl;
    int matricula;
    cin >> (matricula);

    int indice = exibirPorMatricula(vetor, matricula, tam);

    if(indice != -1){
        cout << "Aluno encontrado:\n";
        cout << "Nome: " << vetor[indice].nome << endl;
        cout << "Matricula: " << vetor[indice].matricula << endl;
    } else {
        cout << "Aluno com matricula " << matricula << " nao encontrado" << endl;
    }
    return 0;
 }


 