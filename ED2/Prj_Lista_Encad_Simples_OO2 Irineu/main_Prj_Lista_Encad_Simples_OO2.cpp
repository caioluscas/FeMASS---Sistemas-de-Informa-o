#include "Lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void print_tamanho(int t){
	cout << "Tamanho da Lista: " << t << endl;	
}

void print_retira(bool x){
	if (x)
		cout << "Dado removido com sucesso da lista!" << endl;
	else	
		cout << "Dado não encontrado na lista!" << endl;
}

void print_vazia(bool x){
	if (x)
		cout << "Lista vazia!" << endl;
	else	
		cout << "Lista não vazia!" << endl;
}

void print_busca(bool x){
	if (x)
		cout << "Dado encontrado!" << endl;
	else	
		cout << "Dado não encontrado!" << endl;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "");

	cout << "PROGRAMA LISTA ENCADEADA SIMPLES" << endl;
	Lista l; //instanciando o objeto l conforme a classe Lista
	
	l.insere_inicio(23);
	l.insere_inicio(45);
	l.insere_inicio(56);
	l.insere_inicio(78);
	l.imprime();
	print_tamanho(l.tamanho());
	print_retira(l.retira(78));
	l.imprime();
    print_tamanho(l.tamanho());
    print_retira(l.retira(10));
    print_vazia(l.vazia());
    print_busca(l.busca(45));
    print_busca(l.busca(100));
    l.imprime();
    print_tamanho(l.tamanho());
    l.libera();
    l.imprime();
    print_tamanho(l.tamanho());
    
    l.~Lista();
	return 0;
}
