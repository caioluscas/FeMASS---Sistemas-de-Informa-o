#Estrutura Condicional MIPs - PONTO FIXO
 #Elabore um algoritmo que solicite do usuário um número inteiro
 # e informe em tela se ele é par ou ímpar.
 .data
 msg1: .asciiz "Digite um número inteiro: "
 numpar: .asciiz "Número PAR"
 numimpar: .asciiz "Número íMPAR"

 .text
 #mensagem ao usuário
li $v0, 4
 la $a0, msg1
 syscall

 #leitura de número inteiro
  li $v0, 5
 syscall
 move $t0, $v0

 #divisão do número inteiro por 2
 li $t1, 2
 div $t0,$t1

 #Registrado lo (quociente) e registrador hi (resto da divisão)
 mfhi $t2 # possui i resto da divisão por 2

 #comparação para Tomada de Decisão
 #Se $t2 for igual a zero, então vá para o rótulo imprimePar
 beq $t2, $zero, imprimePar

 #imprimir se for ìmpar
 li $v0, 4
 la $a0, numimpar
 syscall

 j fimPrograma

 #imprimir se for Par
 imprimePar:
 li $v0, 4
 la $a0, numpar
 syscall

 #Encerrar o programa
 fimPrograma:
 li $v0, 10
 syscall