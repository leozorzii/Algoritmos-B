#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
#define n 5

void popular(int *v, int tam){
    srand(time(NULL));
    for(int i=0;i<tam;i++){
        v[i] = rand() %20;
    }
}
void substituirPares(int *v, int tam,int &qtdSubstituida){
    qtdSubstituida=0;
    for(int i=0;i<tam;i++){
        if(v[i]%2==0){
            v[i] = 0;
            ++qtdSubstituida;
        }
    }
}

void exibir(int *v, int tam){
    for(int i=0;i<tam;i++){
        cout << v[i] << endl;
    }
}


int main(){
    int numeros[n];
    int valornovo;
    popular(numeros,n);
    int qtd;
    substituirPares(numeros,n,qtd);
    exibir(numeros, n);
    cout << "quantidade de numeros pares substituidos: " << qtd << endl;

    /*faça um metodo que receba um vetor, substitua todos os elementos pares por 0 e retorne
     a quantidade de numeros que foram
    substituidos contudo, nao pode usar return*/

}

