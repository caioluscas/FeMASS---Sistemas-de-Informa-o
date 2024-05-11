//pilha.h
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Pilha{
	int qtd;  //quantidade de elementos
	int* vet; //alocação dinâmica e acesso do vetor
};
typedef struct Pilha pilha;

void init_stack(pilha* p);
void push(int x, pilha* p);
int pop(pilha* p);
int top(pilha* p);
bool isEmpty(pilha* p);
void kill_stack(pilha* p);
int size(pilha* p);	
void print(pilha* p);
