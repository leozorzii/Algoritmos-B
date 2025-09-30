/* 7) Criar um programa que tenha duas funções:
- função que receba um nome de arquivo texto e retorne uma string com todas as palavras em maiúsculo;
- função que receba um nome de arquivo texto e retorne a quantidade de palavras neste arquivo
*/

#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;


bool arquivoExiste(const string& nomeArquivo){
    ifstream procuradorArquivo; //procurador
    procuradorArquivo.open(nomeArquivo);//ta representado em memoria ram
    if (procuradorArquivo){
        procuradorArquivo.close();
        return true;
    } else {
        return false;
    }
}

string copiarArquivoParaString(const string& nomeArquivo){
    ifstream procuradorArquivo; //procurador
    procuradorArquivo.open(nomeArquivo);//ta representado em memoria ram
    if (!procuradorArquivo) return "";

    string resposta;
    string linha;
    // Evita while (!eof())
    while (getline(procuradorArquivo, linha)) {
        resposta += linha;
        resposta += '\n';
    }
    procuradorArquivo.close();

    return resposta;
}

// Retorna o CONTEÚDO do arquivo todo em MAIÚSCULAS (ASCII)
string arquivoEmMaiusculas(const string& nomeArquivo){
    string texto = copiarArquivoParaString(nomeArquivo);
    for(char &c : texto ){
        c = toupper(c);
    }
    return texto;
}

// Conta as PALAVRAS no conteúdo do arquivo
size_t contarPalavras(const string& nomeArquivo){
    string texto = copiarArquivoParaString(nomeArquivo);
    istringstream stream(texto);
    string palavra;
    size_t contador = 0;
    while (stream >> palavra){
        ++contador;
    }
    return contador;
}

int main(){
    string nomeArquivo;
    cout << "digite o caminho do arquivo" << endl;
    getline(cin, nomeArquivo);
    
    // testar se o arquivo existe
    if(arquivoExiste(nomeArquivo)){
        cout << "arquivo localizado com sucesso!"<< endl;
    } else {
        cout << "arquivo nao localizado" << endl;
        exit(0);
    }
    
    // (opcional) mostrar conteúdo original
    string resposta = copiarArquivoParaString(nomeArquivo);
    cout << "=== CONTEUDO ORIGINAL ===\n" << resposta << endl;

    // 1) Exibir conteúdo em maiúsculas
    string emMaiusculas = arquivoEmMaiusculas(nomeArquivo);
    cout << "--- CONTEUDO EM MAIUSCULAS ---\n";
    cout << emMaiusculas << endl;

    // 2) Contar e mostrar quantidade de palavras
    size_t totalPalavras = contarPalavras(nomeArquivo);
    cout << "Quantidade de palavras: " << totalPalavras << endl;

    return 0;
}
