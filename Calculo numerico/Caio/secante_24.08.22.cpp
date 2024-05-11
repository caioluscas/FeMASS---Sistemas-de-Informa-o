#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

float funcao(float x){

//resultado da conversão é x se aproximar de 3 para a função ser igual a 0
return pow(10,x)*log(10)+x;
		
}

float recursiva(float a, float b, float fb, float fa){
	
	/*float fdelta=100;
	fdelta=(fb-fa);
	if(fdelta<0.01){
		printf("\nfdelta tende ao infinito\n");
	}*/
	
//retorna x2
return (b-fb*((b-a)/(fb-fa)));
		
}

int main(){
	
	int k=1;
	float a, b, c, fa, fb, fc=100, erro;
	
	setlocale( LC_ALL, "" );
	
	//a=x0 e b=x1
	printf ("Informe o primeiro ponto:");
	scanf ("%f",&a);
	printf ("Informe o segundo ponto:");
	scanf ("%f",&b);
	printf ("Informe o erro:");
	scanf ("%f",&erro);

	//Calculo da imagem dos pontos
	fa=funcao(a);
	fb=funcao(b);
	c=recursiva(a, b, fb, fa);
	
	printf("\n====================================================");
	//k-2=x0=a e k-1=x1=b e k=x2=c
	printf("\nK\tX k-2\t\tX k-1\t\tX k\t\tf(c)");
	printf("\n%d\t%f.2\t%f.2\t%f.2\t%f", k, a, b, c, fc);
	
	while(fc>erro){
		
		k++;
		
		a=b;
		b=c;
		
		fa=funcao(a);
		fb=funcao(b);
		fc=funcao(c);
		c=recursiva(a, b, fb, fa);
		
		printf("\n%d\t%f.2\t%f.2\t%f.2\t%f", k, a, b, c, fc);
		
	}
}
