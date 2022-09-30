#include <iostream>
#include <iomanip>
using namespace std;
#define TOT 3

////////////// Funcionarios de uma empresa ///////////////////////

struct func
{
    int matr;
    float sal;
};
typedef struct func Tfunc;

void bubbleSort(Tfunc v[], int qtd) // ordem decrescente
{ 
    Tfunc aux;
    for (int i = 0; i < qtd; i++)
    {
        for (int j = i + 1; j < qtd; j++)
        {
            if (v[j].sal > v[i].sal)
            {
                aux = v[j];
                v[j] = v[i];
                v[i] = aux;
                // aux = 0;
            }
        }
    }
}

main()
{
    Tfunc v[TOT];
    int cont = 0;
    //string decre("");
    float soma = 0;
    float mdGeral;
    for (int i = 0; i < TOT; i++)
    {
        cout << "\nDigite matricula: ";
        cin >> v[i].matr;
        cout << "\nDigite o salario: ";
        cin >> v[i].sal;

        soma += v[i].sal;
        mdGeral = soma / TOT;
    }
    bubbleSort(v, TOT);

    cout << "\nSoma dos salarios: " << soma;
    cout << "\nSalario medio geral: " << mdGeral;

    for (int i = 0; i < TOT; i++)
    {
        //decre = decre + to_string(v[i].sal); (Transforma o sal (que é float) em string, precisa usar #include <string>)

        if (v[i].sal < mdGeral)
        {
            cont++;
            cout << "\nMatricula do menor salario: " << v[i].matr;
        }
    }
    cout << "\nQuantidade que recebe menor salario: " << cont;
    cout << fixed << setprecision(0);
    cout << "\nOrdem decrescente: ";// << decre;
    for (int i = 0; i < TOT; i++)
    {
        cout << "\nMatricula " << v[i].matr << " -  Salario: " << v[i].sal;
    }
}
