#include <string>
#include <iostream>
#include <cctype>
#include <fstream>
#include <sstream>
#include <filesystem> // C++17
#define TAM 1000

using namespace std;

#include "../uteis.h"

int main() {

    string listaNomes[TAM];
    string nomeBaseDados = "base.dat";
    int quantidadeNomes = conectarBase(listaNomes, nomeBaseDados, TAM);
    //ao iniciar, conectar com a base do file de origem


    //listar nomes ja cadastrados

    if(quantidadeNomes > 0){
        exibirListaNomes(listaNomes, quantidadeNomes);
    }
    int quantidadeNomes = conectarBase(listaNomes, nomeBaseDados, TAM);
    
	if (existeArquivo(nomeArquivo)) {
		cout << "Programa vai encerrar para nao apagar o arquivo....\n";
		exit(0);
	}
    //abrir arquivo para escrita
	ofstream procuradorArquivo; //tipo de arquivo para escrita do ZERO
    procuradorArquivo.open(nomeBaseDados, ios::out | ios::app); 
 
	string nome;
	while (true) {
		cout << "Digite um nome para guardar no arquivo ou fim para encerrar: ";
		getline(cin,nome);
		fflush(stdin);

		nome = paraMaiusculo(nome);
		if (nome == "FIM"){
			break;
		}

        bool conseguiuInserir = inserirLista(nome, listaNomes, &quantidadeNomes, TAM);//passa o endereço da variavel de nomes

      
        if(conseguiuInserir){
        procuradorArquivo << "\n" << nome << endl;
	}else {
        cout << "nome ja cadastrado..." << endl;
    }

    //ordenar este codigo de arquivos e colocar o restante em um metodo
	procuradorArquivo.close();
    return 1;
}
