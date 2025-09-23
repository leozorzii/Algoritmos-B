#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

bool arquivoExiste(string nomeArquivo){
     ifstream procuradorArquivo; //procurador
    procuradorArquivo.open(nomeArquivo);//ta representado em memoria ram
    if (procuradorArquivo){
       procuradorArquivo.close();
        return true;
    }else{
        return false;
    }
}
string copiarArquivoParaString(string nomeArquivo){
     ifstream procuradorArquivo; //procurador
    procuradorArquivo.open(nomeArquivo);//ta representado em memoria ram
    
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
    string nomeArquivo;
    cout << "digite o caminho do arquivo" << endl;
    cin >> nomeArquivo;
    
    //testar se o arquivo existe

   if(arquivoExiste(nomeArquivo)){
    cout << "arquivo localizado com sucesso!"<< endl;
   }else{
    cout << "arquivo nao localizado" << endl;
    exit(0);
   }
    

    //receber conteudo do arquivo
   string resposta = copiarArquivoParaString(nomeArquivo);
   cout << resposta << endl;

    //exibir conteudo da string








    return 0;
}
