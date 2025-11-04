/*Questão 2) Construir um programa que gere aleatoriamente n números inteiros e os armazene em um vetor de tamanho TAM.
 Contudo, é necessário criar um método que receba: 
 a) o vetor com os números gerados automaticamente
  b) o tamanho desse vetor ou a quantidade de números inseridos no vetor 
 c) um vetor de resultado que irá armazenar somente os pares*/
 #include <cctype>
#include <fstream>
#include <sstream>
#include <filesystem> 
#include <string>
#include <algorithm>
#include <iostream>
#include<random>
#define tam 5
using namespace std;

int geradorDeNumeros(int num[], int tamanho){
    random_device rd;
    mt19937 geradorNumeros(rd());
    uniform_int_distribution<int> distribuicao(1,100);
    for(int i = 0; i < tamanho; i++){
        num[i] = distribuicao(geradorNumeros);
    }
    return tamanho;
}

void encontrarPares(int numeros[], int tamanho, int pares[], int qtdPares){
    qtdPares = 0;
    for(int i = 0; i < tamanho; i++){
        if(numeros[i] % 2 == 0){
            pares[qtdPares++] = numeros[i];
            cout <<"numeros gerados(pares):\n" << numeros[i] << endl;
        }
    }
}
int main(){

int numeros[tam];
int numerosPares[tam];
int qtdPares;
geradorDeNumeros(numeros,tam);
encontrarPares(numeros,tam, numerosPares,qtdPares);

    int qtdGerados = geradorDeNumeros(numeros, tam);

    cout << "quantidade de numeros gerados: " << qtdGerados << endl;
}