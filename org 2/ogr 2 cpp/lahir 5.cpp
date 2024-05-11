#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include <locale.h>

main(){
	setlocale(LC_ALL, "Portuguese");
	int i;
    int alt[i], lar[i], arlados[i], arpisc, arlad, altlad, larglad;

    for(i=1;i<6;i++){
        printf("         Lateral %d      \n", i);
        printf("\nDiga a altura do lado da piscina:" );
        scanf("%d",&alt[i]);
        printf("\nDiga a largura do lado da piscina:" );
        scanf("%d",&lar[i]);
    }

    printf("\n       Fundo da Piscina       \n");
    printf("\nDiga sua altura do fundo da piscina:" );
    scanf("%d",&alt[i]);
    printf("\nDiga sua largura do fundo da piscina:" );
    scanf("%d",&lar[i]);

    printf("\n     Tamanho do Ladrilho     \n");
    printf("\nInforme a altura do ladrilho utilizado:" );
    scanf("%d",&altlad);
    printf("\nInforme a largura do ladrilho utilizado:" );
    scanf("%d",&larglad);
    arlad = altlad * larglad;
    for(i=1;i<6;i++){
    arlados[i] = alt[i] * lar[i];
    printf("\n\nÀrea do lado %d: %d", i, arlados[i]);
    arpisc+=arlados[i];

    }
    printf("\nÀrea da piscina: %d", arpisc);
    printf("\nÀrea do ladrilho:%d\n", arlad);
    printf("Compre %d ladrilhos para a obra", arpisc/arlad);
}
