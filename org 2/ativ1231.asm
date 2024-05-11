#ESTRUTURA CONDICIONAL - PONTO FLUTUANTE
#Elabore um algoritmo que apoie o cálculo da média aritmética simples das notas
 #dos alunos de uma turma. O professor iniciará a execução do programa
 #informando ao mesmo a quantidade de notas que irão compor a média (duas, três
 #ou quatro notas). Na sequência, o professor informará ao programa as notas
 #propriamente dita conforme o quantitativo definido por ele no passo anterior. O
 #programa deve informar a situação do aluno (a) e a sua nota média. O programa
 #deverá perguntar se o usuário deseja apurar o resultado de outro aluno (a).

 #Nota Situação
 #Menor do que 4,0 Reprovado
 #Menor do que 7,0 e Maior e Igual a 4,0 Prova Final
 #Maior do que 7,0 Aprovado

 .data
 msg1: .asciiz "\nCálculo da Situação dos Alunos ao Final do Período Letivo\n"
 msg2: .asciiz "\nQuantas notas serão utilizada no cálculo da Média? "
 msg3: .asciiz " - Digite a nota do aluno: "
 msg4: .asciiz "\n"
 msg5: .asciiz "\nSituação do Aluno (a): "
 msg6: .asciiz "\nAluno (a) Reprovado!\n "
 msg7: .asciiz "\nAluno (a) Aprovado!\n "
 msg8: .asciiz "\nAluno (a) em Prova Final!\n "
 msg9: .asciiz "\nApuração (Média): "
 msg10: .asciiz "\nDeseja Apurar Novo Resultado? [1-Sim] / [2-Sair] "
 Zero: .float 0.0
 num1: .float 1.0
 num4: .float 4.0
 num7: .float 7.0
 .text
 main:
 #Zerando os Registradores por garantia.
 l.s $f2, Zero
 l.s $f3, Zero
 l.s $f4, Zero
 l.s $f9, Zero
 l.s $f10, Zero
 l.s $f11, Zero
 l.s $f13, Zero
 l.s $f14, Zero
 l.s $f18, Zero
 l.s $f22, Zero

 # Descrição dos Objetivos do Algoritmo
 li $v0, 4
 la $a0, msg1
 syscall

 # Informar ao programa a quantidade de notas que compõem a média
 li $v0, 4
 la $a0, msg2
 syscall

 li $v0, 6
 syscall
 mov.s $f10, $f0

 l.s $f9, num1

 #Enquanto $f9 é menor e igual a $f10 faça
 enquanto:
 #Número sequencial relativo ao passo da execução
 li $v0, 2  #escrita de numero flutuante
 mov.s $f12, $f9    
 syscall

 #O usuário deve informar a nota do aluno
 li $v0, 4
 la $a0, msg3
 syscall

 li $v0, 6     #leitura de float
 syscall
 mov.s $f2, $f0

 #Acumulador das notas digitas pelo usuário
 add.s $f3, $f3, $f2             #soma e guarda em f3

 #Contador da condição de execução do enquanto ($f9 menor ou igual a $f10)
 l.s $f11, num1            #guardando numero num1
 add.s $f9, $f9, $f11

 #Se $f9 é menor ou igual a $f10, salte para o rótulo enquanto
 c.le.s $f9, $f10  
 bc1t enquanto
 #----Fim do Enquanto -----

 #calculando a média aritmética da nota do aluno (a):
 div.s $f4, $f3, $f10

 #Relembrando o Conteúdo das nossas Variáveis (registradores neste caso)
 #$f3: contém a soma das notas do aluno (a) em ponto flutuante;
 #$f10: contém o quantitativo de notas do aluno (a) em ponto flutuante;
 #$f4: é o resultado do cálculo da média das notas do aluno (a)

 #Definindo a situação do Aluno (a)

 #Comparação: se $f1 é menor ou igual a $f2; se verdadeiro = 1, se falso = 0.
 #igual a 1 salto para "se"; igual a 0 salto para "senao".
 l.s $f13, num4
 c.lt.s $f4, $f13 
 bc1t se
 bc1f senao


 #Informar ao usuário a reprovação do aluno (a)
 se:
 li $v0, 4
 la $a0, msg5
 syscall

 li $v0, 4
 la $a0, msg6
 syscall
 j fimse

 # se $f4 é maior ou igual a 7.0, informar aprovação.
 senao:
 l.s $f14, num7
 c.lt.s $f4, $f14
 bc1t se2
 bc1f senao2


 #Informar ao usuário a aprovação do aluno (a)
 se2:
 li $v0, 4
 la $a0, msg5
 syscall

 li $v0, 4
 la $a0, msg8
 syscall

 j fimse

 #Informar ao usuário que o aluno (a) está na Prova Final!
 senao2:
 li $v0, 4
 la $a0, msg5
 syscall

 li $v0, 4
 la $a0, msg7
 syscall

 j fimse
 fimse:

 #Informar a média artimética alcançada pelo aluno (a)
 li $v0, 4
 la $a0, msg9
 syscall

 li $v0, 2
 mov.s $f12, $f4
 syscall

 #Perguntar ao Usuário ses ele deseja sair do programa
 li $v0, 4
 la $a0, msg10
 syscall

 li $v0, 6
 syscall
 mov.s $f18, $f0

 #Condição para retornar ao programa. Menor e igual a 1
 l.s $f22, num1
 c.le.s $f18, $f22
 bc1t main
 
 #Encerrar programa
 li $v0, 10
 syscall