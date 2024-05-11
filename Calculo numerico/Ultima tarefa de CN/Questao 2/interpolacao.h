#ifndef INTERPOLACAO_H_INCLUDED
#define INTERPOLACAO_H_INCLUDED

float interpol(int num, float x){

    float mat[2][num], L[num], valorL = 1;
    int count = 0;
    float valor = 0;

     for(int lin = 0; lin< num; lin++){
        printf("\nDigite o valor de Fx e x separados por ',':");
        scanf("%f,%f", &mat[lin][0], &mat[lin][1]);
    }

    for(int elemento = 0; elemento<num; elemento++){
        for(int lin = 0; lin <num; lin++){
            if(elemento != lin){
                valorL = valorL*(x-mat[lin][1])/(mat[elemento][1] - mat[lin][1]);
            }
        }
        L[count] = valorL;
        count++;
        valorL = 1;
    }
    for(int i = 0; i<num; i++){
        valor = valor + mat[i][0]*L[i];
    }
return valor;
}

#endif // INTERPOLACAO_H_INCLUDED
