#include <string>
#include <iostream>
#include <cctype>
#include <fstream>
#include <sstream>
#include <filesystem> // C++17

using namespace std;

#include "Cpp\uteis.h"

int main() {
    //solicita pro usuario nome do arquivo origem
    string nomeArquivo;
	cout << "Informe nome do arquivo que recebera os nomes: ";
	cin >> nomeArquivo;
	fflush(stdin);
	//testar se o arquivo existe
    
	if (existeArquivo(nomeArquivo)) {
		cout << "Programa vai encerrar para nao apagar o arquivo....\n";
		exit(0);
	}
    //abrir arquivo para escrita
	//https://www.tutorialspoint.com/cplusplus/cpp_files_streams
	ofstream procuradorArquivo; //tipo de arquivo para escrita do ZERO
    procuradorArquivo.open(nomeArquivo); 
 
	string nome;
	while (true) {
		cout << "Digite um nome para guardar no arquivo ou fim para encerrar: ";
		getline(cin,nome);
		fflush(stdin);

		nome = paraMaiusculoMaiusculo(nome);
		if (nome == "FIM"){
			break;
		}
		procuradorArquivo << nome << endl;
	}
	procuradorArquivo.close();
    return 1;
}
