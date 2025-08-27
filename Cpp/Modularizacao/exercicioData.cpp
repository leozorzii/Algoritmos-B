#include <iostream>

using namespace std;

/*#2-fazer um programa e dentro dele um método que receba o dia (string), o mês (string) e o ano (string). 
O método deve escrever 'DATA VÁLIDA' ou 'DATA INVÁLIDA' para a situação das variáveis passadas.*/

#include "metodoData.h"

int main(){
string dia;
string mes;
string ano;

    cout << "digite o dia: " << endl;
        cin >> dia;
    cout << "digite o mes: " << endl;
        cin >> mes;
    cout << "digite o ano: " << endl;
        cin >> ano;

    data(dia, mes, ano);


    return 0;
}