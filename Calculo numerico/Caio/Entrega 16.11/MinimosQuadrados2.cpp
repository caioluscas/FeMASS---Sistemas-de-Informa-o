#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include <locale.h>
#include <math.h>

//Calcula os elementos da matriz A
float sum(float* v,int p,int n){
	float soma=0;
	for(int i=0;i<n;i++){
		soma=soma+pow(v[i],p);
	}
	return soma;
}

//Calcula os elementos da matriz B
float sumxy(float* vx,float* vy,int p,int n){
	float somaxy=0;
	for(int i=0;i<n;i++){
		somaxy=somaxy+vy[i]*pow(vx[i],p);
	}
	return somaxy;
}



main(){
	int i=0,j=0,n=10,grau=0,posicao;
	int tam=0;
	float erro=0,aux=0;
	float soma=0;
	int para=1;
	float dif=0;
	printf("**********************************************\n");
	printf("\t Minimos Quadrados \t\n");
	printf("**********************************************\n");
	printf("Informe o grau para a funcao:");
	scanf("%d",&grau);
	tam=grau+1;


	float Xi[]={1,2,3,4,5,6,7,8,9,10};
	float FX[] = {1.3,3.5,4.2,5,7,8.8,10.1,12.5,13,15.6};
	float A[tam][tam],Alfa[tam],Xini[tam],B[tam],Res[tam];

		
	for(int i=0;i<tam;i++){
		posicao=i;
		for(int j=0;j<tam;j++){
			A[i][j]=sum(Xi,posicao,n);
			posicao=posicao+1;
		}
			
	}
	printf("\n\n\t Matriz A\n");
	printf("------------------------------------------------\n");			
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			printf("%6.4f\t\t",A[i][j]);
		}
		printf("\n");
	}

	for(int i=0;i<tam;i++){
		posicao=i;
		B[i]=sumxy(Xi,FX,posicao,n);	
	}
	printf("\n\n\t Matriz B\n");
	printf("------------------------------------------------\n");		
	for(int i=0;i<tam;i++){
		printf("%.4f\t",B[i]);
		printf("\n");
	}
	
	
	//Atribuindo valores para o alfa inicial
	for(int i=0;i<tam;i++){
		Xini[i]=0;
	}	
	printf("\n\n");
	do{
		for(int i=0;i<tam;i++) {
	        soma=0;
	        for(int j=0;j<tam;j++) {
	            if(i!=j) {
	                soma+=A[i][j]*Xini[j];
	            }
	        }
	        	Alfa[i]=(1/A[i][i])*(B[i]-soma);
	        	//printf("X(%d) = %.4f\n",i+1,Alfa[i]);
	        	dif=fabs(Alfa[i])- fabs(Xini[i]);
	        	Xini[i]=Alfa[i];
				if(fabs(dif)>erro){
					para=1;
				}else 
					para=0;					
	    }	   
		//printf("\n");     	
	    }while(para==1);	   
	printf("------------------------------------------------\n");
	printf("\t\t Resultados\n");
	printf("------------------------------------------------\n");			
	for(int i=0;i<tam;i++){
	   	printf("X(%d)= %.4f\n",i+1,Alfa[i]);
		}
	
	   				
}
