#include <iostream>
#include<string>

#include"includes.h"

using namespace std;

void fraseMinuscula(string frase){
    cout << "digite uma frase: "<< endl;
    getline(cin, frase);
    for(char &M : frase){
        M = tolower(M);
    }
    cout << "frase em minusculo:" << endl;
    cout << frase << endl;
     
        
    }


int main(){
    string frase;
    fraseMinuscula(frase);

    return 1;
}