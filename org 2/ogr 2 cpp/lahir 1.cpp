/*Elabore em pseudocódigo uma solução para que os clientes de uma clínica de nutrição possam se avaliar
durante o tratamento. O usuário deverá digitar a sua massa corporal (kg) e sua altura (m), recebendo em
tela o resultado do seu atual IMC. Fórmula: IMC = massa/(altura*altura)
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<cmath>

main(){
	
	float alt, kg,imc;
	
	printf("Diga sua altura: ");
	scanf("%f",&alt);
	printf("Diga sua massa: ");
	scanf("%f",&kg);
	imc=kg/pow(alt,2);
	
	if(imc<16){
		printf("Magreza grave");
	}
	else
	if((imc>=16) && (imc<17)){
		printf("Magreza moderada");
	}
	else
	if((imc>=17 )&& (imc<18.5)){
		printf("Magreza leve");
	}
	else
	if((imc>=18.5 )&& (imc<25)){
		printf("Saudavel");
	}
	else
	if((imc>=25 )&& (imc<30)){
		printf("Sobrepeso");
	}
	else
	if((imc>=30 )&& (imc<35)){
		printf("Obesidade de Grau I");
	}
	else
	if((imc>=35 )&& (imc<40)){
		printf("Obesidade de Grau II");
	}
	else{
		printf("Obesidade de Grau III");
	}
	
}
