#include <string>
#include <iostream>
#include <cctype>
#include <fstream>
#include <sstream>
#include <filesystem> // C++17

using namespace std;

#include "uteis.h"

int main() {
    //solicita pro usuario nome do arquivo origem
    string nomeArquivo;
	cout << "Informe nome do novo arquivo que recebera os nomes: ";
	cin >> nomeArquivo;
	fflush(stdin);
	//testar se o arquivo existe
    
	if (arquivoExiste(nomeArquivo)) {
		cout << "Programa vai encerrar para nao apagar o arquivo....\n";
		exit(0);
	}
    //abrir arquivo para escrita
	ofstream procuradorArquivo; //tipo de arquivo para escrita do ZERO
    procuradorArquivo.open(nomeArquivo); 
 
	string nome;
	while (true) {
		cout << "Digite um nome para guardar no arquivo ou fim para encerrar: \n";
		getline(cin,nome);
		fflush(stdin);

		nome = paraMaiusculo(nome);
		if (nome == "FIM"){
			break;
		}
		procuradorArquivo << nome << endl;
	}
	procuradorArquivo.close();
    return 1;
}
