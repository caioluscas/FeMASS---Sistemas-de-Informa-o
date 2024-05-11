#include"Teste_num.h"
bool impar(int num)
{
	if(num%2!=0)
		cout << "Seu numero eh impar!\n";
	else
		cout << "Seu numero nao eh impar!\n";
}
bool par(int num)
{
	if(num%2==0)
		cout << "Seu numero eh par!\n";
	else
		cout << "Seu numero nao eh par!\n";
	
}
bool primo(int num)
{
	int aux=0,div=0;
for(aux=2;aux<=num/2;aux++)
        if(num%aux==0)
            div++;
    	if(div==0)
        	cout<<"Eh primo"<<endl;
    	else
        	cout<<"Nao eh primo"<<endl;
}
