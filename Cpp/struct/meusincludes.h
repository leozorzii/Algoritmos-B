   #include <string.h>

      typedef struct{
    string nome;
    string celular;
    string data;
    string descricao;
    string hora;

}Emprestimo;


//MENU
void exibirMenu() {
   cout << "M E N U" << endl;
    cout << "1 - Emprestar" << endl;
    cout << "2 - Devolver" << endl;
    cout << "3 - Listar emprestimos" << endl;
    cout << "4 - Buscar" << endl;
    cout << "5 - Sair" << endl;
    cout << "Opcao: ";
}

//EMPRESTAR
void emprestarItem(Emprestimo itens[], int &qtd){
   cout << "AREA DE EMPRESTIMO" << endl;
    if (qtd == TAM) {
        cout << "Voce nao pode mais emprestar itens. Limite atingido." << endl;
        return;
    }

    Emprestimo novoItem;
    cout << "Pessoa: ";
    getline(cin, novoItem.nome);

    cout << "Numero de Celular: ";
    getline(cin, novoItem.celular);

    cout << "Item: ";
    getline(cin, novoItem.descricao);

    // Rotina para verificar se o item já foi emprestado (CORRIGIDA)
    bool existe = false;
    for (int i = 0; i < qtd; ++i) {
        if (itens[i].descricao == novoItem.descricao) {
            existe = true;
            break;
        }
    }

    if (existe) {
        cout << "Erro: Este item ja esta emprestado!" << endl;
        return; // Sai da função
    }

    // Rotina para capturar data e hora
    time_t agora = time(nullptr);
    tm* t = localtime(&agora);
    novoItem.data = to_string(t->tm_mday) + "/" + to_string(t->tm_mon + 1) + "/" + to_string(t->tm_year + 1900);
    novoItem.hora = to_string(t->tm_hour) + ":" + to_string(t->tm_min);

    cout << "Data: " << novoItem.data << endl;
    cout << "Hora: " << novoItem.hora << endl;

    // Armazenar na base temporaria
    itens[qtd] = novoItem;
    qtd++;
    cout << "Item registrado com sucesso..." << endl;
}

//DEVOLVER
void devolverItem(Emprestimo itens[], int &qtd){
   cout << "AREA DE DEVOLUCAO" << endl;
    if (qtd == 0) {
        cout << "Nenhum item esta emprestado para devolver." << endl;
        return;
    }

    string itemParaDevolver;
    cout << "Digite a descricao do item a ser devolvido: ";
    getline(cin, itemParaDevolver);

    int indiceParaRemover = -1;
    // Encontra o índice do item a ser removido
    for (int i = 0; i < qtd; ++i) {
        if (itens[i].descricao == itemParaDevolver) {
            indiceParaRemover = i;
            break;
        }
    }

    if (indiceParaRemover == -1) {
        cout << "Item nao encontrado na lista de emprestimos." << endl;
    } else {
        // "Empurra" todos os elementos para a esquerda, sobrescrevendo o item removido
        for (int i = indiceParaRemover; i < qtd - 1; ++i) {
            itens[i] = itens[i + 1];
        }
        qtd--; // Diminui a quantidade total de itens
        cout << "Item devolvido com sucesso!" << endl;
    }
}

//LISTAR
void listarItens(const Emprestimo itens[], int &qtd){
   cout << "LISTAGEM DE EMPRESTIMOS" << endl;
    if (qtd == 0) {
        cout << "Nenhum item esta emprestado." << endl;
    } else {
        for (int i = 0; i < qtd; i++) {
            cout << "------------------------" << endl;
            cout << "Item: " << itens[i].descricao << endl;
            cout << "Pessoa: " << itens[i].nome << endl;
            cout << "Numero: " << itens[i].celular << endl;
            cout << "Data: " << itens[i].data << endl;
            cout << "Horario: " << itens[i].hora << endl;
            cout << "------------------------" << endl;
        }
    }
}

//BUSCAR
void buscarItem(const Emprestimo itens[], int qtd){
   cout << "BUSCAR ITEM" << endl;
    if (qtd == 0) {
        cout << "Nenhum item esta emprestado para buscar." << endl;
        return;
    }

    string termoBusca;
    cout << "Digite o nome da pessoa ou a descricao do item: ";
    getline(cin, termoBusca);

    bool encontrado = false;
    cout << "\n--- Resultados da Busca ---" << endl;
    for (int i = 0; i < qtd; i++) {
        // Procura o termo na descrição OU no nome (não diferencia maiúsculas/minúsculas seria um próximo passo)
        if (itens[i].descricao.find(termoBusca) != string::npos || itens[i].nome.find(termoBusca) != string::npos) {
            cout << "------------------------" << endl;
            cout << "Item: " << itens[i].descricao << endl;
            cout << "Pessoa: " << itens[i].nome << endl;
            cout << "Numero: " << itens[i].celular << endl;
            cout << "Data: " << itens[i].data << endl;
            cout << "Horario: " << itens[i].hora << endl;
            cout << "------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Nenhum item encontrado com o termo '" << termoBusca << "'." << endl;
    }
}