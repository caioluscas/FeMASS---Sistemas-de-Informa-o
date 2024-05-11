#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
main(){
	float v,c;
	printf("Diga o valor da venda: ");
	scanf("%f",&v);
	if(v<=1500){
		c=(v*0.10)+1200;
	}
	else{
		c=(0.30*v)+1200;	
	}
	printf("\valor do salario junto com comissão: R$%.2f",c);
}
