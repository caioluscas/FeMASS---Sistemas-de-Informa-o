#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/* Agora está alocando a celula do tipo struct*/



/* Funcao menu, retorna o numero digitado pelo usuario conforme as instruções abaixo*/
int menu(){
    int menu;
    printf("\n");
    printf ("***MENU CADASTRO DE CLIENTES LOJA DE INFORMATICA***\n");
    printf("\n");
    printf ("Digite 1 para INSERIR\n"); 
    printf ("Digite 2 para PROCURAR\n");   
    printf ("Digite 3 para EXCLUIR\n");
    printf ("Digite 4 para ALTERAR\n");    
    printf ("Digite 5 para GRAVAR EM ARQUIVO\n");      
    printf ("Digite 6 para LER ARQUIVO\n");            
    printf ("Digite 0 para SAIR\n");     
    printf("\n");
    printf ("Digite qual a opcao que deseja efetuar: ");
    scanf ("%i", &menu);
    printf("\n");
    system("cls");
    return menu;
    }

/*Funcao Cadastro, armazena o cadastro na ultima celula e
a passagem de parâmetro acontece por referência*/  

main()
{
	CEL *mostra,*p;
	int x,i,f=0,cod;
	system("cls");
	mostra=0;

	/* Abre o menu, possibilitando o usuário escolher o que deseja*/
	int opcao;
       opcao=menu();
       while (opcao==1 || opcao==2 || opcao==3 || opcao==4 || opcao==5 || opcao==6){
       if(opcao==1){ 
                    [B][U] opcao=insere_ult(&mostra);[/U][/B]
                     }                        
       if(opcao==2){ 
                     opcao=busca(&mostra);
                     }
       if(opcao==3){ 
                     opcao=remove(&mostra);
                     }
       if(opcao==4){ 
                     opcao=modifica(&mostra);
                     }
       if(opcao==5){ 
                     opcao=grava(&mostra);
                     }
       if(opcao==6){ 
                     opcao=exibe_lista(&mostra);
                     }
                     }
 printf("\n\n");                                                 
system("pause"); 
}
