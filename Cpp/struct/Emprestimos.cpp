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
        cout << "M E N U" << endl;
        cout << "1 - Emprestar" << endl;
        cout << "2 - Devolver" << endl;
        cout << "3 - Listar emprestimos" << endl;
        cout << "4 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa
 
        switch (opcao)
        {
        case 1:
            cout << "AREA DE EMPRESTIMO" << endl;
            if (qtdEmprestimos == TAM) {
                cout << "Voce nao tem mais itens para emprestar..." << endl;
            } else {
                cout << "Pessoa: ";
                getline(cin, item.nome);

                cout << "Numero de Celular: " ;
                getline(cin,item.celular);

                cout << "Item: ";
                getline(cin, item.descricao);

                //rotina para verificar se o item ja foi ou nao emprestado
                bool existe = false;
                for(int i =0 ; i< qtdEmprestimos ; ++i){
                    if(meusItens[i].descricao == item.descricao){
                        existe = true;
                        break;
                    }
                    if(existe){
                        cout << "Item ja esta emprestado";
                    }
                }

                //rotina para capturar a data de emprestimo
                time_t agora = time(nullptr);
                tm* t = localtime(&agora);
                item.data = to_string(t->tm_mday) + "/" + to_string(t->tm_mon +1) + "/" + to_string(t->tm_year + 1900);

                //rotina para capturar horario do emprestimo
                item.hora = to_string(t->tm_hour) + ":" + to_string(t->tm_min);

                cout << "Data: " << item.data << endl;
                cout << "Hora: " << item.hora << endl;
                
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
                    int guardaItem = -1;
                    if(guardaItem == -1){
                        cout << "item nao encontrado";
                    }else{
                        for(int i = guardaItem; i< qtdEmprestimos; ++i){
                            meusItens[i] = meusItens[i +1];
                        }
                        qtdEmprestimos--;
                        cout << "item devolvido";
                    }
                for(int i=0;i < qtdEmprestimos;i++){
                    cout << "Itens: " << meusItens[i].descricao << endl;
                    cout << "Pessoa: " << meusItens[i].nome << endl;
                    cout << "Data de Emprestimo: " << meusItens[i].data << endl;
                    cout << "Horario de Emprestimo: " << meusItens[i].hora << endl;
                }
        }
            break;
        case 3:
            cout << "LISTAGEM DE EMPRESTIMOS" << endl;
            if (qtdEmprestimos == 0) {
                cout << "Nenhum item esta emprestado" << endl;
            } else {
                for(int i=0;i<qtdEmprestimos;i++){
                    cout << "------------------------" << endl;

                    cout << "item: " << meusItens[i].descricao << endl;
                    cout << "Pessoa: " << meusItens[i].nome << endl;
                    cout << "Numero: " << meusItens[i].celular << endl;
                    cout << "Data: " << meusItens[i].data << endl;
                    cout << "Horario: " << meusItens[i].hora << endl;

                    cout << "------------------------" << endl;
                }
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