#include <iostream>
#include <ctime>
#include <string>
#define TAM 5
using namespace std;
    //construa um método que preencha o vetor com nomes lidos do teclado
    //construa um método que exiba os nomes do vetor
    //construa um método que receba o vetor e um nome a ser buscado, 
    //'retorne' a posição do nome no vetor. Caso o nome não exista, 'retorne' -1. Não é permitido usar return

    void escreverNomes(string *v, int tam){
        for(int i=0;i<TAM;i++){
        cout << "digite um nome: " << endl;
            getline(cin, v[i]);
        if(v[i] == v[i+1]){
            cout << "nome ja adicionado!!!!" << endl;
            }
        }
    }
    void buscaNome(string *v, int tam, string buscaNome, int *posicao){
        *posicao = -1;
        for(int i=0;i<tam;i++){
            if(v[i] == buscaNome){
                *posicao = i;
                break;
            }
        }
    }
    void exibir(string *v, int tam){
          cout << "-L I S T A   N O M E S-" << endl;
        for(int i=0;i<tam;i++){
            cout << "nome: " << v[i] << endl;
        }
    }


int main() {
    string vet[TAM];

    escreverNomes(vet,TAM);
    exibir(vet,TAM);


    string buscar;
    cout << "----------" << endl;
    cout << "digite um nome para buscar" << endl;
    getline(cin, buscar);

    int posicaoEncontrada=0;
    buscaNome(vet, TAM, buscar, &posicaoEncontrada);

    if (posicaoEncontrada == -1) {
        cout << "Nome nao encontrado no vetor(-1)" << endl;
    } else {
        cout << "Nome encontrado na posicao: " << posicaoEncontrada << endl;
    }

    return 0;

}