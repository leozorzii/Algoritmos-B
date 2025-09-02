#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int contarVogais(string frase){
    int totalVogais = 0;
    for(int i=0;i<frase.size();i++){

        if(frase[i] == 'a' || frase[i] == 'e'|| frase[i] == 'i'|| frase[i] == 'o'|| frase[i] == 'u'
        || frase[i] == 'A'|| frase[i] == 'E'|| frase[i] == 'I'|| frase[i] == 'O'|| frase[i] == 'U'){
           totalVogais++; 
        }
    }
    

    return totalVogais;
}

    int contarConsoantes(string frase){
        int totalConsoantes = 0;
        for(int i = 0; i< frase.size();i++){
            char c = tolower(frase[i]);
            if(isalpha(c) && !(c =='a' || c == 'e'|| c == 'i' || c == 'o' || c == 'u')){
                totalConsoantes++;
            }
        }
        return totalConsoantes;
    }

int main(){
    string frase;
    cout << "digite uma frase: " << endl;
    getline(cin, frase);

    cout << "quantidade de vogais: " << contarVogais(frase) <<  endl;
    cout << "quantidade de consoantes: " << contarConsoantes(frase) << endl;


    return 1;

}