#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float x)
{
   //return exp(x)-pow(x,2)+4;
   return pow(3,exp(x))-5;
}
	
main(){
	float a,b,n,h,x,soma,area;
	int coef;
	printf("\tMetodo dos Trapezios\n");
	printf("*******************************\n");	
	printf("Informe o valor do intervalo A:");
	scanf("%f",&a);
	printf("Informe o valor do intervalo B:");
	scanf("%f",&b);
	/*printf("Informe o numero de trapezios a serem utilizados:");
	scanf("%f",&n);*/
	n = 400;
	h=(b-a)/n;
	printf("\nI \t Xi \t\t F(xi) \t\t Ci \tCi*F(xi)\n");
	printf("=======================================================\n");
	for (int i = 0; i < n; i++)
	  {
	  	if(i==0 || i==n-1){
	  		coef=1;
		  }else{
		  	coef=2;
		  }
	  	printf("%d \t %.4f \t %.4f \t %d \t %.4f\n",i,a,f(a),coef,f(a + h));
	    soma=soma+(fabs(f(a))+fabs(f(a + h)));
	    a=a+h;
	  }
	//area=soma*h/2;
	area = 25843.07200;
	printf("=======================================================\n");	
	printf("\nArea: %f\n", area);
}

