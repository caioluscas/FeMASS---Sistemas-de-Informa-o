//Lista.cpp

#include "Lista.h"


Lista::Lista(){ //Construtor - inicializar a lista em NULL
	this->cabeca = 0; //inicializa a lista vazia, mesmo que NULL
	this->qtd = 0;
}

Lista::~Lista(){ //Destrutor - invocar m�todo libera
	libera();
}

void Lista::insere_inicio(int i){ //Inserir dado i no in�cio da Lista
	//no_dado* novo = (no_dado*) malloc(sizeof(no_dado));
	//novo->info = i;
 	//novo->prox = this->cabeca;
 	//this->cabeca = novo; //atualiza o cabe�a para apontar ao novo 1o n�-dado
 	
	//Abordagem com objeto de classe no_dado alocado dinamicamente
	this->cabeca = new no_dado(i, this->cabeca); 
	this->qtd++; //incrementa contador de dados na Lista
}

void Lista::imprime(){ //Imprime a lista do in�cio para o fim
	if(!isEmpty(this->cabeca)){
		no_dado* p; /* vari�vel auxiliar para percorrer a lista */
 		cout << "Info: ";
		for (p = this->cabeca; p != NULL; p = p->prox)
 			cout << p->info << " - ";
 		
		cout << endl;
	} else {
		cout << "Lista � vazia!" << endl;
	}
}

bool Lista::vazia(){ //True se lista � vazia, false caso contr�rio
	return isEmpty(this->cabeca);
}

bool Lista::busca(int i){ //Busca i na Lista, retornando bool
	no_dado* p = this->cabeca;
 	for (; p!=NULL; p=p->prox)
 		if (p->info == i)
 			return 1;
 	
	return 0; /* n�o achou o elemento */
}

bool Lista::retira(int i){ //Remove 1a ocorr�ncia de i, retornando true caso encontre
	no_dado* ant = NULL; /* ponteiro para elemento anterior */
 	no_dado* p = this->cabeca; /* ponteiro para percorrer a lista*/
 	/* procura elemento na lista, guardando anterior */
 	while (p != NULL && p->info != i) {
 		ant = p;
 		p = p->prox;
 	}
 	/* verifica se achou elemento */
 	/* caso n�o achou, retorne false */
	if (p == NULL)
 		return 0; //false
 	
	/* sen�o, chou elemento para retirar e retorne true*/
 	if (ant == NULL) { /* retira elemento do inicio */
 		this->cabeca = p->prox;
 	}
 	else { /* retira elemento do meio da lista */
 		ant->prox = p->prox;
 	}
 	free(p); //desaloca o n�-dado
 	this->qtd--; //decrementa o contador de no-dados da lista
 	return 1; //true
}

int Lista::tamanho(){ //Retorna a qtd de n�s na lista
	return this->qtd;
}

void Lista::libera(){ //Libera a lista
	no_dado* p = this->cabeca;
 	while (p != NULL) {
 		no_dado* t = p->prox; /* guarda refer�ncia para o pr�ximo elemento*/
 		free(p); /* libera a mem�ria apontada por p */
 		p = t; /* faz p apontar para o pr�ximo */
	}
	this->qtd = 0;
	this->cabeca = 0;
}

bool Lista::isEmpty(no_dado* l){ //M�todo privado que auxiliar� verifica��o de lista vazia a partir de dada refer�ncia	
	return l==NULL;
}

