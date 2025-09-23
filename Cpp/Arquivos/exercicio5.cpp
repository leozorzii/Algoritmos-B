/* 5) Criar um programa que tenha uma função que receba 
um nome de arquivo texto e retorne a quantidade de vogais;*/
#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

bool arquivoExiste(string nomeArquivo){
    ifstream procuradorArquivo; //procurador
    procuradorArquivo.open(nomeArquivo); //ta representado em memoria ram
    if (procuradorArquivo){
        procuradorArquivo.close();
        return true;
    } else {
        return false;
    }
}

string copiarArquivoParaString(string nomeArquivo){
    ifstream procuradorArquivo; //procurador
    procuradorArquivo.open(nomeArquivo); //ta representado em memoria ram
    
    string resposta = "";
    string linha;
    // Evita while (!eof())
    while (getline(procuradorArquivo, linha)) {
        resposta += linha + "\n";
    }
    procuradorArquivo.close();

    return resposta;
}

int contarVogais(string texto){
    int NumeroDeVogais = 0;
    for (size_t i = 0; i < texto.size(); i++){
        char c = texto[i];
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
            c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
            NumeroDeVogais++;
        }
    }
    return NumeroDeVogais;    
}

int main(){
    string nomeArquivo;
    cout << "digite o caminho do arquivo" << endl;
    cin >> nomeArquivo;
    
    //testar se o arquivo existe
    if(arquivoExiste(nomeArquivo)){
        cout << "arquivo localizado com sucesso!"<< endl;
    } else {
        cout << "arquivo nao localizado" << endl;
        exit(0);
    }
    
    //receber conteudo do arquivo
    string resposta = copiarArquivoParaString(nomeArquivo);
    cout << resposta << endl;

    //contar e exibir quantidade de vogais no conteudo
    int respostaContador = contarVogais(resposta);
    cout << "contagem de vogais: " << respostaContador << endl;

    return 0;
}
