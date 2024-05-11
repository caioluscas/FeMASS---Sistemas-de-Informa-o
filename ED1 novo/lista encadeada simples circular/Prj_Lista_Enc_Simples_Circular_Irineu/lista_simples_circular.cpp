//Aula ED - prof. Irineu
//lista_simples_circular.cpp
#include "lista_simples_circular.h"


/* fun��o de inicializa��o: retorna uma lista vazia */
Lista* inicializa(){ //ok
	return NULL;
}

bool vazia(Lista* l){ //verifica se lista est� vazia: true caso positivo!
	return l == NULL;
}

/* inser��o no in�cio: retorna a lista atualizada */
Lista* insere_inicio(Lista* l, int i){
	//l � ponteiro para �ltimo n�-dado, l->prox estar� apontando para 1o n�-dado
	//criando novo n�-dado
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	
	//testar se � o primeiro encadeamento
	if (vazia(l)){
		novo->prox = novo;
		return novo;
	}else{
		novo->prox = l->prox; //faz novo se o 1o, e o antigo 1� ser segundo...
		l->prox = novo; //atualiza o encadeamento do n�-final com o novo 1o n�-dado
	}
	return l;	
}

/* inser��o no fim: retorna a lista atualizada */
Lista* insere_fim(Lista* l, int i){
	
	if (vazia(l)) //se for 1a inser��o... delega para insere_inicio
		return insere_inicio(l, i);
	
	//sen�o... faz-se o �ltimo virar pen�ltimo...
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
	novo->prox = l->prox;
	l->prox = novo;
	return novo;
}

/* fun��o imprime: imprime valores dos elementos */
void imprime(Lista* l){
	if (!vazia(l)){
		Lista* p = l->prox; /* vari�vel auxiliar aponta para n� inicial */
	 	printf("Info: ");
		do{ //garantir a travessia da lista mesmo no caso de �nico n�, partindo do inicial e usando-o tb para teste final
			printf("%d - ", p->info);	
			p = p->prox;
		}while(p !=l->prox); 
		printf("\n"); 
	}else printf("Lista eh vazia!\n");
}

/* fun��o retira: retira elemento da lista */
Lista* retira (Lista* l, int v) {
	if(vazia(l)){
		printf("Lista vazia!\n");
		return l;
	}
		
	Lista* ant = NULL; /* ponteiro para elemento anterior */
	Lista* p = l->prox; /* ponteiro para percorrer a lista*/
 	/* procura elemento na lista, guardando anterior */
	do{ //garantir a travessia da lista mesmo no caso de �nico n�, partindo do inicial e usando-o tb para teste final
		if (p->info == v)
			break;
		ant = p;
		p = p->prox;	
	}while(p != l->prox); 
	
 	/* verifica se achou elemento */
 	if (ant != NULL && p == l->prox) //ok
 		return l; /* n�o achou: retorna lista original */
 	//verifica se h� apenas 1 n�-dado
 	if (p == p->prox){ 
 		free(p);
 		return NULL;
	}
	//achou n�-dado numa lista com 2 ou mais elementos 
	if (ant == NULL && p == l->prox){//ok //primeiro n�-dado em p
		l->prox = p->prox; //�ltimo aponta para segundo
		free(p);
		return l;
	}
	//sen�o, � n� intermedi�rio para final
	ant->prox = p->prox;
	if (p == l){//se p aponta para o �ltimo n�-dado
		l = ant;
	} 
	free(p);
	return l;
}
