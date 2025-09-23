/* 6) Criar um programa que tenha uma função que receba 
um nome de arquivo texto e um caracter de pesquisa. 
A função deve retornar uma string contendo o conteúdo do arquivo, 
contudo substituindo o caracter de pesquisa pelo símbolo @. */

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
    if (!procuradorArquivo) return "";

    string resposta = "";
    string linha;
    // Evita while (!eof())
    while (getline(procuradorArquivo, linha)) {
        resposta += linha + "\n";
    }
    procuradorArquivo.close();

    return resposta;
}

// Troca case-insensitive: 'a' e 'A' viram '@'
string trocarCaracter(string texto, char letra){
    for (size_t i = 0; i < texto.length(); i++){
        char ch = (texto[i]);
        if (toupper(ch) == toupper((letra))){
            texto[i] = '@';
        }
    }
    return texto;
}

int main(){
    string nomeArquivo;
    cout << "digite o caminho do arquivo" << endl;
    cin >> nomeArquivo;
    
    // testar se o arquivo existe
    if(arquivoExiste(nomeArquivo)){
        cout << "arquivo localizado com sucesso!"<< endl;
    } else {
        cout << "arquivo nao localizado" << endl;
        exit(0);
    }
    
    // receber conteudo do arquivo
    string conteudo = copiarArquivoParaString(nomeArquivo);
    cout << "--- CONTEUDO ORIGINAL --\n" << conteudo << endl;

    // escolha do caracter para mudar no arquivo
    char letra;
    cout << "digite a letra decisoria" << endl;
    cin >> letra;

    // trocar no CONTEUDO (não no nome do arquivo)
    string resultado = trocarCaracter(conteudo, letra);

    cout << "=== CONTEUDO MODIFICADO ===\n" << resultado << endl;

    return 0;
}
