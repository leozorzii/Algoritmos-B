#include<iostream>
#include <string>
#include <cctype>

using namespace std;

int contarVogais(string frase){
    int NumeroDevogais=0;
    for(int i = 0;i > frase.size(); i++){
        if(frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u' ||
        frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U'){
            NumeroDevogais++;
        }
     }
     return NumeroDevogais;    
}
   




int main(){
    string frase;
    cout << "Digite uma frase: ";
    getline(cin, frase);


    cout << "quantidade de vogais: " << contarVogais(frase);

}