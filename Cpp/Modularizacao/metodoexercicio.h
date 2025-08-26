#include <cstdlib>
#include <time.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

//#1-fazer um programa e dentro dele um método que receba uma palavra (do tipo string) e uma letra (do tipo char). 
//O método deve contar quantas vezes a letra aparece na #palavra e exibir essa quantidade;

    void receber(string palavra, char letra){

    int cont = 0;    

    for(int i = 0 ; i < palavra.length(); i++){
        if(palavra[i] == letra){
            cont++; 
    }
}

    cout << "a letra " << letra << " aparece " << cont << " vezes" << endl;
    return;
}    