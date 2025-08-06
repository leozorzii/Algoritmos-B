#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
int main(){
    int idade;
    int tempoSono;

    printf("digite sua idade: ");
    scanf("%d",&idade);

    tempoSono = (int)(idade/3);//converte divisao para inteiro

    printf("Você ja dormiu %d anos\n",tempoSono);
    return 1;
}