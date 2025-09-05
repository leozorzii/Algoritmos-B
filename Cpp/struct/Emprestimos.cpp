#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#define TAM 4
using namespace std;
 
 #include "meusincludes.h"


 
int main()
{
    int opcao;
    Emprestimo meusItens[TAM];//base temporaria
    Emprestimo item;
    int qtdEmprestimos = 0;

 
    do
    {
        exibirMenu();
            cin >> opcao;
             cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa
 
        switch (opcao){
        case 1: 
        emprestarItem(meusItens, qtdEmprestimos);
            break;
        case 2:
        devolverItem(meusItens, qtdEmprestimos);
            break;
        case 3:
        listarItens(meusItens, qtdEmprestimos);
            break;
         case 4:
                buscarItem(meusItens, qtdEmprestimos);
            break;
            
            case 5:
            cout << "Voce esta encerrando o programa...." << endl;
            break;

        default:
            cout << "Opcao invalida...." << endl;
            break;
        }        
    } while (opcao != 5);
    cout << "Programa encerrado....\n";
    return 1;
}