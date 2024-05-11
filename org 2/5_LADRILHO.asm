.data
msg1: .asciiz "\nDiga a altura deste lado da piscina:"
msg2: .asciiz "\nDiga a largura deste lado da piscina: "
msg3: .asciiz "\nDiga sua altura do fundo da piscina: "
msg4: .asciiz "\nDiga sua largura do fundo da piscina: "
msg5: .asciiz "\nInforme a altura do ladrilho utilizado: "
msg6: .asciiz "\nInforme a largura do ladrilho utilizado: "
msg7: .asciiz "\n Àrea do lado 1:"
msg8: .asciiz "\n Àrea do lado 2:"
msg9: .asciiz "\n Àrea do lado 3:"
msg10: .asciiz "\n Àrea do lado 4:"
msg11: .asciiz "\n Àrea do lado 5:"
num1:.float 1.0
num2:.float 5.0
.text
main:
#Informe a altura do ladrilho utilizado: 
	li $v0, 4
	la $a0, msg5
	syscall
#recebe altura do ladrilho utilizado
	li $v0, 6
	syscall
	mov.s $f1, $f0
	
	
#Informe a largura do ladrilho utilizado:
	li $v0, 4
	la $a0, msg6
	syscall
#recebe largura do ladrilho utilizado:
	li $v0, 6
	syscall
	mov.s $f2, $f0


#Diga sua altura do fundo da piscina:
	li $v0, 4
	la $a0, msg3
	syscall
#recebe altura do  fundo da piscina:
	li $v0, 6
	syscall
	mov.s $f3, $f0
	
#Diga sua largura do fundo da piscina:
	li $v0, 4
	la $a0,msg4
	syscall
#recebe largura do fundo da piscina:
	li $v0, 6
	syscall
	mov.s $f4, $f0
	
	l.s $f5, num1
	l.s $f6, num2
	
enquanto:
	


c.le.s $f5, $f6
bc1t enquanto
