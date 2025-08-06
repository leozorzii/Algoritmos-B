#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Sortear TAM de numeros num vetor, porem
//nao pode inserir numeros presentes no vetor
//exibir o vetor no final
    #define TAM 10


    int main(){
       int vetor[TAM]; 
    srand(time(NULL));
        int num;
        int qntInserida = 0;
        int jainserido;

        for(int i=0; i< TAM; i++){
        num = rand() % 100;
        jainserido = 0;

        for(int j=0; j <= qntInserida; j++){
            if(num == vetor[j]){
                jainserido =1;//numero ja esta no vetor
            break;
        }
    }
      
        if(!jainserido == 0){
            vetor[qntInserida] = num;
            qntInserida++;
        }
    }
        for(int i=0; i < qntInserida;i++){
            printf("%d\t",vetor[i]);
        }
            printf("\n");
    return 1;
}
