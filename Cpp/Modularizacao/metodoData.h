#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

/*#2-fazer um programa e dentro dele um método que receba o dia (string), o mês (string) e o ano (string). 
O método deve escrever 'DATA VÁLIDA' ou 'DATA INVÁLIDA' para a situação das variáveis passadas.*/

//rotina para verificar se o ano e bissexto
    bool anoBissexto(int ano){
        if((ano % 4 == 0 && ano % 100 == 0) || ano % 400 == 0)
                return true;
            return false;
    }
    // rotina para converter string para inteiro
    void data(string diasString, string mesString, string anoString){
        int dia = stoi(diasString);
        int mes = stoi(mesString);
        int ano = stoi(anoString);

        if(mes < 1 || mes > 12 ){
            cout << "data invalida!" << endl;
        }
        //vetor para declarar ate que dia vai cada mes
        int diasDoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        
        if(mes == 2 && anoBissexto(ano)){
            diasDoMes[2] = 29;
            cout << "ano bissexto" << endl;
        }

        if(dia < 1 || dia > diasDoMes[mes]){
            cout << "data invalida! " << endl;
        } else{
            cout << "data valida!" << endl;
        }
    }