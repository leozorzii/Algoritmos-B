#include <iostream>
#include<string>
#include <cctype>

using namespace std;

void inverterFrase(string frase){
    string invertido;
    for(int i = frase.size() - 1;i >= 0; i--){
     invertido += frase[i];
    }
        cout << invertido << endl;
}

int main(){
string frase;
        cout << "digite uma frase para inverter: " << endl;
        getline(cin,frase);
        
        inverterFrase(frase);


     return 0;
}