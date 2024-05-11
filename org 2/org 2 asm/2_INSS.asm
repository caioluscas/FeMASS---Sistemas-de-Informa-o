.data
	msg1:.asciiz "Diga seu o valor de seu salario:"
	msg2:.asciiz "O valor a ser descontado é de:"
	msg3:.asciiz "\nvalor do salário após a aplicação do desconto R$"
	num1:.float 1045.0
	num2:.float 2089.0
	num3:.float 3134.0
	#desconto
	num4:.float 0.0750
	num5:.float 0.09
	num6:.float 0.12
	num7:.float 0.14
.text
main:

	l.s $f1, num1
	l.s $f2, num2
	l.s $f3, num3
	l.s $f4, num4
	l.s $f5, num5
	l.s $f6, num6
	l.s $f7, num7
	
	#solicitar salario
	li $v0, 4
	la $a0, msg1
	syscall
	
	#receber salario
	li $v0, 6
	syscall
	mov.s $f8,$f0
	
	mul.s $f9,$f8,$f4 #desconto
	sub.s $f10, $f8,$f9 #salario dps do desconto
	c.lt.s $f8,$f1
	bc1t se1
	
	mul.s $f11,$f8,$f5 #desconto
	sub.s $f13, $f8,$f11 #salario dps do desconto
	c.lt.s $f8,$f2
	bc1t se2
	
	mul.s $f14,$f8,$f6 #desconto
	sub.s $f15, $f8,$f14 #salario dps do desconto
	c.lt.s $f8,$f3
	bc1t se3
	
	mul.s $f16,$f8,$f7
	sub.s $f17,$f8,$f16
	bc1f se4
	
	se1:
	#valor descontado 1
	li $v0, 4
	la $a0, msg2
	syscall
	
	#escrita dps de recebido o valor
	li $v0, 2
	mov.s $f12,$f9
	syscall
	
	#valor apos o desconto 1
	li $v0, 4
	la $a0, msg3
	syscall
	
	#escrita dps de recebido o valor
	li $v0, 2
	mov.s $f12,$f10
	syscall
	j fimse
	
	se2:
	#valor descontado 2
	li $v0, 4
	la $a0, msg2
	syscall
	
	#escrita dps de recebido o valor
	li $v0, 2
	mov.s $f12,$f11
	syscall
	
	#valor apos o desconto 2
	li $v0, 4
	la $a0, msg3
	syscall
	
	#escrita dps de recebido o valor
	li $v0, 2
	mov.s $f12,$f13
	syscall
	j fimse
	
	se3:
	#valor descontado 3
	li $v0, 4
	la $a0, msg2
	syscall
	
	#escrita dps de recebido o valor
	li $v0, 2
	mov.s $f12,$f14
	syscall
	
	#valor apos o desconto 3
	li $v0, 4
	la $a0, msg3
	syscall
	
	#escrita dps de recebido o valor
	li $v0, 2
	mov.s $f12,$f15
	syscall
	j fimse
	
	se4:
	#valor descontado 4
	li $v0, 4
	la $a0, msg2
	syscall
	
	#escrita dps de recebido o valor
	li $v0, 2
	mov.s $f12, $f16
	syscall
	
	#valor apos o desconto 3
	li $v0, 4
	la $a0, msg3
	syscall
	
	#escrita dps de recebido o valor
	li $v0,2
	mov.s $f12, $f17
	syscall
	j fimse
	fimse:
	
	
	
	
	
	
	
	
	