#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

/*#2-fazer um programa e dentro dele um método que receba o dia (string), o mês (string) e o ano (string). 
O método deve escrever 'DATA VÁLIDA' ou 'DATA INVÁLIDA' para a situação das variáveis passadas.*/

    void data(string dia, string mes, string ano){

        cout << "Digite a data que quiser: (dia/mes/ano)" << endl;
        cin >> dia >> mes >> ano;

       time_t data = time(nullptr);
                tm* t = localtime(&data);
                dia.data = to_string(t->tm_mday) + "/" + to_string(t->tm_mon +1) + "/" + to_string(t->tm_year + 1900);

            cout << "data valida" << endl;
    }