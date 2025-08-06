#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 5
 
int main() {
    printf("Exemplo de vetor de placas que são strings\n\n");
    char placa[7];
    char vetor[TAM][7];
 
   
    //rotina que o usuario digita TAM numeros inteiros
    for (int i = 0; i < TAM; i++) {
        printf("digite uma placa:", i);
        scanf("%s", placa);        
 
        strcpy(vetor[i], placa);
    }
 
    //rotina que o programa exibe os numeros inteiros um depois do outro
    printf("Placas: ");
    for (int i = 0; i < TAM; i++) {
        printf("placa %d: ",i);
        printf("%s\n",vetor[i]); 
    }
   
    printf("\n");
 
 
    return 1;
}