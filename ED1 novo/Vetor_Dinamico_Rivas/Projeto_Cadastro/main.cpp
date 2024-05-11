#include <iostream>
#include <locale.h>
#include "cadastro.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu(){
	int op;
	cout << "CADASTRO:" << endl;
	cout << "1 - Cadastrar novo usuário" << endl;
	cout << "2 - Exibir usuários cadastrados" << endl;
	cout << "3 - Exibir quantidade de usuários cadastrados" << endl;
	cout << "4 - Remover último usuário cadastrado" << endl;
	cout << "5 - Sair" << endl;
}

int main(int argc, char** argv) {
	
	setlocale(LC_ALL,"");
	
	unsigned int op(0);
	int x;
	cadastro c;
	iniciar_cadastro(&c);
	do{
		menu();
		cin >> op;
		switch(op){
			case 1:
				//cadastrar
				c.quantidade++;
				for(int i=0; i<c.quantidade; i++){
					cout << "Nome: ";
					scanf("%s/n",&c.nome);
					//cin >> c.nome >> endl;
					cout << "RG: ";
					//cin >> cadastro[i].rg << endl;
					scanf("%s/n",&c.rg);
					cout << "CPF: ";
					//cin >> cadastro[i].cpf << endl;
					scanf("%s/n",&c.cpf);
					cout << "Endereço: ";
					//cin >> cadastro[i].endereco << endl;
					scanf("%s/n",&c.endereco);
					cout << endl;
				}
				break;
			case 2:
				//exibir cadastros
				print(&c);
				break;
			case 3:
				//exibir quantidade
				cout << "Usuários cadastrados: " << size(&c) << endl << endl;
				break;
			case 4:
				//remover
				x = pop(&c);
				if(x!=-99){
					cout << "Removido: " << x << endl << endl;
				}else{
					cout << "Erro ao remover!" << endl << endl;
				}
				break;
			case 5:
				//sair
			default:
				cout << "Fim de programa!" << endl << endl;
				return 0;
		}	
	}while(op>0 && op<=5);
	kill_stack(&c);
	return 0;
}
