/*3) Construa um programa(com metodo) que leia n nomes de pessoas, armazene em um vetor de nomes e os exiba na tela.
Porém é necessario do lado do nome mostrar os caracteres tem esse nome.
*/
//1) Contrua um programa(com metodo) que leia n nomes de pessoas completos e os exiba na tela
#include<iostream>
#include<string>

using namespace std;

#define TAM 5

   void lerNomes(string nomes[],  int n){
    for(int i = 0;i <TAM;i++){
    cout << "digite seu nome " << i + 1 << endl;
    getline(cin, nomes[i]);
    }
}
    void exibirNomes(string nomes[], int n){
        for(int i=0;i < TAM; i++){
        cout << nomes[i]<< "Tamanho: " << nomes[i].size() << "caracteres" <<endl;
    }
}
    void ordenarNomes(string vetor[],int n){
        string tmp;
        bool houveTroca;

        do{
            houveTroca = false;
            for(int i =0; i < TAM-1; i++){
                if(vetor[i] > vetor[i+1]){
                    houveTroca = true;
                    tmp = vetor[i];
                    vetor[i] = vetor[i+1];
                    vetor[i+1] = tmp;
                }
            }

        }while(houveTroca);
    }

int main(){
    string nomes[TAM];
    lerNomes(nomes, TAM);
    ordenarNomes(nomes,TAM);
    exibirNomes(nomes,TAM);

    return 1;
}