
#include<stdio.h>
#include "interpolacao.h"

int main(){

    int num = 0;
    float x = 0;

    printf("Quantas combinacoes de valores existentes? ");
    scanf("%d", &num);
    printf("Qual valor de X que quer interpolar:");
    scanf("%f", &x);

    printf("%.1f", interpol(num,x));

return 0;
}
