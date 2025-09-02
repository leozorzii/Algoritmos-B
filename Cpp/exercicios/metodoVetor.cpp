#include <iostream>
#include <vector>

using namespace std;
//fazer um programa que tenha um método que receba um vetor de números inteiros,
// o tamanho desse vetor e retorne true se o vetor estiver ordenado ou false se o vetor estiver desordenado.


bool estaOrdenado(int vetor[], int tamanho){
    for(int i = 0; i < tamanho-1;i++){
        if(vetor[i] > vetor[i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    int vetor[100];


    return 1;
}