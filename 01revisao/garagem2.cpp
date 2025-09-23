#include<iostream>
#include<string>

#define TAM 5

using namespace std;

typedef struct {
    string placas;
    string horaEntrada;
    string horaSaida;
    float valor;

} Carro;

int main(){
    Carro garagem[TAM];
    Carro carro;
    int quantidadeCarros = 0;
    int opcao = 1;

    while(opcao != 4){
        cout << "M E N U\n";
        cout << " 1 - Veículo Entra\n";
        cout << "2 - Veículo Sai\n";
        cout << "3 - Listar Veículo\n";
        cout << "4 - Fim\n";
        cout << opcao;
        cin >> opcao;

        switch (opcao){
        case 1:
        cout << "entrando na garagem\n";
        if(quantidadeCarros == TAM){
            cout << "garagem cheia\n";
        }else{
            for(int i=0; i<TAM; i++){
                if(carro[i] == carro[i]){
                    cout << "carro ja esta na garagem\n";
                }
            }
            
            cout << "placa: ";
            cin >> carro.placas;
            cout << "hora de entrada: ";
            cin >> carro.horaEntrada;

            garagem[ quantidadeCarros ] = carro;
            quantidadeCarros++;
            cout <<"imprimindo ticket\n";
        }
            break;
         case 2:
        cout << "saindo da garagem\n";
            break;
        
             case 3:
        cout << "Listagem de carros na garagem\n";
        if(quantidadeCarros == 0){
            cout << "garagem vazia\n";
        }else{
            for(int i = 0; i < quantidadeCarros; i++){
                cout << "carro com placa" << garagem[i].placas << "hora entrada" << garagem[i].horaEntrada << "\n";
            }
        }
            break;

         case 4:
        cout << "obrigado por usar o sistema\n";
            break;
        
            
        default:
        cout << "Opção inválida, tente novamente\n";
            break;
        }
    
    }

    return 1;


}
//verificar se o carro já está na garagem