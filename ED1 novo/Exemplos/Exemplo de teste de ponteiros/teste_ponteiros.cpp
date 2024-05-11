//EDI - prof. Irineu
//Leitura: http://linguagemc.com.br/ponteiros-em-c/
//Teste com ponteiros

#include <stdio.h>
#include <conio.h>
 
int main(void)
{
   //valor � a vari�vel que
   //ser� apontada pelo ponteiro
   int valor = 27;
 
   //declara��o de vari�vel ponteiro
   int *ptr;
 
   //atribuindo o endere�o da vari�vel valor ao ponteiro
   ptr = &valor;
 
   printf("Utilizando ponteiros\n\n");
   printf ("Conteudo da variavel valor: %d\n", valor);
   printf("\nTamanho da var valor %i",sizeof(int));
   printf("Tamanho de var int *ptr (bytes): %x \n", sizeof(typeof ptr));
   getch();
   printf ("Endere�o da variavel valor: %x \n", &valor);
   getch();
   printf ("Conteudo da variavel ponteiro ptr: %x \n", ptr);
   getch();
   printf ("Acessando a variavel apontada pelo ponteiro ptr: %d \n", *ptr);
   getch(); //efeito de pausa - previsto pela biblioteca conio.h
   return(0);
}
