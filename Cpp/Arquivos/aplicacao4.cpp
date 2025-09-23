/*Construa um programa (com módulo/método) 
que leia n nomes completos de pessoas DE UM ARQUIVO DE ORIGEM e os exiba na tela;*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

    void exibirDaOrigem(string procurarArquivo){
        string nomeArquivo;
	cout << "Informe nome do arquivo que quer exibir na tela: ";
	cin >> nomeArquivo;
    
	ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeArquivo); 

    if (!procuradorArquivo) {
        cout << "Arquivo não localizado. Programa encerrado." << endl;
        exit(0);
    } 
 
   		
	//le o arquivo capturando as frases
	string linha;
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		// procuradorArquivo >> frase; //lendo palavra por palavra da linha 
		cout << linha << endl;
		//tratar a linha e extrair dados dela
	}

	procuradorArquivo.close();
    } 

int main() {
    string nomeArquivo;
    exibirDaOrigem(nomeArquivo);
	
    return 1;
}