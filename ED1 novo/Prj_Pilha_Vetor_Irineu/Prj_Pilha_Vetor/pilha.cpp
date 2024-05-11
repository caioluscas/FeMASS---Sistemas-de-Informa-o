//pilha.cpp
#include "pilha.h"

void init_stack(pilha* p){
	p->qtd = 0;
	p->vet = NULL;
}

void push(int x, pilha* p){
	p->qtd++;
	if (p->qtd == 1)
		p->vet = (int*) malloc(sizeof(int));
	else 
		p->vet = (int*) realloc(p->vet, p->qtd);
	
	p->vet[p->qtd-1] = x;
}

int pop(pilha* p){
	int x = -99;
	if (!isEmpty(p)){
		x = p->vet[p->qtd-1];
		p->qtd--;
		if (p->qtd > 0)	
			p->vet = (int*) realloc(p->vet, p->qtd);
		else
			kill_stack(p);	 
	}
	return x;
}

int top(pilha* p){
	int x = -99;
	if (!isEmpty(p)){
		x = p->vet[p->qtd-1];
	}
	return x;
}

bool isEmpty(pilha* p){
	return p->qtd == 0;
}

void kill_stack(pilha* p){
	free(p->vet);
	init_stack(p);
}

int size(pilha* p){
	return p->qtd;
}

void print(pilha* p){
	if (!isEmpty(p)){
		for (int i=0; i<p->qtd; i++)
			cout << p->vet[i] << " - ";
		cout << "> [top]" << endl;	
	} else
		cout << "Stack is empty!\n";
}
