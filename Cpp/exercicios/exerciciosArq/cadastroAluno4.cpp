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

    float mediaDasNotas = mediaNotas(vetor, tam);

    cout << "a medias da notas: " << mediaDasNotas << endl;
    
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

    gravarAlunoArquivo(vetor,tam);

    string resultado = lerArquivosParaString("alunos.txt");
    cout << resultado;
    
    return 0;
 }


 