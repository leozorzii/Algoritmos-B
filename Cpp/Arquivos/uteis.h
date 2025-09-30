#include <cctype>
#include <fstream>
#include <sstream>
#include <filesystem> 
#include <string>
#include <algorithm>
#include <iostream>
// C++17
#define TAM 1000


int contarVogais(string frase) {
    int totalVogais = 0;

    for (int i = 0; i < frase.size(); i++) {
        //cout << frase[i] << endl;
        if (frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U' || 
            frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u'){
                totalVogais+=1; //totalVogais++;
        }
    }

    return totalVogais;
}

string trocarCaracter(string frase, char letra) {
    for (int i = 0; i < frase.size(); i++) {
        if (toupper(frase[i]) == toupper(letra)) {
            frase[i] = '@';
        }
    }
    return frase;
}

string trocarCaracterOrigemDestino(string frase, char letraOrigem, char letraDestino) {
    for (int i = 0; i < frase.size(); i++) {
        if (toupper(frase[i]) == toupper(letraOrigem)) {
            frase[i] = letraDestino;
        }
    }
    return frase;
}

int contarPalavras(string& frase) {
    istringstream stream(frase);
    string palavra;
    int contagem = 0;
    
    // Enquanto houver palavras na frase
    while (stream >> palavra) {
        cout << palavra << endl;
        contagem++;
    }
    
    return contagem;
}

string paraMaiusculo(string frase) {
    for (int i = 0; i < frase.size(); i++) {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

bool arquivoExiste(string nomeArquivo) {
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeArquivo); 
    
    if (procuradorArquivo) { //caso arquivo exista
        procuradorArquivo.close();
        return true;
    } 
    return false; //caso arquivo nao exista
}

string copiarArquivo2String(string nomeArquivo) {
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeArquivo); 

    string resposta = "";
    string linha;
    while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		resposta = resposta + linha + "\n";
	}
  
    procuradorArquivo.close();

    return resposta;
}


int conectarBase(string listaNomes[], string nomeBaseDados, int tamanho){
     ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeBaseDados); 

   string linha;
   int quantidadeNomes =0;
    while (!procuradorArquivo.eof() && quantidadeNomes < tamanho) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		listaNomes[quantidadeNomes] = linha;
        quantidadeNomes++;
	}
  
    procuradorArquivo.close();

    return quantidadeNomes;
}


void exibirListaNomes(string listaNomes[], int quantidadeNomes){
    for(int i=0;i < quantidadeNomes ;i++){
        cout << listaNomes[i] << endl;
    }
}

bool inserirLista(string nome, string listaNomes[], int *quantidadeNomes, int tamanho){
    if(*quantidadeNomes == tamanho){
        return false;//lista lotada
    }
    
    bool encontrou = false;
    int i;
    for(int i = 0; i < *quantidadeNomes;i++){
        if(nome == listaNomes[i]){
            encontrou = true;
            break;
        }
    }
    if(encontrou){//se encontrou o nome retorna falso pq nao conseguiu inserir
        return false;
    }

    *quantidadeNomes = *quantidadeNomes + 1;
    listaNomes[*quantidadeNomes] = nome;
    
    return true;//consegui inserir na lista

}   
 //ordenar a lista de nomes
    void ordenarLista(string listaNomes[], int quantidade){
        sort(listaNomes, listaNomes + quantidade);
    }
    //salvar usando funcao append
    bool salvarNomeAppend(string &arquivo, string nome){
    //arquivo sendo aberto para append ou inserir no final
    ofstream procuradorArquivo(arquivo, ios::out | ios::app); 
    if(!procuradorArquivo){
        cout << "[ERROR] Nao abriu para escrita: " << filesystem::absolute(arquivo) << endl;
        return false;
        }
        cout << nome << '\n' << filesystem::absolute(arquivo) << endl; //confirmacao absoluta de onde esta sendo criado o arquivo
        return true;
    }


    //conferir o caminho 
    void logCaminho(string &arquivo){
        cout << "[INFO] CWD: " << filesystem::current_path() << endl;
        cout << "[INFO] base.dat absoluto: " << filesystem::absolute(arquivo) << endl;
    }
    //cadastrar os nomes
    int cadastrarNomes(string &arquivo, string listaNomes[], int tamanho){
        int quantidadeNomes = conectarBase(listaNomes, arquivo, TAM);
        ordenarLista(listaNomes, TAM);
    //listar nomes ja cadastrados
    if(quantidadeNomes > 0){
        exibirListaNomes(listaNomes, quantidadeNomes);
    }

	string nome;
	while (true) {
		cout << "Digite um nome para guardar no arquivo ou fim para encerrar: ";
		getline(cin,nome);
		fflush(stdin);

		nome = paraMaiusculo(nome);
		if (nome == "FIM"){
			break;
		}
            string base = "base.dat";
            logCaminho(base);
        if(inserirLista(nome, listaNomes, &quantidadeNomes, TAM)){//passa o endereço da variavel de nomes
        ordenarLista(listaNomes, quantidadeNomes);
            if(!salvarNomeAppend(arquivo, nome)){
                cout << "falha ao gravar no arquivo!" << endl;
                }else{
                    cout << "nome cadastrado!" << endl;
                }
            }
        }
      return quantidadeNomes;
     }
