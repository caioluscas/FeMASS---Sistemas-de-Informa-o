.data
	msg1: .asciiz "\ndigite o primeiro numero:"
	msg2: .asciiz "\ndigite o segundo numero:"
	msg3: .asciiz "\nmedia:"
.text 
main:
	li $v0,4         #mostra o texto msg1
	la $a0,msg1
	syscall
	
	li $v0, 6 #leitura de reais
	syscall
	mov.s $f1,$f0
	
	
	li, $v0,4  	#mostra o texto msg2
	la,$a0,msg2
	syscall
	
	li $v0, 6	#recebe real
	syscall
	mov.s $f2, $f0

	
	div.s $f3,$f1,$f2	,
	mov.s $f12, $f3
	syscall
	
	li $v0,4
	la $a0, msg3
	syscall
	
	li $v0,2
	mov.s $f12, $f3
	syscall
	
	
	