#include <iostream> // <stdio.h>
#include <string>
#define TAM 4
using namespace std;
 
 #include "meusincludes.h"
 
typedef struct {
    string nome;
    string celular;
    string data;
    string descricao;
} Emprestimo;
 
int main()
{
    int opcao;
    Emprestimo meusItens[TAM];//base temporaria
    Emprestimo item;
    int qtdEmprestimos = 0;
 
    do
    {
        cout << "M E N U" << endl;
        cout << "1 - Emprestar" << endl;
        cout << "2 - Devolver" << endl;
        cout << "3 - Listar emprestimos" << endl;
        cout << "4 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;
 
        switch (opcao)
        {
        case 1:
            cout << "AREA DE EMPRESTIMO" << endl;
            if (qtdEmprestimos == TAM) {
                cout << "Voce nao tem mais itens para emprestar..." << endl;
            } else {
                cout << "Pessoa: ";
                getline(cin, item.nome);//evitar quebra no espaco(Leo Zorzi/  fica so Leo)
                cout << "Numero de Celular" ;
                getline(cin,item.celular);
                cout << "Item: ";
                getline(cin, item.descricao);
                //rotina para verificar se o item ja foi ou nao emprestado
                //rotina para capturar a data de emprestimo

                cout << "data do emprestimo (dd/mm/aaaa):";
                cin >> item.data;
                //armazenar na base temporaria
                meusItens[qtdEmprestimos] = item;
                qtdEmprestimos++;
                cout << "Item registrado com sucesso..." <<endl;
            }
            break;
        case 2:
            cout << "AREA DE DEVOLUCAO" << endl;
            if (qtdEmprestimos == 0) {
                cout << "Nenhum item esta emprestado" << endl;
            } else {
                for(int i=0;i < qtdEmprestimos;i++){
                    cout << "Itens: " << meusItens[i].descricao << endl;
                    cout << "Pessoa" << meusItens[i].nome << endl;
                    cout << "Data de Emprestimo" << meusItens[i].data << endl;
                }
            }
            break;
        case 3:
            cout << "LISTAGEM DE EMPRESTIMOS" << endl;
            if (qtdEmprestimos == 0) {
                cout << "Nenhum item esta emprestado" << endl;
            } else {
 
            }
            break;
        case 4:
            cout << "Voce esta encerrando o programa...." << endl;
            break;
        default:
            cout << "Opcao invalida...." << endl;
            break;
        }        
    } while (opcao != 4);
    cout << "Programa encerrado....\n";
    return 1;
}