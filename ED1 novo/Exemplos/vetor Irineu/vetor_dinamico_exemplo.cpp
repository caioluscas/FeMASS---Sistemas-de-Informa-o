//EDI - Prof. Irineu
//Aloca��o din�mica de vetor
//Exemplo: http://linguagemc.com.br/alocacao-dinamica-de-memoria-em-c/

#include <stdio.h>
#include <stdlib.h> //necess�rio para usar as fun��es malloc() e free()
#include <conio.h>
 
int main(void)
{
    float *v; //definindo o ponteiro v
    int i, num_componentes;    
     
    printf("Informe o numero de componentes do vetor\n");
    scanf("%d", &num_componentes);
     
    /* ------------- Alocando dinamicamente o espa�o necess�rio -------------
     
    1 - Calcular o n�mero de bytes necess�rios
    primeiramente multiplicamos o n�mero de componentes do vetor pela    
    quantidade de bytes que � dada pelo comando sizeof,
    portanto temos: 
             num_componentes * sizeof(float)
     
    2 - Reservar a quantidade de mem�ria
    usamos malloc para reservar essa quantidade de mem�ria,    
    ent�o temos: 
          malloc(num_componentes * sizeof(float))
     
    3 - Converter o ponteiro para o tipo de dados desejado
    como a fun��o malloc retorna um ponteiro do tipo void, 
    precisamos converter esse ponteiro para o tipo da nossa vari�vel, no caso float,
    por isso usamos o comando de convers�o explicita:
                                                   (float *)
     
    4 - juntando tudo e atribuindo em v temos o comando abaixo:   */
      
    v = (float *) malloc(num_componentes * sizeof(float));  //aloca mem�ria
    //v = (float *) calloc(num_componentes, sizeof(float)); //aloca mem�ria e atribui zero como valor - op��o ao malloc
      
    for (i = 0; i < num_componentes; i++)
    {
       printf("%.2f\n",v[i]);
	}
    //Armazenando os dados em um vetor
    for (i = 0; i < num_componentes; i++)
    {
      printf("\nDigite o valor para a posicao %d do vetor: ", i+1);
      scanf("%f",&v[i]);
    }   
     
   // ------ Percorrendo o vetor e imprimindo os valores ----------
   printf("\n*********** Valores do vetor dinamico ************\n\n");
    
   for (i = 0;i < num_componentes; i++)
   {
       printf("%.2f\n",v[i]);
   }       
    
   //------ Realocando o vetor -------
   int novo_tam;
   printf("\nInforme novo tamanho para redimensionamento: ");
   scanf("%d", &novo_tam);

   if (novo_tam > 0 && novo_tam < num_componentes){
   	    v = (float *) realloc(v, novo_tam); 
   	    printf("\nValores contidos: \n");
   	    for (i = 0;i < novo_tam; i++)
   		{
       		printf("%.2f\n",v[i]);
   		}
	}
   else
   		printf("\nNovo tamanho informado eh invalido!\n");
   		   
   //liberando o espa�o de mem�ria alocado 
   free(v);
    
   getch();
   return 0;
}    
