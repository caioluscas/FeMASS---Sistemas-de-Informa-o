#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <locale.h>
/*Elabore um algoritmo para calcular automaticamente a quantia a ser paga (contribuição mensal) por um
empregado da iniciativa privada. O usuário deverá digitar o seu respectivo salário bruto, recebendo em
tela o valor a ser descontado (conforme tabela abaixo) e o valor do salário após a aplicação do desconto.*/
main(){
	setlocale(LC_ALL, "Portuguese");
	float sal,des,novsal;
	printf("Diga seu o valor de seu salario: ");
	scanf("%f",&sal);
	if(sal<=1045){
		des=(sal*0.0750);
		printf("O valor a ser descontado é de: R$%.2f\n",des);
		novsal=sal-des;
		printf("valor do salário após a aplicação do desconto R$%.2f",novsal);
	}
	if(sal>1045 && sal<=2089.60){
		des=(sal*0.09);
		printf("O valor a ser descontado é de: R$%.2f\n",des);
		novsal=sal-des;
		printf("valor do salário após a aplicação do desconto R$%.2f",novsal);
	}
	if(sal>2089.60 && sal<= 3134.40){
		des=(sal*0.12);
		printf("O valor a ser descontado é de: R$%.2f\n",des);
		novsal=sal-des;
		printf("valor do salário após a aplicação do desconto R$%.2f",novsal);
	}
	if(sal>3134.40){
		des=(sal*0.14);
		printf("O valor a ser descontado é de: R$%.2f\n",des);
		novsal=sal-des;
		printf("valor do salário após a aplicação do desconto R$%.2f",novsal);
	}
	
}
