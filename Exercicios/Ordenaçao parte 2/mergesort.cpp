#include <iostream>
using namespace std;
#define TOT 5

////////////// Metodo Mergesort ///////////////////////

void intercala(int v[], int inicio, int fim, int meio){
    int i, aux[TOT], posLivre = inicio, inicioA1 = inicio, inicioA2 = meio + 1;
    
    while (inicioA1 <= meio && inicioA2 <= fim){
        if (v[inicioA1] > v[inicioA2]){
            aux[posLivre] = v[inicioA2];
            inicioA2++;
            } else {
                aux[posLivre] = v[inicioA1];
                inicioA1++;
            }
        posLivre++;
    } // término do while

    for (i = inicioA1; i <= meio; i++){ // elems. do 1o. array que não foram intercalados
        aux[posLivre] = v[i];
        posLivre++;
    }
    for (i = inicioA2; i <= fim; i++){ // elems. do 2o. array que não foram intercalados
        aux[posLivre] = v[i];
        posLivre++;
    }
    for (i = inicio; i <= fim; i++) // atualiza array A conforme array auxiliar
        v[i] = aux[i];
    } // término da função intercala()

void mergesort(int v[], int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = (inicio + fim)/2;
        mergesort(v, inicio, meio);
        mergesort(v, meio + 1, fim);
        intercala(v, inicio, fim, meio);
    }
}

main(){
    int v[TOT], i;
    int inicio = 0;
    int fim = TOT-1;
    for (i = 0; i < TOT; i++)
    {
        cout << "Entre com o " << i + 1 << "o. numero: ";
        cin >> v[i];
    }
    mergesort(v, inicio, fim);
    for (i = 0; i < TOT; i++)
        cout << v[i] << "\t";
}
