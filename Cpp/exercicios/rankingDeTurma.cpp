/*O Objetivo:
Você tem uma lista de alunos e precisa criar dois relatórios diferentes: um ranking dos alunos pela nota 
(do maior para o menor) e uma lista de chamada em ordem alfabética.

Requisitos:
Crie uma struct chamada Aluno que contenha std::string nome e float notaFinal.
Na sua função main, crie um std::vector<Aluno> e adicione pelo menos 5 alunos com nomes e notas variadas.

Primeiro Relatório:
Crie uma função de comparação para ordenar os alunos pela notaFinal em ordem decrescente.
Use std::sort com essa função para ordenar o vetor.
Imprima a lista ordenada, mostrando o "Ranking da Turma".

Segundo Relatório:
Crie outra função de comparação para ordenar os alunos pelo nome em ordem alfabética (crescente).
Use std::sort novamente com esta segunda função para reordenar o vetor.
Imprima a lista ordenada, mostrando a "Lista de Chamada".*/

#include<iostream>
#include <string>
#include<algorithm>
#include<vector>
#include <functional>

using namespace std;

struct Aluno{
    string nome;
    float notaFinal;
};
        bool compararNotas(const Aluno& a, const Aluno& b){
            return a.notaFinal > b.notaFinal;
    } 
        bool compararNomes(const Aluno& a, const Aluno& b){
            return a.nome < b.nome;
        }

        void imprimirListaAlfabetica(vector<Aluno>& turma){
            sort(turma.begin(), turma.end(), compararNomes);
            for(const auto&  Aluno : turma){
            cout << "Nome: " << Aluno.nome << endl;
            cout << "--------------------------" << endl;
        }
    }


        void mostrarRanking(vector<Aluno>& turma){
            sort(turma.begin(), turma.end(), compararNotas);

        // laco para imprimir o vetor
        for(const auto&  Aluno : turma){
            cout << "Nome: " << Aluno.nome << endl;
            cout << "Nota: " << Aluno.notaFinal << endl;
            cout << "--------------------------" << endl;
        }
    }

int main(){
        vector<Aluno> turma ={
        {"Leonardo" , 9.50f},
        {"Daniel", 10.00f},
        {"Clebs", 4.50f},
        {"Tunico", 6.50f},
        {"Laura", 8.50f}
    };
    //primeiro relatorio
    cout << "--R A K I N G   D E   T U R M A--" << endl;
        mostrarRanking(turma);
    
    //segundo relatorio
    cout << "L I S T A  D E  C H A M A D A" << endl;
    imprimirListaAlfabetica(turma);   

    return 0;
}