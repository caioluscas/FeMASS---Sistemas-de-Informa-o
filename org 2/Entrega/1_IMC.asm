.data
	msg1: .asciiz "Diga sua massa:"
	msg2:.asciiz "\nDiga sua altura: "
	
	msg3:.asciiz "\nMagreza grave: "
	num1:.float 16.0
	
	msg4:.asciiz "\nMagreza moderada: "
	num2:.float 17.0
	
	msg5:.asciiz "\nMagreza leve: "
	num3:.float 18.5
	
	msg6:.asciiz "\nSaudavel: "
	num4:.float 25.0
	
	msg7:.asciiz "\nSobrepeso: "
	num5:.float 30.0
	
	msg8:.asciiz "\nObesidade grau I: "
	num6:.float 35.0
	
	msg9:.asciiz "\nObesidade grau II: "
	num7:.float 40.0
	
	msg10:.asciiz "\nObesidade grau III: "
	num8:.float 10000.0
	msg11:.asciiz "\nIMC: "
	
.text
main:
	
	#solicitar sua MASSA
	li $v0, 4
	la $a0, msg1
	syscall
	
	#recebe massa
	li $v0, 6
	syscall
	mov.s $f1,$f0
	
	#Solicitar sua altura
	li $v0, 4
	la $a0, msg2
	syscall
	
	#recebe altura
	li $v0, 6
	syscall 
	mov.s $f2,$f0
	
	#fzr multiplicacao de altura por altura
	mul.s $f3,$f2,$f2
	#divisO pela massa agr
	div.s $f4,$f1,$f3
	
	#magreza grave
	lwc1 $f5, num1
	c.lt.s $f4, $f5 
	bc1t se1
	#magreza moderada
	lwc1 $f6, num2
	c.lt.s $f4, $f6 
	bc1t se2
	#magreza leve
	lwc1 $f7, num3
	c.lt.s $f4, $f7
	bc1t se3
	#saudavel
	lwc1 $f8, num4
	c.lt.s $f4, $f8
	bc1t se4
	#sobrepeso
	lwc1 $f9, num5
	c.lt.s $f4, $f9
	bc1t se5
	#Obesidade grau I
	lwc1 $f10, num6
	c.lt.s $f4, $f10
	bc1t se6
	#Obesidade grau II
	lwc1 $f11, num7
	c.lt.s $f4, $f11 
	bc1t se7
	#Obesidade grau III
	lwc1 $f12, num8
	c.lt.s  $f4, $f12
	bc1t se8
	
	se1: 
	li $v0, 4
	la $a0 , msg3
	syscall
	j fimse
	
	
	se2:
	li $v0, 4
	la, $a0, msg4
	syscall
	j fimse
	
	se3:
	li $v0, 4
	la, $a0, msg5
	syscall
	j fimse
	
	se4:
	li $v0, 4
	la, $a0, msg6
	syscall
	j fimse
	
	se5:
	li $v0, 4
	la, $a0, msg7
	syscall
	j fimse
	
	se6:
	li $v0, 4
	la, $a0, msg8
	syscall
	j fimse
	
	se7:
	li $v0, 4
	la, $a0, msg9
	syscall
	j fimse
	
	se8:
	li $v0, 4
	la, $a0, msg10
	syscall
	j fimse
	fimse:
	
	
	
	
	
	
	
	
	
	
	
