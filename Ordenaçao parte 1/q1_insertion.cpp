#include <iostream>
using namespace std;
#define TOT 5

////////////// Metodo Insertion ///////////////////////

void insertionSort(int v[], int qtd){
    for (int i = 1; i < qtd; i++)
    {
        int chave = v[i];
        int j = i - 1;
        while (chave < v[j] && j >= 0)
        {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = chave;
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
    insertionSort(v, TOT);
    for (int i = 0; i < TOT; i++)
    {
        cout << v[i] << "\t";
    }
}