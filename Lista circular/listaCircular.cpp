#include <iostream>
#include <stdlib.h>
using namespace std;

struct no
{
    int valor;
    no *prox;
};
typedef no *noPtr;

void inserir(noPtr *);
void remover(noPtr *);
void listar(noPtr *);

main()
{
    int op;
    noPtr topo = NULL;

    do
    {
        cout << "\n1- inserir um elemento\n2- remover o primeiro elemento\nEscolha uma opcao: ";
        cin >> op;
        switch (op)
        {
        case 1:
            inserir(&topo);
            break;
        case 2:
            remover(&topo);
            break;
        }
        listar(&topo);
    } while (op == 1 || op == 2);
    cout << "\n\nFim do programa" << endl;
}

void inserir(noPtr *t)
{
    no *aux = new no;
    cout << "\nEntre com o valor: ";
    cin >> aux->valor;
    if (*t == NULL)
    {
        aux->prox = aux;
        *t = aux;
    }
    else
    {
        noPtr p = *t;
        while (p->prox != *t)
        {
            p = p->prox;
        }
        aux->prox = *t;
        p->prox = aux;
    }
}

void remover(noPtr *t)
{
    if (*t == NULL)
        cout << "\nErro! A lista esta vazia" << endl;
    else
    {
        noPtr p = *t;
        if (*t == (*t)->prox)
        {
            *t = NULL;
            delete (p);
        }
        else
        {
            noPtr aux = *t;
            while (p->prox != *t)
            {
                p = p->prox;
            }
            p->prox = (*t)->prox;
            *t = (*t)->prox;
            delete (aux);
        }
    }
}

void listar(noPtr *t)
{
    if (*t == NULL)
        cout << "\nA lista está vazia" << endl;
    else
    {
        noPtr aux = *t;
        cout << "\nLista: ";
        do
        {
            cout << aux->valor << " - ";
            aux = aux->prox;
        } while (aux != *t);
        cout << endl;
    }
}