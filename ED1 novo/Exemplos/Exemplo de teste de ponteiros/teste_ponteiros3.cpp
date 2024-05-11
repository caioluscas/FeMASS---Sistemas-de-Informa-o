#include<iostream>

#define LEN 50 //numero de caracteres vai ate 50

struct endereco {
  char rua[LEN];
  char cidade_estado_cep[LEN];
};
typedef struct endereco Endereco;

void obtem_endereco(Endereco *pender)
{ //usa -> quando usa *
   printf("Entre rua: ");
   gets(pender->rua); //função para leitura
   printf("Entre cidade/estado/cep: ");
   gets(pender->cidade_estado_cep);
   //atribuir e consultar é ->
}

void imprime_endereco(Endereco ender)
{ //usa . quando nao usar *
   printf("%s\n", ender.rua);
   printf("%s\n", ender.cidade_estado_cep);
}

int main( ){
   struct endereco residencia; //é aplicado de forma estática

   printf("Entre seu endereco residencial:\n");
   obtem_endereco(&residencia);

   printf("\nSeu endereco:\n");
   imprime_endereco(residencia);
   return 0;
}
