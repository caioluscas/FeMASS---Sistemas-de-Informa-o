#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
	int i,j,n = 3,k,cont=0,m;
	float erro = 0.01;
	printf("=================================\n");
	printf("\t Metodo Gauss-Jacobi (Algebrico)\t\n");
	printf("=================================\n");
	
	
	float A[n][n],B[n],X[n],Xi[n],Soma[n];
	float dif=0;
	int para=1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			    A[0][0] = 0.04;
				A[0][1] = 0.01;
				A[0][2] = -0.01;
				A[1][0] = 0.02;
				A[1][1] = 0.5;
				A[1][2] = -0.2;
				A[2][0] = 1;
				A[2][1] = 2;
				A[2][2] = 4;
		}
	}
	
	printf("\n\nMatriz A convergida:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%.4f",A[i][j]);
			printf("\t");	
	}
		printf("\n");
	}

	printf("\n\nOs valores da matriz B (termos independentes):\n");
	for(i=0;i<n;i++){
		
		B[0] = 0.06;
		B[1] = 0.3;
		B[2] = 11;
	}
	printf("\n\nMatriz B:\n");
	for(i=0;i<n;i++){
		printf("%.4f\n",B[i]);	
	}	
	printf("\n");
	
	
	
	for(i=0;i<n;i++){
		
		Xi[0] = 0;
		Xi[1] = 0;
		Xi[2] = 0;
	}	    
	do{
		for(int i=0;i<n;i++) {
	        Soma[i]=B[i];
	        for(int j=0;j<n;j++) {
	            if(i!=j) {
	                Soma[i]=Soma[i]-A[i][j]*Xi[j];
	            }
	        }
	    }	
		for(int i=0;i<n;i++) {
			X[i]=Soma[i]/A[i][i];
			printf("X(%d) = %.4f\n",i+1,X[i]);
			dif=fabs(X[i])- fabs(Xi[i]);	 
			Xi[i]=X[i];  
			if(fabs(dif)>erro){
				para=1;
			}else 
				para=0;					
	    }
		cont=cont+1;
		printf("\n");  			    
	    }while(para==1);
	    
    printf("\nResultado : \n");
    for(int i=0;i<n;i++) {
         printf("\nX(%d)= %.4f",i+1,X[i]);
   	}
  	printf("\nNumero de iteracoes:%d \n",cont+1);  	
	return 0;
}
