#include <iostream> //stdio.h
#include <string>   //string.h
#include <vector>
#include <algorithm>
#include <limits>
 //ordenar os nomes por ordem de entrada
#define TAM 4
 
using namespace std;
 
int main() {
    cout << "Fazer um programa em C ou C++ que preencha um vetor de string com n nomes e exiba-os" << endl;
    string nomes[TAM];
    int quantidadeInseridos = 0;
    int opcao;
    string nome;
    string tmp;
    do {
        cout << "MENU" << endl;
        cout << "1 - Cadastrar nomes" << endl;
        cout << "2 - Listar nomes" << endl;
        cout << "3 - Pesquisar nome" << endl;
        cout << "4 - Ordenar" << endl;
        cout << "5 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
 
        switch (opcao)
        {
        case 1:
            cout << "Cadastrar nomes..." << endl;
            if (quantidadeInseridos == TAM) {
                cout << "Vetor lotado..." << endl;
            } else {
                for (int i = 0; i < TAM; i++) {
                    cout << "Nome: ";
                    getline(cin, nome);
                    
                    //rotina que verifica se o nome ja esta no vetor de nomes
                    bool jaExiste = false;
                    for (int j=0; j < quantidadeInseridos; j++){
                        if (nome == nomes[j]) {
                            jaExiste = true;
                            break;
                        }
                    }
                    if(!jaExiste){
                        nomes[quantidadeInseridos] = nome;
                        quantidadeInseridos++;
                    }else{
                        cout << "Nome ja cadastrado" << endl;
                    } 
                }
            }
            break;
        case 2:
            cout << "Listar nomes:" << endl;
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
            cout << "Pesquisar nome:" << endl;
            if (quantidadeInseridos == 0) {
                cout << "Vetor de nomes vazio... nao eh possivel pesquisa ..." << endl;
            } else {
                cout << "Nome para pesquisa:" << endl;
                getline(cin,nome);
                int quantidadeLocalizados = 0;
                for (int i = 0; i < quantidadeInseridos; i++) {
                    if (nomes[i].find(nome)) {
                        cout << nomes[i] << endl;
                        quantidadeLocalizados++;
                    }
                }
                cout << "-----------------" << endl;
                cout << "Total de registros: " << quantidadeLocalizados << endl;
            }
            break;
        case 4:
        //filosofia da bolha empurrar os maiores para o final do vetor
            cout << "Ordenando o vetor de nomes." << endl;
            bool houveTroca;
            do{
                houveTroca = false;
                for(int i = 0; i < quantidadeInseridos-1; i++){
                    if(nomes[i] > nomes[i+1]){
                        houveTroca = true;
                        tmp = nomes[i];
                        nomes[i] = nomes[i+1];
                        nomes[i+1] = tmp;
                    }
                }
            } while(houveTroca);
                           
            break;
 
        case 5:
            cout << "Saindo do programa" << endl;
        default:
            cout << "Opcao invalida..." << endl;
            break;
        }
    } while (opcao != 5);
    return 1;
}