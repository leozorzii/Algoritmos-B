#include <iostream>
#include<string>

using namespace std;

    int contarPalavras(string frase){
        int cont = 0;
        bool foraDaPalavra = true;
        for(char c : frase){
            if(isspace(c)){
                foraDaPalavra = true;
            }else if(foraDaPalavra){
                cont++;
                foraDaPalavra = false;
            }
        }
        return cont;
    }

int main(){
string frase;
cout << "digite uma frase" << endl;
getline(cin, frase);

int totalPalavras = contarPalavras(frase);

cout << "A frase contem:" << totalPalavras << " palavras" << endl;


}