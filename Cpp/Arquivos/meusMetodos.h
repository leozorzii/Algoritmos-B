#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include<iostream>
#define TAM 1000
using namespace std;

#include "meusTipos.h"
// aqui naoooooooooooooooooooo

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












void gravarCarroBase(string placa, string dataEntrada, string baseDados){
    ofstream procuradorArquivo(baseDados, ios::out | ios::app);
    if(!procuradorArquivo){
        cout << "Falha ao abrir base de veiculos para escrita.\n";
        return;
    }
    procuradorArquivo << placa << "," << dataEntrada << "\n";
}
int conectarBaseVeiculos(const string& arquivo, Veiculo garagem[], int tamanho){
    int qtdCarros = 0;
    ifstream procuradorArquivo(arquivo);
    if(!procuradorArquivo){
        cout << "Base de veiculos nao localizada. Iniciando vazio.\n";
        return 0;
    }
    if(qtdCarros == tamanho){
        cout << "garagem lotada. Programa Encerrado" << endl;
        exit(0);
    }

    //le o arquivo capturando as pessoas, linha a linha
    string linha;
    string vetorLinha[2];
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
        //linha = Leonardo Zorzi, leonardo.zorzi@ufn.edu.br
        split(vetorLinha, linha, ",");
        string placa = vetorLinha[0];
        garagem[qtdCarros].placa = placa;
        garagem[qtdCarros].dataEntrada = vetorLinha[1];
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

    cout << "placa: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa \n pendente antes do getline
    getline(cin, placa);

    cout << "dataEntrada: " << endl;
    cin >> dataEntrada;

    garagem[qtdCarros].placa = placa;
    garagem[qtdCarros].dataEntrada = dataEntrada;
    qtdCarros += 1;

    gravarCarroBase(placa, dataEntrada, baseDados);
    return qtdCarros + 1;
    
}
    void listarCarros(Veiculo garagem[], int qtdCarros){
    cout << "Listar Carros: " << endl;
    for(int i=0; i < qtdCarros; i++){
        cout << "placa: "<< garagem[i].placa << endl;
        cout << "dataEntrada: " << garagem[i].dataEntrada << endl;
        cout << "_________________" << endl;
    }
    cout << "----------------\n";
    cout << "total de registros: " << qtdCarros << endl;
}   

    int retirarVeiculo(Veiculo garagem[], int qtdCarros, string placa){
        int j=0;
        bool estaGaragem = false;
        for(int i=0; i < qtdCarros;i++){
            if(!estaGaragem && garagem[i].placa == placa){
                estaGaragem = true;
                continue;
            }
            garagem[j++] = garagem[i];
        }
        if(estaGaragem){
            cout << "Saida liberada para: " << placa << endl;
        }else{
            cout << "placa nao encontrada" << endl;
            return j;
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
                qtdCarros = cadastrarCarro(garagem, qtdCarros, tamanho, baseDados);
                break;
            case 3: {
                string placa;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Informe placa: ";
                getline(cin, placa);
                for(auto& c: placa) c = toupper((unsigned char)c);
                qtdCarros = retirarVeiculo(garagem, qtdCarros, placa);
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
