CEL *cria_cel()
{
  CEL *p;

  p=(struct celula *) malloc(sizeof(struct celula));
  return p;
}

[B][U]void insere_ult(CEL **pl)[/U][/B]
{
	CEL *p,*q;

	p=cria_cel();
	fflush(stdin);
	int i=0,qtd;
        FILE *arq;
        arq=fopen("C:/teste.bin", "ab");
        printf ("********** CADASTRO DE GRUPO DE CLIENTES **********\n");
        printf ("\nDigite quantos grupos de clientes que deseja cadastrar: ");
        scanf ("%i", &qtd);
        printf("\n");
        for(i=0;i<qtd;i++){

        printf ("**********Cadastro de Clientes**********\n");
        printf("\n");
        printf ("Digite um codigo para o cadastro do cliente: "); 
        fflush(stdin);
        scanf ("%i",&p->cadastro.id);
        printf("\n");
        printf ("Digite o nome do %i cliente: ", i+1); 
        fflush(stdin);
        gets (p->cadastro.nome);
        printf("\n");
        printf ("Digite o Estado Civil do %i cliente: ", i+1); 
        fflush(stdin);
        gets (p->cadastro.estadocivil);
        printf("\n");
        printf ("Digite a situacao do %i cliente(ATIVO/INATIVO): ", i+1); 
        fflush(stdin);
        gets (p->cadastro.situacao); 
        printf("\n");
        printf ("Digite a profissao do %i cliente: ", i+1); 
        fflush(stdin);
        gets (p->cadastro.cargo);
        p->prox=*pl;
        *pl=p;
        printf("\n");
        system("cls");
	p->prox=NULL;
	if(*pl==NULL)
	  *pl=p;
	else
	 {
	   /* Procura o ultimo numero */
	   for(q=*pl;q->prox!=NULL;q=q->prox);
	   q->prox=p;
	 }
	 fwrite(pl,sizeof(pl),1,arq); 
        }
        fclose(arq); 

        }
        
        
        
        
/* Remove a ultima célula e verifica se a mesma está vazia*/
void remove_ult(CEL **pl)
{
	 CEL *pn,*un;

	if(*pl==NULL)
	   printf("\nLista Vazia");
	else
	  {
		if((*pl)->prox==NULL)
			*pl=0;
		else
		{
		  /* procura o ultimo no */
		  pn=*pl;
		  un=*pl;
		  while(un->prox!=NULL)
		  {   pn=un;
				un=un->prox;
		  }
		  pn->prox=NULL;
		  free(un);
		}
		printf("\nFoi removida a ultima celula!!!!");
	  }
}




/* Remove depois da celula que verifica se contêm conteudo*/
void remDepois(CEL *pl)
{
	CEL *q;

   if(pl==NULL||pl->prox==NULL)
	printf("\nRemocao nula");
   else
        {
	    q=pl->prox;
	    pl->prox=q->prox;
	    free(q);
	}
}




/* Exibe o conteudo cadastrado no sistema*/
void exibe_lista(CEL *p)
{
   int m=1;

	printf("\n*****Conteudo Cadastrado*****");
	while(p!=0)
    {
        printf("\nCelula da Lista- %i",m++);
        printf("\nCódigo Cliente Cadastrado:%i\n",p->cadastro.id);
        printf("\nNome Cliente:%s\n",p->cadastro.nome);
        printf("\nEstado Civil:%s\n",p->cadastro.estadocivil);
        printf("\nSituacao do cadastro:%s\n",p->cadastro.situacao);
        printf("\nCargo:%s\n",p->cadastro.cargo);
        p=p->prox;
    }
  printf("\nFim da exibicao do conteudo cadastrado\n");
}




/* Busca o que já foi cadastrado no sistema e o que vai estar no arquivo*/
CEL * busca(CEL *pl)
{
	CEL *p;
	int m=1,cod;
	printf("\nDigite o codigo do cliente que deseja pesquisar: ");
    scanf("%i",&cod);
    for(p=pl;p!=NULL;p=p->prox)
     {
	if(p->cadastro.id==cod){
        printf("\nCelula da Lista- %i",m++);
        printf("\nCódigo Cliente Cadastrado:%i\n",p->cadastro.id);
        printf("\nNome Cliente:%s\n",p->cadastro.nome);
        printf("\nEstado Civil:%s\n",p->cadastro.estadocivil);
        printf("\nSituacao do cadastro:%s\n",p->cadastro.situacao);
        printf("\nCargo:%s\n",p->cadastro.cargo);

	  return p;
     }
   return NULL;
}
}





/* Remove e exclui o cadastro conforme digitar pelo código do cliente*/
CEL * remove(CEL *pl,int id){
   CEL *p,*ant;
   int m=1,del,cod;
   ant = pl;

   for(p=pl;p!=NULL;p=p->prox)                   
     {
	if(p->cadastro.id==cod)
	{
        printf("\nCelula da Lista- %i",m++);
        printf("\nCódigo Cliente Cadastrado:%i\n",p->cadastro.id);
        printf("\nNome Cliente:%s\n",p->cadastro.nome);
        printf("\nEstado Civil:%s\n",p->cadastro.estadocivil);
        printf("\nSituacao do cadastro:%s\n",p->cadastro.situacao);
        printf("\nCargo:%s\n",p->cadastro.cargo);
	    fflush(stdin);
	    printf("Deseja realmente excluir?\n1-Sim\n2-Nao");
	    printf("Digite: 1-Sim e 2-Nao");
     	scanf("%i",&del);
     	if(del==1)
     	{
			ant->prox=p->prox;
			free(p);
			}
		}	
     }

   return NULL;
}




/* Vai modificar um cadastro já efetuado, permitindo alterar o que desejar*/
CEL * modifica(CEL **pl)
{
	CEL *p;
	int m=1,id,cod;
	printf("\nDigite o codigo do cliente que deseja alterar: ");
    scanf("%i",&id);	
    for(p=*pl;p!=NULL;p=p->prox){
	if(p->cadastro.id==cod){
	  	printf("\nCelula da Lista- %i",m++);
		printf("Codigo Cadastrado: %i\n",p->cadastro.id);
		printf("\nNome Cliente: %s\n",p->cadastro.nome);
		fflush(stdin);
		printf ("Digite o nome do %i cliente: "); 
        fflush(stdin);
        gets (p->cadastro.nome);
        printf("\n");
		printf ("Digite a situacao do %i cliente(ATIVO/INATIVO): ");
		fflush(stdin);
		scanf("%s",&p->cadastro.situacao);
		printf("\n");
		printf ("Digite a profissao do %i cliente: "); 
        fflush(stdin);
        gets (p->cadastro.cargo);

        p=p->prox;
	  return p;
		}
	 else{
			printf("\nNao existe cadastro com esse codigo\n");
            }
            }
   return NULL;
   }
        
        
