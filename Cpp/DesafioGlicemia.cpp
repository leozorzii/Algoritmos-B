#include <iostream> //stdio.h
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>

/*fechei os cases 3 e 4 com chaves por causa do
swtich nao criar o escopo correto, sendo desviado antes da variavel
ser iniciada*/

#define TAM 5
using namespace std;

   int main(){
    double indices[TAM];
    int qtdGlicemica = 0;
    int opcao = 0;

    do{
        cout << "-- M E N U --" << endl;
        cout << "1 - Cadastrar Glicemia(5 medições)" << endl;
        cout << "2 - Mostrar Dados Glicemicos" << endl;
        cout << "3 - Media Glicemica" << endl;
        cout << "4 - Mediana Glicemica" << endl;
        cout << "5 - Sair" << endl;
        
        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcao invalida.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //para limpar sem usar fflush(stdin)

            switch(opcao) {
            case 1:
                cout << "-- Cadastro de Glicemia --" << endl;
                if(qtdGlicemica == TAM){
                    cout << "Você ja cadastrou "<< qtdGlicemica << "valores." << endl;
                    break;

                }else{
                    cout << "Glicemia(faixa de 45 a 450) restam " << (TAM - qtdGlicemica) << " posicoes" << endl;
                    
                        for(int i = qtdGlicemica; i < TAM ; i++){
                            double valor;
                        if(!(cin >> valor)){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "[ERROR] Tente novamente." << endl;
                            --i;
                            continue;
                        }

                         cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        indices[i] = valor;
                        qtdGlicemica= i+1;
                    }
                    cout << "Seu indice foi cadastrado com sucesso, total: " << qtdGlicemica << endl;
                    break;
                }

            break;

            case 2:
                cout << "-- Mostrar Valores Glicemicos --" << endl;
                if(qtdGlicemica ==0){
                    cout << "vetor de dados vazio..." << endl;
                }else{
                    for(int i=0; i< qtdGlicemica; i++){
                        cout << "Indice " << (i+1) << ": " << indices[i] << endl;

                    }
                    cout << "----------------" << endl;
                    cout << "Quantidade de Registro de Glicemia: " << qtdGlicemica << endl;
                    cout << "----------------" << endl;
                }

            break;

            case 3: {
                cout << "-- Media Glicemica --" << endl;
                if(qtdGlicemica == 0){
                    cout << "Sem dados para calcular a media!" << endl;
                    break;
                }
                double soma = 0.0L;

                for(int i=0 ; i < qtdGlicemica; ++i)soma += indices[i];
                    double media = static_cast<double>(soma / qtdGlicemica);
                    cout << fixed << setprecision(2)//imprime em ponto fixo, com casas decimais
                        << "Media: " << media << endl;
                    break; 
                }
            case 4: { 
            cout << "-- Mediana Glicemica --" << endl;
            if(qtdGlicemica == 0){
                cout << "Sem dados para calcular a mediana!" << endl;
                break;
            }

                vector<double> tmp(indices, indices + qtdGlicemica);
                sort(tmp.begin(), tmp.end());

                double mediana;

                if(qtdGlicemica % 2 == 1){
                    mediana = (tmp[qtdGlicemica / 2]);
            } else {
                    mediana = (tmp[qtdGlicemica /2 -1] + tmp[qtdGlicemica /2]) /2.0;
            }
                cout << fixed << setprecision(2);//numero fixo com duas casas apos a virgula
                cout << "Mediana: " << mediana << endl;
            break;
            }
            case 5:
            cout << "Fechando o programa..." << endl;
            break;

            default:
            cout << "opcao invalida" << endl;
            break;
        }

    }while(opcao !=5);

    return 1;
}