#include <iostream>
#include <string>
#include <cctype>
#include<cstdlib>
//criar um programa que tenha uma funcao e receba uma frase e retorne a quantidade de vogais
using namespace std;

int contarVogais(string frase){
            int totalVogais = 0;
            for(int i=0;i < frase.length();i++){
                if(frase[i]=='A' ||'E' ||'I' ||'O' ||'U' ||
                'a' ||'e' ||'i' ||'o' ||'u'){
                    totalVogais++;
                }
            }
            return totalVogais;
        }

int main(){
//receber frase em uma string
    string frase;
    cout << "digite uma frase" << endl;
    getline(cin, frase);

//receber a quantidade de vogais na frase
    int quantidadeVogais = contarVogais(frase);

//exibir a quantidade de vogais na frase
    cout << "a frase tem quantidade vogais: " << quantidadeVogais << endl;

    return 1;
}