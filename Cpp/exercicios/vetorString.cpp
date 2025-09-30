//1) Fazer um programa em C ou C++ que preencha um vetor de string com n nomes e exiba-os
 
#include <iostream> //stdio.h
#include <string>   //string.h
#include <algorithm> //Para rodar a função sort
#include <limits> // Para usar cin.ignore

#define TAM 4
 
using namespace std;
 
int main() {
    cout << "Fazer um programa em C ou C++ que preencha um vetor de string com n nomes e exiba-os" << endl;
    string nomes[TAM];
    int quantidadeInseridos = 0;
    int opcao;
    string nome;
    do {
        cout << "MENU" << endl;
        cout << "1 - Cadastrar nomes" << endl;
        cout << "2 - Listar nomes" << endl;
        cout << "3 - Pesquisar nome" << endl;
        cout << "4 - Ordenar nomes" << endl;
        cout << "5 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcao){
            case 1:
                if (quantidadeInseridos == TAM) {
                cout << "Vetor lotado...." << endl;
                }else {
                cout << "Nome: ";
                getline(cin, nome);

                bool jaExiste = false;
                for (int j = 0; j < quantidadeInseridos; j++) {
                    if (nomes[j] == nome) {
                        jaExiste = true;
                        break;
                    }
                }

                if (jaExiste) {
                    cout << "Nome já cadastrado. Tente outro..." << endl;
                } else {
                    nomes[quantidadeInseridos] = nome;
                    quantidadeInseridos++;
                    cout << "Nome cadastrado com sucesso!" << endl;
                }
            }
            break;

        
            case 2:
                cout << "Listar nomes ..." << endl;
                if (quantidadeInseridos == 0) {
                    cout << "Vetor de nomes vazio... nada a exibir ..." << endl;
                } else {
                    for (int i = 0; i < quantidadeInseridos; i++) {
                        cout << "Nome " << (i+1) << ": " << nomes[i] << endl;
                    }
                    cout << "-----------------" << endl;
                    cout << "Total de registros: " << quantidadeInseridos << endl;
                }
                break;
            case 3:
                cout << "Pesquisar nome ..." << endl;
                if (quantidadeInseridos == 0) {
                    cout << "Vetor de nomes vazio... nao eh possivel pesquisa ..." << endl;
                } else {
                    cout << "Nome para pesquisa: ";
                    getline(cin,nome);
                    int quantidadeLocalizados = 0;
                    for (int i = 0; i < quantidadeInseridos; i++) {
                        if (nomes[i].find(nome) != string::npos) {
                            cout << nomes[i] << endl;
                            quantidadeLocalizados++;
                        }
                    }
                    cout << "-----------------" << endl;
                    cout << "Total de registros: " << quantidadeLocalizados << endl;
                }
                break;
            case 4:
                if(quantidadeInseridos == 0){
                    cout << "Vetor de nomes vazio... nada a exibir ..." << endl;
                }else{
                    cout << "Ordenando o vetor de nomes..." << endl;
                    sort(nomes, nomes + quantidadeInseridos);
                }
                break;
            case 5:
                cout << "Saindo do programa ..." << endl;
                break;
            default:
                cout << "Opcao invalida..." << endl;
                break;
        }
    } while (opcao != 5);
    return 1;
}