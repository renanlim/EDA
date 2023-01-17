#include <iostream>
using namespace std;
#include <stdlib.h>// srand, rand contém várias funções e constantes básicas
#define TOT 5


// função que realiza a troca entre dois elementos
void troca(int v[], int i, int j)
{
	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

// particiona e retorna o índice do pivô
int particiona(int v[], int inicio, int fim)
{
	int pivo, pivo_indice, i;
	
	pivo = v[fim]; // o pivô é sempre o último elemento
	pivo_indice = inicio;
	
	for(i = inicio; i < fim; i++)
	{
		// verifica se o elemento é <= ao pivô
		if(v[i] <= pivo)
		{
			// realiza a troca
			troca(v, i, pivo_indice);
			// incrementa o pivo_indice
			pivo_indice++;
		}
	}
	
	// troca o pivô
	troca(v, pivo_indice, fim);
	
	// retorna o índice do pivô
	return pivo_indice;
}

// escolhe um pivô aleatório para evitar o pior caso do quicksort
int particiona_random(int v[], int inicio, int fim)
{
	// seleciona um número entre fim (inclusive) e inicio (inclusive)
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
	
	// faz a troca para colocar o pivô no fim
	troca(v, pivo_indice, fim);
	// chama a particiona
	return particiona(v, inicio, fim);
}

void quick_sort(int v[], int inicio, int fim)
{
	if(inicio < fim)
	{
		// função particionar retorna o índice do pivô
		int pivo_indice = particiona_random(v, inicio, fim);
		
		// chamadas recursivas quick_sort
		quick_sort(v, inicio, pivo_indice - 1);
		quick_sort(v, pivo_indice + 1, fim);
	}
}
main()
{
	// vetor que será ordenado
	int v[TOT];
	int i;
	for (i = 0; i < TOT; i++)
    {
        cout << "Entre com o " << i + 1 << "o. numero: ";
        cin >> v[i];
    }
	// chamada do quicksort
	quick_sort(v, 0, TOT - 1);

	// mostra o vetor ordenado
	 for (i = 0; i < TOT; i++)
        cout << v[i] << "\t";
}