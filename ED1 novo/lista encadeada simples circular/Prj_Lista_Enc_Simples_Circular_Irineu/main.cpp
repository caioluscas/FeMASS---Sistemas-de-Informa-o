//Aula ED - prof. Irineu
#include "lista_simples_circular.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu(){
	cout<<"1 - Diga o numero para inserir no inicio: \n";
	cout<<"2 - Diga o numero para inserir no fim: \n";
	cout<<"3 - IsEmpty? \n";
	cout<<"4 - Imprimir\n";
	cout<<"5 - Retirar\n";
	cout<<"6 - Mostrar inicio\n";
	cout<<"7 - Mostra fim\n";
	cout<<"8 - Size\n";
	cout<<"9 - Ocorrencia\n";
	cout<<"10 - Remove inicio\n";
	cout<<"11 - Remove fim\n";
	
}
int main(int argc, char** argv) {
	int op(0),x;
	Lista* l; /* declara uma lista não inicializada - deverá apontar sempre para nó final*/
 	l = inicializa(); /* inicializa lista como vazia */
 	do{
 		menu();
 		cin >> op;
 		switch(op){
 			case 1:
 				cout<<"Diga um número para inserir no inicio: ";
 				cin>>x;
 				l = insere_inicio(l,x);
 				break;
 				
 			case 2:
 				cout<<"Diga um número para inserir no fim: ";
 				cin>>x;
 				l = insere_fim(l,x);
 				break;
 				
 			case 4:
 				
 				
		 }
	 }while(op>=1 && op<=11);
 	
	
}
