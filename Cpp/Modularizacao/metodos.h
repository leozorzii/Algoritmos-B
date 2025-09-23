#include <cstdlib>
#include <time.h>
#include <string.h>
#include <algorithm>


void popular(int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel...";
        return; //forcando a saida do metodo
    }
    srand(time(NULL));
    for (int i = 0; i < quantidade; i++) {
        vetor[i] = rand() % 100;
    }
}

void exibir(string frase, int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel...";
        return; //forcando a saida do metodo
    }
    cout << frase << endl;
    for (int i = 0; i < quantidade; i++) {
        cout << vetor[i] << endl;
    }
}

void menorElemento(int vetor[], int quantidade, int tamanho) {
    int menor = vetor[0];

    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel...";
        return; //forcando a saida do metodo
    }

    for (int i = 1; i < quantidade; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    cout << "Menor elemento =  " << menor << endl;

}
        
        void ordenar(int vetor[], int quantidade, int tamanho){
            if(quantidade > tamanho){
                cout << "Quantidade não é possivel" << endl;
            }
            sort(vetor, vetor + quantidade);
            cout << "Vetor Ordenado" << endl;
        }
            //exercicio 4 de arquivos
        

    