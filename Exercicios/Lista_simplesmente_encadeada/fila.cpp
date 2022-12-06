#include <iostream>
using namespace std;

struct no
{
    int info;
    struct no *prox;
};

typedef struct no *noPtr;

noPtr inicio = NULL, fim = NULL;

void enqueue(); // colocar na fila
void dequeue(); // tirar da fila
bool listaVazia();
int menu();
void listar();

main()
{
    int op;
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            listar();
            break;
        }
    } while (op != 0);
    return 0;
}

int menu()
{
    int opcao;
    cout << "\n1. Colocar elemento na fila"
         << "\n2. Retirar elemento da fila"
         << "\n3. Imprimir elementos da fila"
         << "\n0. Sair"
         << "\nEscolha opcao: ";
    cin >> opcao;
    return opcao;
}

bool listaVazia()
{
    if (inicio)
        return false;
    else
        return true;
}

void enqueue()
{
    noPtr p = new no;
    cout << "Digite um numero inteiro: ";
    cin >> p->info;
    p->prox = NULL;
    if (listaVazia())
        inicio = p;
    else
        fim->prox = p;
    fim = p;
}

void dequeue()
{
    noPtr p;
    if (!listaVazia())
    {
        p = inicio;
        inicio = inicio->prox; // inicio = p->prox;
        if (listaVazia())
            fim = NULL;
        delete (p);
    }
    else
        cout << "\nFila vazia!";
}

void listar()
{
    noPtr p;
    if (!listaVazia())
    {
        p = inicio;
        cout << "\nINICIO --> ";
        while (p != NULL)
        {
            cout << p->info << " --> ";
            p = p->prox;
        }
        cout << "NULL\n";
    }
    else
        cout << "\nFila vazia!";
}