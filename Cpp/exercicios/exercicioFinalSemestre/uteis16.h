#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <algorithm>
#include <iomanip>
#include "tipos16.h" 

#define TAM 1000 

using namespace std;

void regravarBaseCompleta(Jogador vetor[], int qtdJogadores, const string& baseDados);

void gravarBase(string name, string tag, string level,double kd, string baseDados){
    ofstream procuradorArquivo; 
    procuradorArquivo.open(baseDados, ios::out | ios::app);

    procuradorArquivo << name << "/" << tag << "/" << level << "/" << kd << endl;

    procuradorArquivo.close();
}

void split(string vetor[], string str, string deli = ","){      
    int start = 0;
    int end = str.find(deli);
    int i = 0;
    while (end != -1) {
        vetor[i] = str.substr(start, end - start);
        i++;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    if (i < 3) { 
        vetor[i] = str.substr(start, end - start);
    }
}

int conectarBase(string arquivo, Jogador vetor[], int tamanho){
    int qtdJogadores = 0;
    ifstream procuradorArquivo;   
    procuradorArquivo.open(arquivo);

    if(!procuradorArquivo.is_open()){
        cout << "Arquivo de base de dados nao localizado. Criando um novo arquivo." << endl;
        ofstream novoArquivo(arquivo);
        novoArquivo.close();
        return 0; 
    }
    
    string linha;
    string vetorLinha[4];
    
    while (getline(procuradorArquivo, linha)) {
        if (qtdJogadores == tamanho) {
            cout << "Vetor lotado. Dados adicionais nao serao carregados." << endl;
            break;
        }

        
        if (linha.empty() || linha.find_first_not_of(" \n\t") == string::npos) continue; 

        split(vetorLinha, linha, ",");
            
        try {
            vetor[qtdJogadores].username = vetorLinha[0];
            vetor[qtdJogadores].tag = vetorLinha[1];
            vetor[qtdJogadores].level = vetorLinha[2];
            
            // CONVERSÃO DE STRING PARA DOUBLE (stod)
            vetor[qtdJogadores].kd = stod(vetorLinha[3]); 
            
            qtdJogadores += 1;

        } catch (const std::invalid_argument& e) {
          
        }
    } 
    procuradorArquivo.close();

    return qtdJogadores;

    
}
string gerarTag(string& username){
    string tagGerada = "";

    if(username.length() >=3){
        tagGerada = username.substr(0 , 3);
    }else{
        //caso a tag gerada seja mt pequena
        cout << "sua tag sera definida como seu username inteiro" << endl;
        tagGerada = username;
    }
    transform(tagGerada.begin(), tagGerada.end(), tagGerada.begin(), ::toupper);
    return tagGerada;
}

int cadastrarJogador(Jogador vetor[], int qtdJogadores, int tamanho, string baseDados){
    if(tamanho == qtdJogadores){
        cout << "Estrutura de Dados lotada" << endl;
        return qtdJogadores;
    }

    static bool semente_inicializada = false;
    if(!semente_inicializada){
        srand(time(0));
        semente_inicializada = true;
    }

    string name;
    string tag;
    string level;

    cout << "\n--- CADASTRO DE JOGADOR ---\n";
    cout << "Seu username: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, name);

    tag = gerarTag(name);
    cout << "Tag gerada automcaticamente: " << "(" << tag << ")"<< endl;

    cout << "Seu level: " << endl;
    cin >> level;

    int random_int = rand() % 351 + 50;

    double kd_Gerado = random_int / 100.0;
    

    vetor[qtdJogadores].username = name;
    vetor[qtdJogadores].tag = tag;
    vetor[qtdJogadores].level = level;
    vetor[qtdJogadores].kd = kd_Gerado;

    gravarBase(name, tag, level, kd_Gerado, baseDados); 

    cout << "Jogador cadastrado com sucesso!" << endl;
    return qtdJogadores + 1;
}

void listarJogadores(Jogador vetor[], int qtdJogadores){
    cout << "\n--- LISTA DE JOGADORES ---\n";
    if (qtdJogadores == 0) {
        cout << "Nenhum jogador cadastrado." << endl;
        return;
    }
    for(int i=0; i < qtdJogadores; i++){
        cout << "User: "<< vetor[i].username << endl;
        cout << "Tag: " << vetor[i].tag << endl;
        cout << "Level: " << vetor[i].level << endl;
        cout << "KD:" << fixed << setprecision(2) << vetor[i].kd << endl;
        cout << "_________________" << endl;
    }
    cout << "----------------\n";
    cout << "Total de registros: " << qtdJogadores << endl;
}

void regravarBaseCompleta(Jogador vetor[], int qtdJogadores, const string& baseDados){
    ofstream procuradorArquivo(baseDados, ios::out | ios::trunc); // Abre para escrita, truncando (limpando)
    
    for (int i = 0; i < qtdJogadores; i++) {
        procuradorArquivo << vetor[i].username << "," << vetor[i].tag << "," << vetor[i].level << "," << fixed << setprecision(2) << vetor[i].kd << endl;
    }
    procuradorArquivo.close();
    cout << "Base de dados regravada com sucesso." << endl;
}

string tagParaMaiusculo(string gerarTag) {
    for (int i = 0; i < gerarTag.size(); i++) {
        gerarTag[i] = toupper(gerarTag[i]);
    }
    return gerarTag;
}


int removerUsuarioPorTag(Jogador vetor[], int qtdJogadores, string& tagParaRemover, string& baseDados){
    
     string tagBuscaUpper = tagParaMaiusculo(tagParaRemover);

    listarJogadores(vetor, qtdJogadores);

    int indiceEncontrado = -1;

    for(int i = 0; i < qtdJogadores; i++){
        string tagJogadorUpper = tagParaMaiusculo(vetor[i].tag);
        
        if(tagJogadorUpper == tagBuscaUpper){ 
            indiceEncontrado = i;
            break;
        } 
    }

    if(indiceEncontrado != -1){
        for(int i = indiceEncontrado; i < qtdJogadores - 1; i++){
            vetor[i] = vetor[i+1]; 
        }

    if(indiceEncontrado != -1){
        for(int i = indiceEncontrado; i < qtdJogadores - 1; i++){
            vetor[i] = vetor[i+1]; 
        }
    }
        
        cout << "Jogador com a tag: " << tagParaRemover << " removido da memoria com sucesso!" << endl;
        
        regravarBaseCompleta(vetor, qtdJogadores - 1, baseDados); 

        return qtdJogadores - 1; 
    } else {
        cout << "A tag: " << tagParaRemover << " nao foi encontrada!" << endl;
        return qtdJogadores;
    }
}

void pesquisarJogador(Jogador vetor[], int qtdJogadores){
    string termoBusca;
    cout << "\n--- PESQUISAR JOGADOR ---\n";
    cout << "Digite o username ou tag para buscar: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, termoBusca);

    bool encontrado = false;
    cout << "\nResultado da busca por '" << termoBusca << "':" << endl;

    for(int i=0; i < qtdJogadores; i++){
        if (vetor[i].username.find(termoBusca) != string::npos || vetor[i].tag == termoBusca) {
            cout << "ENCONTRADO na posicao: " << i << "\nUser: " << vetor[i].username << "\nTag: " << vetor[i].tag << "\nLevel: " << vetor[i].level << "\nKD: " << vetor[i].kd << endl;
            encontrado = true;
        }
    }
    
    if (!encontrado) {
        cout << "Nenhum jogador encontrado com o termo informado." << endl;
    }
}   

void menuJogadores(Jogador vetor[], int tamanho, int qtdJogadores, string baseDados){
    int opcao;
    string tagParaRemover;

    do{
        cout << "\n-- M E N U --\n";
        cout << "1 - Listar Jogadores" << endl;
        cout << "2 - Cadastrar Jogador" << endl;
        cout << "3 - Remover Jogador por Tag" << endl;
        cout << "4 - Pesquisar Jogador" << endl;
        cout << "5 - Sair" << endl;
        cout << "Opcao: ";
        

        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcao = 0; 
        }
        
        
        switch (opcao)
        {
        case 1:
            listarJogadores(vetor, qtdJogadores);
            break;
        case 2:
            qtdJogadores = cadastrarJogador(vetor, qtdJogadores, tamanho, baseDados);
            break;
        case 3:
            cout << "Digite a Tag do jogador para remover: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, tagParaRemover);
            qtdJogadores = removerUsuarioPorTag(vetor, qtdJogadores, tagParaRemover, baseDados); 
            break;
        case 4:
            pesquisarJogador(vetor, qtdJogadores);
            break;
        case 5:
            cout << "Saindo do programa..." << endl;
            break;
        default:
            cout << "Opcao invalida" << endl;
            break;
        }

    }while (opcao != 5);
}