#include<string>
#include<iostream>
#define TAM 5
 
using namespace std;
int main() {
    cout << "Exemplo de vetor de placas que são strings\n\n";
    string placa;
    string vetor[TAM];

   
    //rotina que o usuario digita TAM numeros inteiros
    for (int i = 0; i < TAM; i++) {
        cout <<"digite uma placa:";
        getline(cin,placa);//
 
        //rotina que somente adiciona se a placa ja esta no vetor
        vetor[i] = placa;
    }
 
    //rotina que o programa exibe os numeros inteiros um depois do outro
    cout << "Placas: ";
    for (int i = 0; i < TAM; i++) {
        cout << vetor[i] << "\t"; 
    }
   
    cout << "\n";
 
 
    return 1;
}