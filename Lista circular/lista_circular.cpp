#include <iostream>
using namespace std;

struct no
{

    int num;
    struct no *prox;
    struct no *ant;
};
typedef struct no *noPtr;

int menu()
{
    int op;
    cout << "\nMENU DE OPCOES\n";
    cout << "\nl - Inserir no inicio da lista";
    cout << "\n2 - Inserir no fim da lista";
    cout << "\n3 - Consultar a lista do inicio ao fim";
    cout << "\n4 - Consultar a lista do fim ao inicio";
    cout << "\n5 - Remover da lista";
    cout << "\n6 - Sair";
    cout << "\nDigite sua opcao: ";
    cin >> op;
    if (op < 1 || op > 6)
        cout << "Opcao invalida!";
    return op;
}

main()
{

    int op, numero, achou;
    noPtr inicio = NULL;
    noPtr fim = NULL;
    noPtr aux;

    do
    {
        op = menu();
        if (op == 1)
        {
            cout << "Digite o numero a ser inserido na lista: ";
            noPtr novo = new no;
            cin >> novo->num;
            if (inicio == NULL)
            { // Lista vazia
                inicio = novo;
                fim = novo;
                novo->prox = inicio;
                novo->ant = inicio;
            }
            else
            {
                novo->prox = inicio;
                inicio->ant = novo;
                novo->ant = fim;
                fim->prox = novo;
                inicio = novo;
            }
        }
        if (op == 2)
        {
            cout << "Digite o numero a ser inserido no fim da lista: ";
            noPtr novo = new no;
            cin >> novo->num;
            if (inicio == NULL)
            { // Lista vazia
                inicio = novo;
                fim = novo;
                novo->prox = inicio;
                novo->ant = inicio;
            }
            else
            {
                fim->prox = novo;
                novo->ant = fim;
                fim = novo;
                fim->prox = inicio;
                inicio->ant = fim;
            }
        }
        if (op == 3)
        {
            if (inicio == NULL)
            { // Lista vazia
                cout << "Lista esta vazia";
            }
            else
            {
                cout << "Consultando a lista do fim ao inicio\n ";
                aux = inicio;
                do
                {
                    cout << aux->num << " ";
                    aux = aux->prox;
                } while (aux != inicio);
            }
        }
        if (op == 4)
        {
            if (inicio == NULL)
            { // Lista vazia
                cout << "Lista esta vazia";
            }
            else
            {
                cout << "Consultando a lista do fim ao inicio\n ";
                aux = fim;
                do
                {
                    cout << aux->num << " ";
                    aux = aux->ant;
                } while (aux != fim);
            }
        }
        if (op == 5)
        {
            if (inicio == NULL)
            { // Lista vazia
                cout << "Lista esta vazia";
            }
            else
            {
                cout << "Digite o elemento a ser removido: ";
                cin >> numero;
                aux = inicio;
                achou = 0;
                int qtd = 0;
                do
                {
                    qtd++;
                    aux = aux->prox;
                } while (aux != inicio);
                int elem = 1;
                do
                {
                    if (inicio == fim && inicio->num == numero)
                    {
                        numero = NULL;
                        delete (inicio);
                        achou++;
                    }
                    else
                    {
                        if (aux->num == numero)
                        {
                            achou++;
                            if (aux == inicio)
                            {
                                inicio = aux->prox;
                                inicio->ant = fim;
                                fim->prox = inicio;
                                delete (aux);
                                aux = inicio;
                            }
                            else if (aux == fim)
                            {
                                fim = fim->ant;
                                fim->prox = inicio;
                                inicio->ant = fim;
                                delete (aux);
                                aux = NULL;
                            }
                            else
                            {
                                aux->ant->prox = aux->prox;
                                aux->prox->ant = aux->ant;
                                noPtr aux2;
                                aux2 = aux;
                                aux = aux->prox;
                                delete (aux2);
                            }
                        }
                        else
                        {
                            aux = aux->prox;
                        }
                        elem++;
                    }
                } while (elem <= qtd);
                {
                    if (achou == 0)
                        cout << "Numero nao encontrado";
                    else
                        cout << "Numero removido";
                }
            }
        }
    } while (op != 5);
}
