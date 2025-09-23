#include <iostream>
#include <cctype>
#include <string>
#include <sstream>

using namespace std;

string receberFrase() {
    cout << "Digite uma frase: " << endl;
    string frase;
    getline(cin, frase);
    return frase;
}

string retornarFrase(string frase) {
    for (char &c : frase) {
        c = toupper(c);
    }
    return frase;
}

int contarPalavras(string& frase) {
    istringstream stream(frase);
    string palavra;
    int contagem = 0;
    while (stream >> palavra) {
        contagem++;
    }
    return contagem;
}

int main() {
    string frase = receberFrase();

    string fraseMaiuscula = retornarFrase(frase);
    int totalPalavras = contarPalavras(frase);

    cout << "Original: " << frase << endl;
    cout << "Em maiusculas: " << fraseMaiuscula << endl;
    cout << "Palavras: " << totalPalavras << endl;

    return 0;
}
