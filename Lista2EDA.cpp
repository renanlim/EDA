#include <iostream>

using namespace std;

// Nó com as informações e o ponteiro para o próximo nó
struct No {
    No *prox = NULL;
    int info;
};

No *topo1 = NULL;
No *topo2 = NULL;
int ListaInt1[5] = {5, 2, 3, 1, 4};
int ListaInt2[8] = {1, 2, 4, 3, 4, 3, 1, 2};

void PrintLista(No* topo);
void CriaLista1(); // Preenche topo1 com a ListaInt1
void InsereNoLista1(int info); // Chamada pelo "CriaLista1" para inserir todos os nós
void CriaLista2(); // Preenche topo2 com a ListaInt2
void InsereNoLista2(int info); // Chamada pelo "CriaLista2" para inserir todos os nós

int Exercicio1();
int Exercicio2(int n);
No* Exercicio3(No *lista1, No *lista2);
No* Exercicio4(int n, No *lista); // Escolhendo um valor pra remover da lista
No* Exercicio4Rec(int n, No *lista); // Recursividade
No* Exercicio5(No *lista, int n); // Divide lista no primeiro nó após um nó com
No* Exercicio7(No* lista1, No* lista2);
bool Exercicio8(No* lista1, No* lista2);
No* Exercicio9(No *topo, int valor);
No* Exercicio10(No *lista, int val);

int main() // Usa isso aqui pra testar o código e as funções.
{
    // Exemplo, testando código do exercicio 7
    
    CriaLista1();
    CriaLista2();

    PrintLista(topo1);
    PrintLista(topo2);

    No *listaIntercalada = Exercicio7(topo1, topo2);
    PrintLista(listaIntercalada);

    return 0;
}

int Exercicio1()
{
    int cont = 0;
    No *no = topo1;
    while(no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

int Exercicio2(int n)
{
    int cont = 0;
    No* no = topo1;
    while (no != NULL)
    {
        if (no->info > n) 
        {
            cont++;
        }
        no = no->prox;
    }
    return cont;
}

No* Exercicio3(No *lista1, No *lista2)
{
    No *no = lista1;
    while (no->prox != NULL)
    {
        no = no->prox;
    }
    no->prox = lista2;
    
    return lista1;
}

No* Exercicio4(int n, No *lista) // Escolhendo um valor pra remover da lista
{
    No *no = lista;

    while (no->prox != NULL) // Remove todos os nós que possuem info = n
    {
        if (lista->info == n) {
            lista = lista->prox;
            delete no;
            no = lista;
        } 
        else if(no->prox->info == n) {
            No *aux = no->prox;
            no->prox = no->prox->prox;
            delete aux;
        }
        else {
            no = no->prox;
        }
    }
    return no;
}

No* Exercicio4Rec(int n, No *lista) // Recursividade
{                       // Lembrar que, como foi passado por parâmetro
    No *no = lista;     // modificar a lista não modifica o ponteiro global
    if(lista->prox != NULL)
        lista->prox = Exercicio4Rec(n, lista->prox);

    if (lista->info == n)
    {
        no = lista->prox;
        delete lista;
    }
    
    return no;
}

No* Exercicio5(No *lista, int n) // Divide lista no primeiro nó após um nó com
{                                       // info == n
    No* no = lista;     // Exercicio 5 e 6 são um só
    while (no != NULL && no->info != n)
    {
        no = no->prox;
    }

    if (no == NULL) return NULL;

    No* lista2 = no->prox;
    no->prox = NULL;
    
    return lista2;
}

No* Exercicio7(No* lista1, No* lista2)
{
    No *no1 = lista1, *no2 = lista2, *novaLista = NULL, *noPtr = NULL;

    while (no1 != NULL || no2 != NULL)
    {
        if (novaLista == NULL) {
            novaLista = new No;
            novaLista->prox = novaLista;
            noPtr = novaLista;
        }
        
        if (no1 != NULL)
        {
            noPtr = noPtr->prox;
            noPtr->info = no1->info;
            noPtr->prox = new No;
            no1 = no1->prox;
        }
        
        if (no2 != NULL)
        {
            noPtr = noPtr->prox;
            noPtr->info = no2->info;
            noPtr->prox = new No;
            no2 = no2->prox;
        }
    }

    delete noPtr->prox;
    noPtr->prox = NULL;

    return novaLista;
}

bool Exercicio8(No* lista1, No* lista2)
{
    No *node1 = lista1, *node2 = lista2;

    while (node1 != NULL && node2 != NULL)
    {
        if (node1->info != node2->info) return false;
        node1 = node1->prox;
        node2 = node2->prox;
    }
    if (node1 != node2) return false;

    return true;
}

No* Exercicio9(No *topo, int valor)
{
    No *node, *prevNode;
    No *newNode  = new No;
    newNode->info = valor;

    prevNode = topo;
    node = prevNode->prox;
    if (valor >= prevNode->info)
    {
        newNode->prox = prevNode;
        return newNode;
    }
    while (valor < node->info && node != NULL)
    {
        prevNode = node;
        node = node->prox;
    }
    prevNode->prox = newNode;
    newNode->prox = node;
    return topo;
}

No* Exercicio10(No *lista, int val)
{
    if (lista == NULL)
    {
        lista = new No;
        lista->prox = lista;
        lista->info = val;
        return lista;
    }
    
    No* no = new No;
    no->info = val;
    no->prox = lista->prox;
    lista->prox = no;
    return no;
}

void CriaLista1()
{
    for (int i = 0; i < 5; i++)
    {
        InsereNoLista1(ListaInt1[i]);
    }
}

void InsereNoLista1(int info)
{
    // O topo da lista é uma variável global com nome topo1
    No *no;
    no = new No; // Criamos o novo nó
    no->info = info; // Atribui o valor pro nó
    no->prox = topo1; // O novo nó deve apontar pro topo antigo
    topo1 = no; // O topo agora deve apontar pro novo topo
}

void CriaLista2()
{
    for (int i = 0; i < 8; i++)
    {
        InsereNoLista2(ListaInt2[i]);
    }
}

void InsereNoLista2(int info)
{
    // O topo da lista é uma variável global com nome topo2
    No *no;
    no = new No; // Criamos o novo nó
    no->info = info; // Atribui o valor pro nó
    no->prox = topo2; // O novo nó deve apontar pro topo antigo
    topo2 = no; // O topo agora deve apontar pro novo topo
}

void PrintLista(No* topo)
{
    No* no = topo;
    cout << endl;
    while (no != NULL)
    {
        cout << no->info << ", ";
        no = no->prox;
    }
    cout << endl;
}