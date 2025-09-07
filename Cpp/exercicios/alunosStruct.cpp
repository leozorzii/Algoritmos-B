/*Crie um programa que:
Declare uma variável do tipo Aluno. Peça para o usuário digitar o nome, a matrícula e a nota final deste aluno.
Armazene essas informações na variável criada.
Ao final, exiba na tela todos os dados do aluno que foram cadastrados.
Exercício 1.2: Cadastro de uma Turma (com Vetor)
Crie um programa que:
Declare um vetor de Aluno com capacidade para 5 alunos.
Use um laço de repetição (for) para pedir ao usuário que preencha os dados (nome, matrícula e nota final) dos 5 alunos.
Após preencher todos os dados, use outro laço de repetição para exibir na tela os dados de todos os alunos cadastrados*/
#include <iostream>
#include <string>
#include <ctime>
#include <limits>
 using namespace std;


 int main(){
     typedef struct{
        string nome;
        int matricula;
        float notaFinal;
    }Aluno;
    Aluno turma[5];

   for(int i = 0; i < 5;i++){
    cout << "digite seu nome - aluno("<< i + 1<<"): " << endl;
         cin.ignore();
        getline(cin, turma[i].nome);
        
    
    cout << "digite sua matricula: " << endl;
        cin >> turma[i].matricula;

    cout << "digite sua nota final: " << endl;
        cin >> turma[i].notaFinal;

        
        turma[i].nome;
        turma[i].matricula;
        turma[i].notaFinal;
        
    }
        for(int i = 0; i < 5;i++){
        cout << "-- Dados dos alunos --" << endl;
        cout << "aluno("<< i + 1 <<") " << endl;
        cout << "Nome: " << turma[i].nome << endl;
        cout << "Matricula: " << turma[i].matricula << endl;
        cout << "Nota final: " << turma[i].notaFinal << endl;
        cout << "---------------------" << endl;
        }


        return 0;
 }