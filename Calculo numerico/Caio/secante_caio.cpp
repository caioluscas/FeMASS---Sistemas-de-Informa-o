#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

float funcao(float x){
	return (pow(10,x)*log(10)+x);
}


int main(){
	float xn_1, xn, yn_1, yn, xn1;
	int i=0, erro = 0.01, inte;
	printf("Diga o Xn-1: ");
	scanf("%f",&xn_1);
	
	printf("Diga o Xn: ");
	scanf("%f",&xn);
	
	printf("Diga o numero de interações: ");
	scanf("%d",&inte);
									
	yn_1=funcao(xn_1);	
	
	yn=funcao(xn);	
														
	xn1=(xn-yn)*(xn-xn_1)/(yn-yn_1);												
	printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t\n",i,xn_1,xn,yn_1,yn,xn1);
									
								
	do{
		xn_1 = xn;
		xn = xn1;
		yn_1 = yn;
		yn = funcao(xn);
		xn1= xn-yn*(xn-xn_1)/(yn-yn_1);
		
		
		if((fabs(yn))<=erro){
			printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t\n",i+1,xn_1,xn,yn_1,yn,xn1);
			break;
		}
		printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t\n",i+1,xn_1,xn,yn_1,yn,xn1);
		i++;
	}while(i<=inte);
	printf("\t\t\traiz\t\t\t\tF(Raiz)");
	
	
	
	
}
