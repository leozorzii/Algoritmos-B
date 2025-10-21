#include <iostream>
#include <string>
using namespace std;
#define n 5
//fazer um programa que recebe um vetor de n inteiros
//1) criar popular(sortear numeros)
//2)criar um localizar pares e impares


void popular(int *v, int tam){
    srand(time(NULL));
    for(int i=0;i<n;i++){
        v[i] = rand() %20;
    }
}

void localizarImpPar(int *v, int tam, int *pares, int *impares){
    *pares=0;
    *impares=0;
    
    for(int i=0;i<n;i++){
        if(v[i] %2 ==  0){
            *pares = *pares + 1;
        }
        else{
             *impares = *impares + 1;
        }
    }
}
void exibir(int *v, int tam){
    for(int i=0;i<n;i++){
        cout << v[i] << endl;
    }
}


int main(){
    int numeros[n];
    int qtdPares;
    int qtdImpares;

    popular(numeros,n);
    localizarImpPar(numeros,n, &qtdPares, &qtdImpares);
    exibir(numeros, n);

    cout << "quantidade de pares: "<< qtdPares << endl;
    cout << "quantidade de impares: " << qtdImpares << endl;
}

