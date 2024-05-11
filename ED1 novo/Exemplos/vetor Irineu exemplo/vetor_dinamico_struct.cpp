#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;

struct Student {
    char* firstName; //alocação de vetor de caracteres (string) de forma dinâmica para evitar erro -fpermissive no uso de vetor de struct dinâmico
    char* lastName;  //alocação de vetor de caracteres (string) de forma dinâmica para evitar erro -fpermissive no uso de vetor de struct dinâmico
    int roomNumber;

};
typedef struct Student STUDENT;

void Exibir(int numStudents, STUDENT* students){
    for (int x = 0; x < numStudents; x++)
        printf("Primeiro Nome: %s, Ultimo Nome: %s, Numero da Sala: %d\n",students[x].firstName,students[x].lastName,students[x].roomNumber);
}

STUDENT* Cadastrar(int numStudents, STUDENT* students){
    if (numStudents == 1)
        students = (STUDENT*) malloc(numStudents * sizeof(STUDENT));
    else if (numStudents > 1)
        students = (STUDENT*) realloc(students, numStudents * sizeof(STUDENT)); //observar o segundo parâmetro: precisa sim calcular a soma de bytes de memória para qtd x tipo de dado   
    
        int x = numStudents-1;
        students[x].firstName=(char*)malloc(sizeof(char*)); //alocação de vetor de caracteres (string) de forma dinâmica para evitar erro -fpermissive no uso de vetor de struct dinâmico
        printf("Entre com primeiro nome: ");
        //scanf("%s",students[x].firstName); //lê todo o texto digitado até primeiro espaço \n
        gets(students[x].firstName); //lê todo o texto digitado até que se aperte enter
        fflush(stdin);

        students[x].lastName=(char*)malloc(sizeof(char*)); //alocação de vetor de caracteres (string) de forma dinâmica para evitar erro -fpermissive no uso de vetor de struct dinâmico
        printf("Entre com ultimo nome: ");
        //scanf("%s",students[x].lastName); //lê todo o texto digitado até primeiro espaço \n
        gets(students[x].lastName); //lê todo o texto digitado até que se aperte enter
		fflush(stdin);
		
        printf("Entre com numero da sala: ");
        scanf("%i",&students[x].roomNumber);
        fflush(stdin);

    return students;
}

int main(int argc, char** argv){

    STUDENT* students; //ponteiro que servirá para controlar o vetor dinâmico

    cout << "Teste de cadastro de 1o estudante" << endl;
    int numStudents=1;
    students = Cadastrar(numStudents, students);
    Exibir(numStudents, students);

    cout << "Teste de cadastro de 2o estudante" << endl;
    numStudents=2;
    students = Cadastrar(numStudents, students);
    Exibir(numStudents, students);
    
    cout << "Teste de cadastro de 3o estudante" << endl;
    numStudents=3;
    students = Cadastrar(numStudents, students);
    Exibir(numStudents, students);

    return (0);
}
