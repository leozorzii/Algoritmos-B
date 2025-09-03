#include<iostream>
#include<string>
#include <algorithm>
 using namespace std;
//fazer um programa que tenha um método que receba um nome completo e retorne o primeiro nome desse nome completo.
    string retornarPrimeiroNome(string nomeCompleto){
        size_t posEspaco = nomeCompleto.find(' ');

        string primeiroNome;
        
        if(posEspaco == string::npos){
            return nomeCompleto;
        }else{
            return nomeCompleto.substr(0,posEspaco);
        }
    }


 int main(){
    string nomeCompleto;

    cout  << "digite seu nome completo: " << endl;
    getline(cin, nomeCompleto);

    string primeiroNome = retornarPrimeiroNome(nomeCompleto);

     cout << "o primeiro nome eh: " << primeiroNome << endl;

    return 0;
 }