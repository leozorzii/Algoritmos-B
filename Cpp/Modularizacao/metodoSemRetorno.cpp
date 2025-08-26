#include <iostream>

#define TAM 10000

using namespace std;

#include "metodos.h"

int main(){
    int vetor[TAM];
    int quantidade =10;

    //metodo que popule o vetor com n elements aleatorios desde menor que TAM
    popular(vetor, quantidade, TAM); //metodo de 3 parametros


    //metodo exiba o valor
    exibir("exibindo vetor", vetor, quantidade, TAM);

    //metodo que receba um vetor, quantidade e seu tamanho e exiba o menor elemento
    menorElemento(vetor, quantidade, TAM);

    //metodo que recebe um vetor, quantidade e seu tamanho e ordene em ordem crescente - bolha
    ordenar(vetor, quantidade, TAM);
    return 1;
}
