#include"Calculadora.h"
#include"Calculadora_av.h"
#include"Teste_num.h"
int main(int argc, char** argv)
{
	float n1=0,n2=0;
	int num=0;
	int op,menu=0;
	cout << "Selecione o tipo de menu\n";
	cout << "0- MENU TESTE\n";
	cout << "1- MENU CALCULADORA\n";
	cin >> menu;
	do 
	{
		if(menu==0)
		{
		//Menu_Test
			cout << "\nTESTAGEM\n";
			cout << "1-Par\n";
			cout << "2-Impar\n";
			cout << "3-Prima\n";
			cout << "\nEscolha o primeiro valor: ";
			cin >> num;
			cout << "\nEscolha a operacao: ";
			cin >> op;
			switch (op)
			{
				case 1:
					cout << "\nFoi selecionada a testagem para numero par...\n";
					par(num);
				break;

				case 2:
					cout << "\nFoi selecionada a testagem para numero impar...\n";
					impar(num);
				break;

				case 3:
					cout << "\nFoi selecionada a testagem para numero primo...\n";
					primo(num);
				break;
				
				default:
					cout << "\nOPCAO INVALIDA\n";
				break;
			}
		}
		else if(menu==1)
		{
			do
			{
	
				//MENU_Calc
				cout << "\nCALCULADORA:\n";
				cout << "1-Soma\n";
				cout << "2-Subtracao\n";
				cout << "3-Multiplicacao\n";
				cout << "4-Divisao\n";
				cout << "5-Potencia\n";
				cout << "6-Raiz\n";
				cout << "7-Sair\n";
				
				cout << "Escolha o primeiro valor: ";
				cin >> n1;
				cout << "\nEscolha o segundo valor: ";
				cin >> n2;
				cout << "\nEscolha a operação: ";
				cin >> op;
				
				switch (op)
				{
					//SOMA
					case 1:
						printf("Soma dos dois valores: ");
						printf("%.1f", soma(n1, n2));
					break;
					
					case 2:
						printf("Subtração dos dois valores: ");
						printf("%.1f", sub(n1, n2));
					break;
					
					case 3:
						printf("Multiplicacao dos dois valores: ");
						printf("%.1f", mult(n1, n2));
					break;
					
					case 4:
						printf("Divisao dos dois valores: ");
						printf("%.1f", div(n1, n2));
					break;
					
					case 5:
						printf("Potenciacao dos dois valores: ");
						printf("%.1f", pot(n1,n2));
					break;
					
					case 6:
						printf("Raiz do primeiro valor: ");
						printf("%.1f",raiz(n1));
					break;
					
					default:
						cout<< "OPERACAO INVÁLIDA\n";
					break;
				}
			}while(op>0&&op<7);
		}
	}while(menu==0||menu==1);
}
