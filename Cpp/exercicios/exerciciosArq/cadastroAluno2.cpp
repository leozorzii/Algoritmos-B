/*2. Média das notas
A partir do exercício anterior, crie uma função com retorno que receba o vetor de alunos e retorne a 
média geral das notas. Mostre o resultado no programa principal.
*/
#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#include "includes.h"
#include "tipos.h"

 using namespace std;

    #define tam 5

 int main(){
    Aluno vetor[tam];

    lerAlunos(vetor, tam);
    exibirAlunos(vetor, tam);
    float mediaDasNotas = mediaNotas(vetor, tam);

    cout << "a medias da notas: " << mediaDasNotas << endl;
    return 0;
 }


 