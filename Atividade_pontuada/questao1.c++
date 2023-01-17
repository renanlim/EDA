#include <iostream>
#include <stdlib.h>

using namespace std;

struct folha{
	int valor;
	struct folha *esq, *dir;
};
typedef struct folha* no;

void inserir(no *p, int num){
	no aux= new folha;
	aux->valor=num;
	if((*p)==NULL){
		aux->dir=NULL;
		aux->esq=NULL;
		*p=aux;
	}
	else{
		if(aux->valor < (*p)->valor)
			inserir(&(*p)->esq, num);
		else
			inserir(&(*p)->dir, num);
	}
}

void listar(no p){ 
	if(p!=NULL){
		listar(p->esq);
		cout<<"  "<< p->valor;
		listar(p->dir);
	}
}

main(){
	int op, num;
	no raiz=NULL;
	
	do{
		cout<<"Escolha uma opcao: ";
		cout<<"\n1 - Inserir no na arvore\n2 - Listar nos"<<endl;
		cin>>op;
		switch(op){
			case 1: cout<<"\nDigite o valor do no: ";
				cin>>num; 
				inserir(&raiz, num);
				break;
			case 2: cout<<"\nNos em ordem crescente:";
				listar(raiz);
				break;
		}
	}while(op>0 && op<3);
	
}