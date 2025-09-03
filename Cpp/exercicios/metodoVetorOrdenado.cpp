#include <iostream>
#include <vector>

using namespace std;
//fazer um programa que tenha um método que receba um vetor de números inteiros,
// o tamanho desse vetor e retorne true se o vetor estiver ordenado ou false se o vetor estiver desordenado.

/*OBS---------------------------------------------------------------------------
  --->  estao em divididos ordem crescente, decrescente e desordenado pra ficar mais completo
*/
    //Metodos 
    bool estaCrescente(int vetor[], int tamanho){
        for(int i = 0; i < tamanho -1;i++){
            if(vetor[i] > vetor[i+1]){
            return false;
        }
    }
    return true;
}

    bool estaDecrescente(int vetor[], int tamanho){
          for(int i = 0; i < tamanho -1;i++){
            if(vetor[i] < vetor[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    int tamanho;

    cout << "digite o tamanho do vetor" << endl;
    cin >> tamanho;

    int vetor[tamanho]; 

    cout << "digite os " << tamanho << " numeros" << endl;
    for(int i = 0;i<tamanho;i++){
        cout << "espaco " << i << ": ";
        cin >> vetor[i];
    }
    if(estaCrescente(vetor, tamanho)){
        cout << "vetor digitado esta ordenado de forma CRESCENTE!" << endl;

    }else if(estaDecrescente(vetor, tamanho)){
        cout << "vetor digitado esta ordenado de forma DECRESCENTE" << endl;

    }else{
        cout << "vetor digitado esta DESORDENADO!!" << endl; 
    }


    return 0;
}