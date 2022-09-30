#include <iostream>
using namespace std;
#define TOT 3

////////////// Metodo Selection ///////////////////////

void selectionSort(int v[], int qtd){
    int menor = 0;
    int aux = 0;
    for (int i = 0; i < qtd-1; i++)
    {
        menor = i;
        for (int j = i + 1; j < qtd; j++)
        {
            //if(v[menor]< v[j]) //decrescente
            if(v[menor]>v[j]) //crescente
            {
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
        //aux = 0;
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
    selectionSort(v, TOT);
    for (int i = 0; i < TOT; i++)
    {
        cout << v[i] << "\t";
    }
}
