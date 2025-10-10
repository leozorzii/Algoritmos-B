#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include<iostream>
#include <cctype>
#define TAM 1000
using namespace std;

#include "meusTipos.h"

void gravarPessoaBase(string nome, string email, string baseDados){
   //abrir arquivo para escrita
	ofstream procuradorArquivo; 
    //arquivo sendo aberto para append ou inserir no final
    procuradorArquivo.open(baseDados, ios::out | ios::app);

    procuradorArquivo << "\n"<< nome << "," << email << endl;

    procuradorArquivo.close();
 

}

int cadastrarPessoas(Pessoa vetor[], int qtdPessoas, int tamanho, string baseDados){
    if(tamanho == qtdPessoas){
        cout << "Estrutura de Dados lotada" << endl;
        return qtdPessoas;
    }

    string nome;
    string email;

    cout << "nome: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa \n pendente antes do getline
    getline(cin, nome);

    cout << "email: " << endl;
    cin >> email;

    vetor[qtdPessoas].nome = nome;
    vetor[qtdPessoas].email = email;
    qtdPessoas += 1;

    gravarPessoaBase(nome, email, baseDados);
    return qtdPessoas;
    
}
    void listarPessoas(Pessoa vetor[], int qtdPessoas){
    cout << "Listar Pessoas: " << endl;
    for(int i=0; i < qtdPessoas; i++){
        cout << "nome: "<< vetor[i].nome << endl;
        cout << "email: " << vetor[i].email << endl;
        cout << "_________________" << endl;
    }
    cout << "----------------\n";
    cout << "total de registros: " << qtdPessoas << endl;
}


void  menu(Pessoa vetor[], int tamanho, int qtdPessoas, string baseDados){
    int opcao;
    do{
        cout << "-- M E N U --\n";
        cout << "1 - listar pessoas" << endl;
        cout << "2 - cadastrar pessoa" << endl;
        cout << "3 - sair" << endl;
        cout << "opcao" << endl;
        cin >> opcao;
        fflush(stdin);
        switch (opcao)
        {
        case 1:
             listarPessoas(vetor, qtdPessoas);
                break;
        case 2:
            cout << "cadastrar Pessoa" << endl;
            qtdPessoas = cadastrarPessoas(vetor, qtdPessoas, tamanho, baseDados);
                break;
            case 3:
            cout << "sair" << endl;
                break;
        default:
            cout << "opcao invalida" << endl;
                break;
        }

    }while (opcao != 3);
    
    
    
}
void split(string vetor[], string str, string deli = " "){        
    int start = 0;
    int end = str.find(deli);
    int i = 0;
    while (end != -1) {
        vetor[i] = str.substr(start, end - start);
        i++;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    vetor[i] = str.substr(start, end - start);
}



int conectarBase(string arquivo, Pessoa vetor[], int tamanho){
    int qtdPessoas = 0;
    ifstream procuradorArquivo;   
    procuradorArquivo.open(arquivo);

    if(!procuradorArquivo){
        cout << "arquivo de base de dados não localizado" << endl;
        exit(0);
    }
    if(qtdPessoas == tamanho){
        cout << "vetor lotado. Programa Encerrado" << endl;
        exit(0);
    }

    //le o arquivo capturando as pessoas, linha a linha
    string linha;
    string vetorLinha[2];
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
        //linha = Leonardo Zorzi, leonardo.zorzi@ufn.edu.br
        split(vetorLinha, linha, ",");
        //vetorLinha[0] = "Leonardo Zorzi" vetorLinha[1] = leonardo.zorzi@ufn.edu
        vetor[qtdPessoas].nome = vetorLinha[0];//colocou no vetor principal
        vetor[qtdPessoas].email = vetorLinha[1];
        qtdPessoas += 1;
    } 
    procuradorArquivo.close();

    return qtdPessoas;
}


/*P A R T E   D O   D E S A F I O   G A R A G E M
----------------------------------------------
------------------------------------------------
-------------------------------------------------
---------------------------------------------------
-----------------------------------------------------
*/
void placaParaMaiusculo(string& placa) {//evitar sombreamento e modifica o objeto original
   for(char& ch: placa){
    ch = static_cast<char>(toupper(static_cast<unsigned char>(ch)));
   }
}

void gravarCarroBase(string placa, string dataEntrada, string baseDados){
    ofstream procuradorArquivo(baseDados, ios::out | ios::app);
    if(!procuradorArquivo){
        cout << "Falha ao abrir base de veiculos para escrita.\n";
        return;
    }
    procuradorArquivo << placa << "," << dataEntrada << "\n";
}

void salvarGaragemBase(const string& baseDados, Veiculo garagem[], int qtdCarros){
    ofstream out(baseDados, ios::out | ios::trunc);//para apagar e/ou reescrever
    if(!out){
        cout << "falha ao abrir base de veiculos" << endl;
        return;
    }
    for(int i=0; i< qtdCarros;++i){
        if(garagem[i].placa.empty()) continue;
        out << garagem[i].placa << "," << garagem[i].dataEntrada << endl;
    }
}
int conectarBaseVeiculos(const string& arquivo, Veiculo garagem[], int tamanho){
    int qtdCarros = 0;
    ifstream procuradorArquivo(arquivo);
    if(!procuradorArquivo){
        cout << "Base de veiculos nao localizada.\n";
        return 0;
    }
    if(qtdCarros == tamanho){
        cout << "garagem lotada. Programa Encerrado" << endl;
        exit(0);
    }

    //le o arquivo capturando os carros, linha a linha
    string linha;
    string vetorLinha[2];
	while (getline(procuradorArquivo, linha)) {
		getline(procuradorArquivo,linha); //lendo a linha inteira

        split(vetorLinha, linha, ",");
        string placa = vetorLinha[0];
        string data = vetorLinha[1];

        if(placa.empty()) continue;//se a placa estiver vazia, continua

        placaParaMaiusculo(placa);

        garagem[qtdCarros].placa = placa;
        garagem[qtdCarros].dataEntrada = data;
        qtdCarros++;

       
    } 
    procuradorArquivo.close();

    return qtdCarros;
}

int cadastrarCarros(Veiculo garagem[], int qtdCarros, int tamanho, string baseDados){
    if(tamanho == qtdCarros){
        cout << "Estrutura de Dados lotada" << endl;
        return qtdCarros;
    }

    string placa, dataEntrada;

    cout << "placa(AAALLLL): " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa \n pendente antes do getline
    getline(cin, placa);

    placaParaMaiusculo(placa);

    cout << "dataEntrada(HH:MM): " << endl;
    cin >> dataEntrada;

    garagem[qtdCarros].placa = placa;
    garagem[qtdCarros].dataEntrada = dataEntrada;
    ++qtdCarros;

    gravarCarroBase(placa, dataEntrada, baseDados);
    return qtdCarros;

}
    void listarCarros(Veiculo garagem[], int qtdCarros){
    cout << "Listar Carros: " << endl;
    for(int i=0; i < qtdCarros; i++){
        if(garagem[i].placa.empty()) continue;
        cout << "placa: "<< garagem[i].placa << endl;
        cout << "dataEntrada: " << garagem[i].dataEntrada << endl;
        cout << "_________________" << endl;
    }
    cout << "----------------\n";
    cout << "total de registros: " << qtdCarros << endl;
}   

    int retirarVeiculo(Veiculo garagem[], int qtdCarros, string& placaBusca){
     
        int j=0;
        bool estaGaragem = false;
        for(int i=0; i < qtdCarros;i++){
            if(!estaGaragem && garagem[i].placa == placaBusca){
                estaGaragem = true;
                continue;
            }
            garagem[j++] = garagem[i];
        }
        if(estaGaragem){
            cout << "Saida liberada para: " << placaBusca << endl;
                return j; 
        }else{
            cout << "placa nao encontrada" << endl;
                return qtdCarros;
        }
        
}

void menuVeiculos(Veiculo garagem[], int tamanho, int& qtdCarros, const string& baseDados){
        int opcao;
    do{
        cout << "\n-- M E N U  G A R A G E M --\n";
        cout << "1 - Listar carros\n";
        cout << "2 - Cadastrar carro\n";
        cout << "3 - Saida de Veiculos\n";
        cout << "4 - Sair\n";
        cout << "opcao: ";
        if(!(cin >> opcao)){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }

        switch(opcao){
            case 1:
                listarCarros(garagem, qtdCarros);
                break;
            case 2:
                qtdCarros = cadastrarCarros(garagem, qtdCarros, tamanho, baseDados);
                break;
            case 3: {
                string placa;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "informe a placa: ";
                getline(cin, placa);
                //padroniza maiusculo
                placaParaMaiusculo(placa);
                int qtdCarrosNova = retirarVeiculo(garagem, qtdCarros,placa);
                if(qtdCarrosNova != qtdCarros){
                    qtdCarros = qtdCarrosNova;
                    salvarGaragemBase(baseDados, garagem, qtdCarros);
                }
                break;
            }
            case 4:
                cout << "sair\n";
                break;
            default:
                cout << "opcao invalida\n";
        }
    } while(opcao != 4);
}
