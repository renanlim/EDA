#include <iostream>
#include <stdlib.h>

using namespace std;

int somar(noPtr *p){
	int num=0;
	if((p->dir==NULL && p->esq!=NULL) || (p->dir!=NULL && p->esq==NULL)){
		num+=p->valor;
	}
	if(p->dir!=NULL)
		num+=somar(p->dir);
	if(p->esq!=NULL)
		num+=somar(p->esq);
	return num;
}