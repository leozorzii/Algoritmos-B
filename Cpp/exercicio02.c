#include<stdio.h>
#include<stdlib.h>
#include<time.h>

    //Plano Cartesiano
int main(){
    int x,y;
        printf("digite o valor de X:");
            scanf("%d",&x);
        printf("digite o valor de Y:");
            scanf("%d",&y);
        if(x>0 && y>0){
            printf("Primeiro Quadrante\n");
        }
        else if(x<0 && y>0){
            printf("Segundo Quadrante\n");
        }
        else if(x<0 && y<0 ){
            printf("Terceiro Quadrante\n");
        }
        else if(x>0 && y<0){
            printf("Quarto Quadrante\n");
        }
        else if(x==0 && y==0){
            printf("eles pertecem a origem\n");
        }
        else if(x!=0  && y==0){
            printf("Está no eixo X\n");
        }
        else if(x==0 && y!=0){
            printf("Está no eixo Y\n");
        }
}