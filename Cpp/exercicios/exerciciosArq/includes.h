#include "tipos.h"   
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include <algorithm> 
#include<vector>
using namespace std;


void lerAlunos(Aluno vetor[], int tamanho){
    for (int i = 0; i < tamanho; ++i){
        cout << "Nome do Aluno:\n";
        getline(cin, vetor[i].nome);
        while (vetor[i].nome.empty()){
            cout << "Nome vazio. Digite novamente: ";
            getline(cin, vetor[i].nome);
        }

        cout << "Matricula do Aluno:\n";
        while (!(cin >> vetor[i].matricula)){
            cout << "Entrada invalida. Digite um numero para matricula: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        cout << "Nota do aluno:" << endl;
        cin >> vetor[i].nota;
    }
}

void exibirAlunos(const Aluno vetor[], int tamanho){
    cout << "-- A L U N O S --\n";
    for (int i = 0; i < tamanho; ++i){
        cout << "--------------------\n";
        cout << "Aluno " << i+1 << ": " << vetor[i].nome << endl;
        cout << "Matricula: " << vetor[i].matricula << endl;
        cout << "Nota: " << vetor[i].nota << endl;
    }
}

int exibirPorMatricula(const Aluno vetor[], int tamanho, int matricula){
    for (int i = 0; i < tamanho; ++i){
        if (vetor[i].matricula == matricula) return i;
    }
    return -1;
}

double mediaNotas(Aluno vetor[], int tamanho){
    float media=0;
    for(int i=0;i<tamanho;i++){
        media += vetor[i].nota;
    }
    return media/tamanho;
}

void gravarAlunoArquivo(Aluno vetor[],int tamanho){
   //abrir arquivo para escrita
	ofstream procuradorArquivo; 
    //arquivo sendo aberto para append ou inserir no final
    procuradorArquivo.open("alunos.txt", ios::out | ios::app);
    for(int i=0;i<tamanho;i++){
    procuradorArquivo << "\n"<< vetor[i].nome << "," << vetor[i].matricula << ","<< vetor[i].nota << endl;
    }
    cout << "Alunos gravados no arquivo!" << endl;
    procuradorArquivo.close();

}

    string lerArquivosParaString(string nomearquivo){
       ifstream procuradorArquivo; //procurador
    procuradorArquivo.open("alunos.txt");//ta representado em memoria ram
    
    string resposta = "";
    string linha;
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		resposta = resposta + linha + "\n";
    } 
    procuradorArquivo.close();
    cout << "---------" << endl;
    cout << "Lista de alunos" << endl;

    return resposta;
}

// Players Metods

void registerPlayers(Player vet[], int tamanho){
    cout << "P L A Y E R   A T R I B U T E S" << endl;
    for (int i = 0; i < tamanho; ++i){
            cout << "username: ";
                getline(cin, vet[i].username);

            while (vet[i].username.empty()){
            cout << "username vazio. Digite novamente: ";
                getline(cin, vet[i].username);
        }

            cout << "score: ";
            while (!(cin >> vet[i].score)){
            cout << "Entrada invalida. Digite um numero para score: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

            cout << "level: ";
            while (!(cin >> vet[i].level)){
            cout << "Entrada invalida. Digite um numero para level: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

    void ordenarPlayers(Player vetor[], int tam){
         sort(vetor, vetor + tam, [](const Player& a, const Player& b){
        if (a.score != b.score) return a.score > b.score;     // maior score primeiro
        if (a.level != b.level) return a.level > b.level;     // maior level desempata
        return a.username < b.username;                       // ordem alfabética
        });
    }

    void gravarPlayerArquivo(Player vetor[],int tam){
    //abrir arquivo para escrita
	ofstream procuradorArquivo; 
    //arquivo sendo aberto para append ou inserir no final
    procuradorArquivo.open("ranking.txt", ios::out | ios::app);
    for(int i=0;i<tam;i++){
    procuradorArquivo << "\n"<< vetor[i].username << "," << vetor[i].score << ","<< vetor[i].level << endl;
    }
    cout << "Players gravados no arquivo!" << endl;
    procuradorArquivo.close();
 }