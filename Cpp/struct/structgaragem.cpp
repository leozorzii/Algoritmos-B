#include <iostream>
#include <string>
#include <cctype>

#define TAM 5
using namespace std;

struct Carro {
    string placas;
    string horaEntrada;
    string horaSaida;
    float valor{};
};

        //  functions de validação

bool validaPlaca7(const string& p) {
    if (p.size() != 7) return false;
    // 3 letras
    for (int i = 0; i < 3; ++i) {
        if (!isalpha((unsigned char)p[i])) return false;
    }
    // 4 números
    for (int i = 3; i < 7; ++i) {
        if (!isdigit((unsigned char)p[i])) return false;
    }
    return true;
}

bool validaHoraHHMM(const string& h) {
    if (h.size() != 5) return false;
    if (h[2] != ':') return false;
    if (!isdigit((unsigned char)h[0]) || !isdigit((unsigned char)h[1]) ||
        !isdigit((unsigned char)h[3]) || !isdigit((unsigned char)h[4])) return false;

    int HH = (h[0] - '0') * 10 + (h[1] - '0');
    int MM = (h[3] - '0') * 10 + (h[4] - '0');

    if (HH < 0 || HH > 23) return false;
    if (MM < 0 || MM > 59) return false;
    return true;
}


int main() {
    Carro garagem[TAM];
    int quantidadeCarros = 0;
    int opcao = 0;

    while (opcao != 4) {
        cout << "\n===== M E N U =====\n";
        cout << "1 - Veiculo Entra\n";
        cout << "2 - Veiculo Sai\n";
        cout << "3 - Listar Veiculos\n";
        cout << "4 - Fim\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
        case 1: {
            cout << "\n--- Entrada de Veiculo ---\n";
            if (quantidadeCarros == TAM) {
                cout << "Garagem cheia!\n";
                break;
            }

            Carro novo;
            // placa válida
            while (true) {
                cout << "Placa (AAA0000): ";
                cin >> novo.placas;
                for (auto &c : novo.placas) c = toupper((unsigned char)c);

                if (!validaPlaca7(novo.placas)) {
                    cout << "Formato invalido. Use 3 letras + 4 numeros (ex.: ABC1234).\n";
                    continue;
                }

                bool existe = false;
                for (int i = 0; i < quantidadeCarros; ++i) {
                    if (garagem[i].placas == novo.placas) { 
                        existe = true; 
                        break; 
                    }
                }
                if (existe) {
                    cout << "Este carro ja esta na garagem.\n";
                    continue;
                }
                break;
            }

            // Hora válida
            while (true) {
                cout << "Hora de entrada (HH:MM): ";
                cin >> novo.horaEntrada;
                if (!validaHoraHHMM(novo.horaEntrada)) {
                    cout << "Hora invalida. Use HH:MM de 00:00 a 23:59.\n";
                    continue;
                }
                break;
            }

            garagem[quantidadeCarros++] = novo;
            cout << "Ticket emitido. Carro " << novo.placas
                 << " entrou as " << novo.horaEntrada << ".\n";
            break;
        }

        case 2:
            cout << "\n--- Saida de Veiculo ---\n";
            break;

        case 3:
            cout << "\n--- Carros na Garagem ---\n";
            if (quantidadeCarros == 0) {
                cout << "Garagem vazia.\n";
            } else {
                for (int i = 0; i < quantidadeCarros; ++i) {
                    cout << "Placa: " << garagem[i].placas
                         << " | Entrada: " << garagem[i].horaEntrada << "\n";
                }
            }
            break;

        case 4:
            cout << "Encerrando.\n";
            break;

        default:
            cout << "opcao invalida, tente novamente.\n";
            break;
        }
    }

    return 0;
}
