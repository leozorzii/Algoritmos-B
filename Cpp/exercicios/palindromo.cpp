#include<iostream>
#include<string>

using namespace std;

bool ehPalindromo(string palavra){
    int inicio = 0;
    int fim = palavra.size() - 1;
    while(inicio < fim){
        if(palavra[inicio] == palavra[fim]){
            inicio++;
            fim--;
            cout << "eh um palindromo" << endl;
        }else{
            cout << "palavra nao eh um palindromo" << endl;
            return false;
        }
    }
    return true;
}



int main(){
string palavra;


    cout << "digite uma palavra pra verificarmos se eh um palindromo: " << endl;
    cin >> palavra;

    ehPalindromo(palavra);

    return 0;
}