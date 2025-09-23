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


string trocarCaracter(string frase, char letra){
    for(int i=0; i < frase.length();i++){
        if(toupper(frase[i]) == toupper(letra)){
            frase[i] = '@';
        }
    }
    return frase;
}


int main(){
//receber frase em uma string
    string frase;
    cout << "digite uma frase" << endl;
    getline(cin, frase);

    char letra;
    cout << "digite a letra de pesquisa" << endl;
    cin >> letra;

    //receber a frase com caracter de pesquisa

    string fraseRes = trocarCaracter(frase, letra);

    //exibir frase alterada
    cout << "Frase alterada: " << fraseRes << endl;



    return 1;
}