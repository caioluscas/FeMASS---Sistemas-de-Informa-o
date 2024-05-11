.data

msg1: .asciiz "\nDiga o valor da venda: "
msg2: .asciiz "\nvalor do salario junto com comissão: R$ "
num1:.float 1500.0
num2:.float 0.10
num3:.float 0.30
num4:.float 1200.0
.text
main:
#Diga o valor da venda
	li $v0, 4
	la $a0, msg1
	syscall
#recebe o valor de venda
	li $v0, 6
	syscall
	mov.s $f1, $f0
	
	l.s $f6, num4 #1200
	l.s $f2, num1 #1500
	c.lt.s   $f1, $f2
	bc1t se
	bc1f senao
se:
	l.s $f4, num2 #0.10
	
	mul.s $f3,$f1,$f4
	add.s $f5,$f3,$f6
	
	#Valor do salario junto com a comissao
	li $v0, 4
	la $a0, msg2
	syscall
	
	#recebe o valor
	li $v0, 2
	mov.s $f12, $f5
	syscall
	j fimse
	
senao:
	l.s $f7, num3 #0.30
	mul.s $f8,$f1,$f7
	add.s $f9,$f8,$f6
	
	#Valor do salario junto com a comissao
	li $v0, 4
	la $a0, msg2
	syscall
	
	#recebe o valor
	li $v0, 2
	mov.s $f12, $f9
	syscall
	j fimse
	fimse: