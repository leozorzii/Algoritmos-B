/*Exercício 2.1: Listar Produtos em Estoque
Crie um programa que cadastre 5 produtos em um vetor 
(você pode pedir para o usuário ou já deixar os valores no código para facilitar).
Depois de cadastrar, o programa deve percorrer o vetor e exibir apenas o nome e o preço
 dos produtos que têm mais de 10 unidades em estoque.

Exercício 2.2: Busca por Código
Peça para o usuário digitar o codigo de um produto.
Seu programa deve buscar no vetor por um produto com aquele código.
Se encontrar, exiba todos os dados do produto.
Se não encontrar, exiba a mensagem: "Produto não encontrado.".

Exercício 2.3: Relatório de Estoque
Percorra o vetor e, ao final, exiba:
O nome e o preço do produto mais caro.
O nome e a quantidade do produto com o maior estoque.
O valor total do estoque (soma de preco * quantidadeEmEstoque de todos os produtos).*/

#include <iostream>
#include <string>
#include <ctime>
#include <limits>

using namespace std;


int main(){

    struct Produto {
    string nome;
    int codigo;
    float preco;
    int quantidadeEmEstoque;
};
    Produto cadastro[5];
    for(int i = 0;i < 5;i++){
    cout << " digite o nome do produto" << endl;
        cin.ignore();
        getline(cin, cadastro[i].nome);

    cout << "digite o codigo do produto: " << endl;
        cin >> cadastro[i].codigo;

    cout << "digite o preço do produto: " << endl;
        cin >> cadastro[i].preco;

    cout << "digite a quantidade do produto em estoque: " << endl;
        cin >> cadastro[i].quantidadeEmEstoque;
    
    }
    cout << "LISTAGEM DOS PRODUTOS COM MAIS DE 10 EM ESTOQUE" << endl;
    for(int i = 0;i < 5;i++){
    if(cadastro[i].quantidadeEmEstoque > 10){
        cout << "nome do produto: " << cadastro[i].nome << endl;
        cout << "preço do produto: R$" << cadastro[i].preco << endl;
         cout << "-----------------------------" << endl;
        }
    }
    int acharViaCodigo;

    cout << "digite o numero do codigo que quer buscar: " << endl;
    cin >> acharViaCodigo;

    bool encontrado = false;
    for(int i = 0 ;i < 5;i++){
        if(cadastro[i].codigo == acharViaCodigo){
            cout << "Produto: " << cadastro[i].nome << endl;
            cout << "--------------------" << endl;
            cout << "Valor: R$ " << cadastro[i].preco << endl;
            cout << "--------------------" << endl;
            cout << "Estoque: " << cadastro[i].quantidadeEmEstoque << endl;
            encontrado = true;
            break;
        } 
        if(!encontrado){
            cout << "Produto nao encontrado!!!" << endl;
        }
    }

        int MaisCaro = 0;
        int MaiorEstoque = 0;
        int valorTotal = 0;
        for(int i = 0;i < 5;i++){
            if(cadastro[i].preco > cadastro[MaisCaro].preco){
                MaisCaro = 1;
            }
            if(cadastro[i].quantidadeEmEstoque > cadastro[MaiorEstoque].quantidadeEmEstoque){
                MaiorEstoque = 1;
            }
            valorTotal += cadastro[i].preco * cadastro[i].quantidadeEmEstoque;

        }

        cout << "-- RELATORIO DO ESTOQUE -- " << endl;
        cout << "Produto mais caro: " << cadastro[MaisCaro].nome << endl;
        cout << "Preço: " << cadastro[MaisCaro].preco << endl;
        cout << "--------------------------" << endl;
        cout << "Produto com Maior estoque: " << cadastro[MaiorEstoque].nome << endl;
        cout << "Quantidade em Estoque: " << cadastro[MaiorEstoque].quantidadeEmEstoque << endl;
        cout << "--------------------------" << endl;
        cout << "Valor Total em Estoque: " << valorTotal << endl;
        // Sempre que for acessar algo da struct dentro do vetor, precisa usar cadastro[i].atributo
    return 0;
}