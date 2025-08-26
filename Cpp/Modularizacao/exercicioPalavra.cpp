#include <iostream>

using namespace std;

#include "metodoexercicio.h"

int main(){
    string palavra;
    char letra;
    int cont = 0;

    cout << "Digite uma palavra" << endl;
    cin >> palavra;
    cout << "digite uma letra" << endl;
    cin >> letra;

    receber(palavra, letra);
}
  
