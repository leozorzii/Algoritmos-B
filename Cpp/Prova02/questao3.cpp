/*Questão 3) Dado um arquivo texto chamado de nomes.txt, 
criar um programa que leia o arquivo e armazene esses nomes numa lista de nomes do tipo string. 
Ao final, exibir a lista populada com a quantidade de nomes lidos do arquivo. 
Questão 4) Complemento da questão 3. Agora, construir um método que localize e exiba os nomes replicados.*/
 #include <cctype>
#include <fstream>
#include <sstream>
#include <filesystem> 
#include <string>
#include <algorithm>
#include <iostream>
#include<random>
#define tam 5
using namespace std;

string copiarNomesArquivoParaString(string nomeArquivo){
     ifstream procuradorArquivo; //procurador
    procuradorArquivo.open("nomes.txt");//ta representado em memoria ram
    string resposta = "";
    string linha;
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		resposta = resposta + linha + "\n";
    } 
    procuradorArquivo.close();

    return resposta;
}
int main(){

    string resposta = copiarNomesArquivoParaString("nomes.txt");;
cout << resposta;


    return 0;
}