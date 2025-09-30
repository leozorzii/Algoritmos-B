#pragma once
#include <string>

void ordenarLista(std::string lista[], int quantidade);
bool salvarNomeAppend(const std::string& arquivo, const std::string& nome);

bool inserirLista(const std::string& nome, std::string lista[],
                  int* quantidade, int capacidade);

int  conectarBase(std::string lista[], const std::string& arquivo, int capacidade);
void exibirListaNomes(const std::string lista[], int quantidade);

int  cadastrarNomes(const std::string& arquivo, std::string lista[], int capacidade);
