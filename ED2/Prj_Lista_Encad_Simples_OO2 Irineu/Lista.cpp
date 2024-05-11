//Lista.cpp

#include "Lista.h"


Lista::Lista(){ //Construtor - inicializar a lista em NULL
	this->cabeca = 0; //inicializa a lista vazia, mesmo que NULL
	this->qtd = 0;
}

Lista::~Lista(){ //Destrutor - invocar método libera
	libera();
}

void Lista::insere_inicio(int i){ //Inserir dado i no início da Lista
	//no_dado* novo = (no_dado*) malloc(sizeof(no_dado));
	//novo->info = i;
 	//novo->prox = this->cabeca;
 	//this->cabeca = novo; //atualiza o cabeça para apontar ao novo 1o nó-dado
 	
	//Abordagem com objeto de classe no_dado alocado dinamicamente
	this->cabeca = new no_dado(i, this->cabeca); 
	this->qtd++; //incrementa contador de dados na Lista
}

void Lista::imprime(){ //Imprime a lista do início para o fim
	if(!isEmpty(this->cabeca)){
		no_dado* p; /* variável auxiliar para percorrer a lista */
 		cout << "Info: ";
		for (p = this->cabeca; p != NULL; p = p->prox)
 			cout << p->info << " - ";
 		
		cout << endl;
	} else {
		cout << "Lista é vazia!" << endl;
	}
}

bool Lista::vazia(){ //True se lista é vazia, false caso contrário
	return isEmpty(this->cabeca);
}

bool Lista::busca(int i){ //Busca i na Lista, retornando bool
	no_dado* p = this->cabeca;
 	for (; p!=NULL; p=p->prox)
 		if (p->info == i)
 			return 1;
 	
	return 0; /* não achou o elemento */
}

bool Lista::retira(int i){ //Remove 1a ocorrência de i, retornando true caso encontre
	no_dado* ant = NULL; /* ponteiro para elemento anterior */
 	no_dado* p = this->cabeca; /* ponteiro para percorrer a lista*/
 	/* procura elemento na lista, guardando anterior */
 	while (p != NULL && p->info != i) {
 		ant = p;
 		p = p->prox;
 	}
 	/* verifica se achou elemento */
 	/* caso não achou, retorne false */
	if (p == NULL)
 		return 0; //false
 	
	/* senão, chou elemento para retirar e retorne true*/
 	if (ant == NULL) { /* retira elemento do inicio */
 		this->cabeca = p->prox;
 	}
 	else { /* retira elemento do meio da lista */
 		ant->prox = p->prox;
 	}
 	free(p); //desaloca o nó-dado
 	this->qtd--; //decrementa o contador de no-dados da lista
 	return 1; //true
}

int Lista::tamanho(){ //Retorna a qtd de nós na lista
	return this->qtd;
}

void Lista::libera(){ //Libera a lista
	no_dado* p = this->cabeca;
 	while (p != NULL) {
 		no_dado* t = p->prox; /* guarda referência para o próximo elemento*/
 		free(p); /* libera a memória apontada por p */
 		p = t; /* faz p apontar para o próximo */
	}
	this->qtd = 0;
	this->cabeca = 0;
}

bool Lista::isEmpty(no_dado* l){ //Método privado que auxiliará verificação de lista vazia a partir de dada referência	
	return l==NULL;
}

