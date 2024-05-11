//cadastro.cpp
#include "cadastro.h"

void iniciar_cadastro(cadastro* c){
	c->quantidade = 0;
	c->vet = NULL;
}

void push(cadastro* c){
	c->quantidade++;
	if(c->quantidade == 1){
		c->vet = (int*)malloc(sizeof(int));
	}
	else{
		c->vet = (int*)realloc(c->vet, c->quantidade);
		c->vet[c->quantidade-1];
	}
	
}

void print(cadastro* c){
	if(!isEmpty(c)){
		for(int i=0; i<c->quantidade; i++){
			cout << c->vet[i] << " - " <<endl;
			c->quantidade++;
		}	
	}else{
		cout << "Nenhum usuário cadastrado!" << endl << endl;
	}	
}

bool isEmpty(cadastro* c){
	return c->quantidade == 0;
}

int size(cadastro* c){
	return c->quantidade;
}

int pop(cadastro* c){
	int x = -99;
	if(!isEmpty(c)){
		x = c->vet[c->quantidade-1];
		c->quantidade--;
		if(c->quantidade > 0){
			c->vet = (int*)realloc(c->vet, c->quantidade);
		}else{
			kill_stack(c);
		}
	}
}

void kill_stack(cadastro* c){
	free(c->vet);
	iniciar_cadastro(c);
}
