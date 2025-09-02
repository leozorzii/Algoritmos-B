#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void fraseMaiuscula(string frase){
  
    for(char &c : frase ){
        c = toupper(c);
    }
    cout << frase << endl;
}

int main(){
    string frase;
    cout << "digite uma frase: " << endl;
    getline(cin, frase);


        fraseMaiuscula(frase);
    return 1;

}