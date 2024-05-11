//EDI - Prof. Irineu
//Alocação dinâmica de vetor
//Exemplo: http://linguagemc.com.br/alocacao-dinamica-de-memoria-em-c/

#include <stdio.h>
#include <stdlib.h> //necessário para usar as funções malloc() e free()
#include <conio.h> //para ambiente ms-dos, usa getch para efeito de pausa
 
void imprimir_vetor(int num_componentes, float* v){ //imprime conteúdo do vetor passado por referência
	for (int i = 0; i < num_componentes; i++)
    {
       printf("%.2f\n",v[i]); //float com 2 casas decimais
	}	
} 

void armazenar_em_vetor(int num_componentes, float* v){ //vetor passado por referência a partir do main
	//Armazenando os dados em um vetor
    for (int i = 0; i < num_componentes; i++)
    {
      printf("\nDigite o valor para a posicao %d do vetor: ", i+1);
      scanf("%f",&v[i]);
    }
}

int main(void)
{
    float* v; //definindo o ponteiro v para controle de vetor dinâmico
    int num_componentes;    
     
    printf("Informe o numero de componentes do vetor\n");
    scanf("%d", &num_componentes);
     
    /* ------------- Alocando dinamicamente o espaço necessário -------------
     
    1 - Calcular o número de bytes necessários
    primeiramente multiplicamos o número de componentes do vetor pela    
    quantidade de bytes que é dada pelo comando sizeof,
    portanto temos: 
             num_componentes * sizeof(float)
     
    2 - Reservar a quantidade de memória
    usamos malloc para reservar essa quantidade de memória,    
    então temos: 
          malloc(num_componentes * sizeof(float))
     
    3 - Converter o ponteiro para o tipo de dados desejado
    como a função malloc retorna um ponteiro do tipo void, 
    precisamos converter esse ponteiro para o tipo da nossa variável, no caso float,
    por isso usamos o comando de conversão explicita:
                                                   (float*)
     
    4 - juntando tudo e atribuindo em v temos o comando abaixo:   */
      
    v = (float*) malloc(num_componentes * sizeof(float));  //aloca memória
    //v = (float *) calloc(num_componentes, sizeof(float)); //aloca memória e atribui zero como valor - opção ao malloc
    
	imprimir_vetor(num_componentes, v);  

    //Armazenando os dados em um vetor
    armazenar_em_vetor(num_componentes, v);
     
    // ------ Percorrendo o vetor e imprimindo os valores ----------
    printf("\n*********** Valores do vetor dinamico ************\n\n");
    imprimir_vetor(num_componentes, v); 
      
    //------ Realocando o vetor -------
    int novo_tam;
    printf("\nInforme novo tamanho para redimensionamento: ");
    scanf("%d", &novo_tam);

    if (novo_tam > 0){ //permite realocar para aumentar ou reduzir tamanho ao fim do vetor, desde que tamanho válido
   	    v = (float *) realloc(v, novo_tam * sizeof(float)); //observar o segundo parâmetro, representa o novo tamanho em bytes, logo: qtd x tamanho do tipo variável
   	    printf("\nValores contidos: \n");
   	    imprimir_vetor(novo_tam, v);
	}
   
    //liberando o espaço de memória alocado 
    free(v);
    
    getch();
    return 0;
}    
