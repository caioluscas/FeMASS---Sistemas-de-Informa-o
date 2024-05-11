//Armazena os dados do clientes cadastrados
struct cadastro{
    char nome[50];
    char estadocivil[15];
    int id;
    char situacao[15];
    char cargo[20];    
};

typedef struct cadastro cli;

/* Cria uma struct para dar referencia a próxima celula*/
struct celula
{
  cli cadastro;
  struct celula *prox;

};

typedef struct celula CEL;
