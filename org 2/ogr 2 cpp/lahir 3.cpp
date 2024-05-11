#include<stdlib.h>
#include<stdio.h>
#include <locale.h>
/*Na recepção do setor de internação tem um terminal de orientação aos clientes. O usuário deve informar
o número do quarto desejado para saber a direção a tomar – direita ou esquerda – no corredor*/
main(){
	setlocale(LC_ALL, "Portuguese");
	int n;
	printf("diga o número do quarto desejado: ");
	scanf("%d",&n);
	if(n%2==0){
		printf("Vá para a Direita");
	}
	else{
		printf("Vá para a Esquerda");
	}
}
