#include <iostream>
using namespace std;

struct no
{
    int info;
    struct no *prox;
};
typedef struct no *noPtr;
noPtr topo = NULL;


void push();
void pop();
void printList();
bool listaVazia();

void push()
{
    noPtr p;
    int valor;
    p = new no; // ou p = (noPtr) malloc (sizeof (struct no));
    cout << "Digite o valor do elemento: ";
    cin >> valor;
    p->info = valor;
    p->prox = topo;
    topo = p;
}

void pop()
{
    noPtr p = topo;
    if (!listaVazia())
    {
        topo = topo->prox; // ou topo = p->prox;
        delete (p);        // ou free(p); - usado com malloc()
        cout << "\nO elemento foi retirado da pilha." << endl;
    }
    else
        cout << "\nLista vazia!" << endl;
}

bool listaVazia()
{
    if (topo)
        return false;
    else
        return true;
}

void printList()
{
    noPtr p = topo;

    if (!listaVazia())
    {
        cout << "\n\ntopo -> ";
        while (p != NULL)
        {
            cout << p->info << "\t";
            p = p->prox;
        }
        cout << "-> fim\n\n ";
    }
    else
        cout << "\nLista vazia!" << endl;
}

main()
{
      int op;

      do {
      	  cout  << "\n1. Empilhar"
      	  		<< "\n2. Desempilhar"
      	  		<< "\n3. Listar elementos da pilha"
      	  		<< "\n0. Sair"
      	  		<< "\n\nInforme a opcao: ";
          cin >> op;
          switch(op)
          {
             case 1: push(); break;
             case 2: pop(); break;
             case 3: printList(); break;
             }
      } while (op !=0);
}