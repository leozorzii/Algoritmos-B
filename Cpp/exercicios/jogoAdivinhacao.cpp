/*O Objetivo:
Criar um jogo onde o computador "pensa" em um número secreto entre 1 e 100, 
e o jogador precisa adivinhar qual é esse número.
Requisitos:
No início do programa, use o método que acabamos de ver para sortear 
um número inteiro entre 1 e 100. Guarde este número em uma variável numeroSecreto.
Crie um laço de repetição (while ou do-while) que continuará rodando enquanto o jogador não acertar o número.
Dentro do laço, peça para o jogador digitar um palpite.
Compare o palpite do jogador com o numeroSecreto:
Se o palpite for menor que o número secreto, exiba a mensagem: "Muito baixo! Tente novamente.".
Se o palpite for maior que o número secreto, exiba a mensagem: "Muito alto! Tente novamente.".
Se o palpite for igual ao número secreto, exiba uma mensagem de parabéns como "Parabens! Voce acertou!" e encerre o laço.
Dica: Você vai precisar de uma variável para guardar o palpite do jogador a cada rodada.
Este exercício é excelente porque te força a:
Gerar um número aleatório uma única vez.
Usar um laço para controlar o fluxo do jogo.
Usar if-else para dar dicas ao jogador.*/

#include <iostream>
#include <random>

using namespace std;

int main(){
    random_device rd;
    
    //motor que gera os numeros aleatorio
    mt19937 motor(rd());
    
    // separar no intervalo de 1 a 100 em inteiros
    uniform_int_distribution<int> distribuicao(1,100);

    int numeroSecreto = distribuicao(motor);
    int palpite;

    while (numeroSecreto){
        cout << "digite um palpite para o numero: (1 a 100)" << endl;
        cin >> palpite;
        
            if(palpite > numeroSecreto){
            cout << "Muito alto, tente novamente" << endl;
            cout << "---------------------------------" << endl;
                
            }
            if(palpite < numeroSecreto){
            cout << "Muito baixo, tente novamente" << endl;
            cout << "---------------------------------" << endl;
                
            }    
            if(palpite == numeroSecreto){
                cout << "---------------------------" << endl;
                cout << "Parabens! Voce acertou!" << endl;
                break;
            }
    }
    
}