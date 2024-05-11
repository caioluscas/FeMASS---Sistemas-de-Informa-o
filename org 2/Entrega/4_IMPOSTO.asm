.data
msg1: .asciiz "\nDiga seu o valor de seu salario:: "
msg2: .asciiz "\nisento "
msg3: .asciiz "\nvalor da parcela: R$"
msg4: .asciiz "\nvalor do imposto: R$"
num1:.float 1903.98
num2:.float 2826.65
num3:.float 3751.05
num4:.float 4664.68
num5:.float 0.067
num6:.float 0.075
num7:.float 142.80
num8:.float 0.15
num9:.float 354.80
num10:.float 0.225
num11:.float 636.13
num12:.float 0.275
num13:.float 869.36
num14:.float 
.text
main:
#imprime a diga seu salario
	li $v0, 4
	la $a0, msg1
	syscall
#recebe o valor de salario
	li $v0, 6
	syscall
	mov.s $f1, $f0

	l.s $f2, num1 #1903.98
	c.lt.s   $f1, $f2
	bc1t se
	bc1f senao
	
se:
	li $v0, 4
	la $a0, msg2
	syscall
	j fimse
senao:
	l.s $f3, num2 #<2826.65
	c.lt.s   $f1, $f3
	bc1t se2
	bc1f senao2
	
se2:
	l.s $f4, num5 #0.067
	mul.s $f5,$f1,$f4 #valor da parcela
	l.s $f6, num6 #0.075
	mul.s $f7,$f1,$f6
	l.s $f8, num7 #142.80
	sub.s $f9,$f7,$f8 #valor do imposto
	#Mostrar valor da parcela ao usuário....
	li $v0, 4
	la $a0, msg3
	syscall
	
	li $v0, 2
	mov.s $f12, $f7
	syscall
	
	#Mostrar valor do imposto ao usuário....
	li $v0, 4
	la $a0, msg4
	syscall
	
	li $v0, 2
	mov.s $f12, $f9
	syscall
	j fimse
senao2:
	l.s $f10, num3 #<3751.05
	c.lt.s   $f1, $f10
	bc1t se3
	bc1f senao3
se3:
	l.s $f11, num8 #0.15
	mul.s $f13,$f1,$f11 #valor da parcela
	l.s $f14, num9 #354.80
	sub.s $f15,$f13,$f14 #valor do imposto
	
	#Mostrar valor da parcela ao usuário....
	li $v0, 4
	la $a0, msg3
	syscall
	
	li $v0, 2
	mov.s $f12, $f13
	syscall
	
	#Mostrar valor do imposto ao usuário....
	li $v0, 4
	la $a0, msg4
	syscall
	
	li $v0, 2
	mov.s $f12, $f15
	syscall
	j fimse
senao3:
	l.s $f16, num4 #<4664.68
	c.lt.s   $f1, $f16
	bc1t se4
	bc1f senao4
se4:
	l.s $f17, num10 #0.225
	mul.s $f18,$f1,$f17 #valor da parcela
	l.s $f19, num11 #636.13
	sub.s $f20,$f18,$f19 #valor do imposto
	
	#Mostrar valor da parcela ao usuário....
	li $v0, 4
	la $a0, msg3
	syscall
	
	li $v0, 2
	mov.s $f12, $f18
	syscall
	
	#Mostrar valor do imposto ao usuário....
	li $v0, 4
	la $a0, msg4
	syscall
	
	li $v0, 2
	mov.s $f12, $f20
	syscall
	j fimse
senao4:
	l.s $f21, num12 #0.275
	mul.s $f22,$f1,$f21 #valor da parcela
	l.s $f23, num13 #869.36
	sub.s $f24,$f22,$f23 #valor do imposto
	
	#Mostrar valor da parcela ao usuário....
	li $v0, 4
	la $a0, msg3
	syscall
	
	li $v0, 2
	mov.s $f12, $f22
	syscall
	
	#Mostrar valor do imposto ao usuário....
	li $v0, 4
	la $a0, msg4
	syscall
	
	li $v0, 2
	mov.s $f12, $f24
	syscall
	j fimse
	fimse:
	