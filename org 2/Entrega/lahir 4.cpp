#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
main(){
	float s,v,vp;
	printf("Diga o valor do seu salário: ");
	scanf("%f",&s);
	if(s<=1903.98){
		printf("\nisento");
	}
	else if((s>=1903.99)&&(s<=2826.65)){
		v=(s*0.067);
		printf("valor da parcela: R$%.2f\n",v);
		vp=-142.80+(s*0.075);
		printf("valor do imposto: R$%.2f\n",vp);
	}
	else if((s>=2826.66)&&(s<=3751.05)){
		v=(s*0.15);
		printf("valor da parcela: R$%.2f\n",v);
		vp=-354.80+(s*0.15);
		printf("valor do imposto: R$%.2f\n",vp);
	}
	else if((s>=3751.06)&&(s<=4664.68)){
		v=(s*0.225);
		printf("valor da parcela: R$%.2f\n",v);
		vp=-636.13+(s*0.225);
		printf("valor do imposto: R$%.2f\n",vp);
	}
	else{
		if(s>4664.68){
			v=(s*0.275);
			printf("valor da parcela: R$%.2f\n",v);
			vp=-869.36+(s*0.275);
			printf("valor do imposto: R$%.2f\n",vp);
			
		}
	}
}
