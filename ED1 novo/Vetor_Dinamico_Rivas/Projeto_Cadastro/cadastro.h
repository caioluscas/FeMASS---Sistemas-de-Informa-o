//cadastro.h
#include<iostream>
#include<stdlib.h>

using namespace std;

struct Cadastro{
	char nome[200];
	int rg;
	int cpf;
	char endereco[200];
	int quantidade;
	int* vet;
};
typedef struct Cadastro cadastro;

void iniciar_cadastro(cadastro* c);
void push(cadastro* c);
void print(cadastro* c);
bool isEmpty(cadastro* c);
int size(cadastro* c);
int pop(cadastro* c);
void kill_stack(cadastro* c);
