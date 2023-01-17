#include <iostream>
#define TAM 10
using namespace std;

void subir(int[], int);
void descer(int[], int, int);
void inserir(int[], int *);
void remover(int[], int *);
void listar(int[], int);
void troca(int *, int *);

main()
{
    int op, v[TAM], tamanho = 0;

    do
    {
        cout << "\n1- Inserir elemento\n2- Remover primeiro elemento\n3- Listar" << endl;
        cout << "Escolha uma opcao: ";
        cin >> op;
        switch (op)
        {
        case 1:
            inserir(v, &tamanho);
            break;
        case 2:
            remover(v, &tamanho);
            break;
        case 3:
            listar(v, tamanho);
            break;
        }
    } while (op != 0);
    cout << "Fim do programa";
}

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void subir(int v[], int i)
{
    int j = i / 2;
    if (j >= 0 && v[i] > v[j])
    {
        troca(&v[i], &v[j]);
        subir(v, j);
    }
}

void descer(int v[], int i, int t)
{
    int e = 2 * i + 1;
    int d = 2 * i + 2;
    int idMaior = i;

    if (d < t && v[d] > v[idMaior])
        idMaior = d;
    if (e < t && v[e] > v[idMaior])
        idMaior = e;
    if (i != idMaior)
    {
        troca(&v[i], &v[idMaior]);
        descer(v, idMaior, t);
    }
}

void inserir(int v[], int *t)
{
    if ((*t) < TAM)
    {
        cout << "\nEntre com o valor: ";
        cin >> v[(*t)];
        subir(v, (*t));
        (*t)++;
    }
    else
        cout << "\nErro! Tamanho maximo atingido" << endl;
}

void remover(int v[], int *t)
{
    cout << "\nElemento removido: " << v[0] << endl;
    --(*t);
    v[0] = v[(*t)];
    descer(v, 0, *t);
}

void listar(int v[], int t)
{
    int i;
    cout << "\nLista: ";
    for (i = 0; i < t; i++)
        cout << v[i] << "  ";
    cout << endl;
}