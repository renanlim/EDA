#include <iostream>
using namespace std;
#define TOT 50

////////////// Metodo BubbleSort ///////////////////////

void bubbleSort(int v[], int qtd){ //ordem crescente
    int aux = 0;
    for (int i = 0; i < qtd; i++)
    {
        for (int j = i + 1; j < qtd; j++)
        {
            if(v[i]>v[j]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                //aux = 0;
            }
        }
    }
}

main (){
    int v[TOT];
    int num;
    for (int i = 0; i < TOT; i++)
    {
        cout << "\nDigite o " << i+1 << " numero (sem repeticao): ";
        cin >> v[i];
    }
    bubbleSort(v, TOT);
    for (int i = 0; i < TOT; i++)
    {
        cout << v[i];
    }
}
