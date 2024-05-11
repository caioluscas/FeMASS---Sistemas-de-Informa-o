.data
	msg1:.asciiz "\nQuantas notas que irão compor o cálculo da Média? "
	msg2: .asciiz " - Digite a nota do aluno: "
	msg3: .asciiz "\n"
	msg4: .asciiz "\n Reprovado         \n "
	msg5: .asciiz "\n Aprovado          \n "
	msg6: .asciiz "\n Prova Final!      \n "
	msg7: .asciiz "\n Média: "
	msg8: .asciiz "\nDeseja apurar novo resultado? 1)Sim ### 2)Sair "
	num1:.float 4.0
	num2:.float 7.0
	num3:.float 1.0
	num4:.float 0.0
.text

main:
	l.s $f1, num1
	l.s $f2, num2
	l.s $f3, num3 #f3 1
	l.s $f4, num4
	
	#Quantas notas serão utilizada no cálculo da Média
	li $v0, 4
	la $a0, msg1
	syscall
	#recebe notas
	li $v0, 6
	syscall
	mov.s $f5,$f0
	
	enquanto:
	l.s $f7, num3 #f7 1
	# Digite a nota do aluno:
		li $v0,4
		la $a0,msg2
		syscall
		#recebe
		li $v0, 6
		syscall
		mov.s $f6,$f0
		
	#total de notas
		add.s $f4, $f4, $f6 #f4 0
		add.s $f3, $f3, $f7
		c.le.s $f3, $f5
		
	bc1t enquanto
		
	#media
	div.s $f8, $f4, $f5
	#média
	li $v0, 4
	la $a0, msg7
	syscall
	#escreve valor da média
	li $v0, 2
	mov.s $f12, $f8
	syscall
	
	
	#situacao do aluno
	c.lt.s $f8, $f1 #menor que 4
	bc1t se1
	bc1f senao1
	
	se1:
		li $v0,4
		la $a0,msg4		#Reprovado
		syscall
		j fimse
	
	senao1:
		
		c.lt.s $f8, $f2   #$f2-7.0
		bc1t se2
		bc1f senao2
	
	se2:
		li $v0,4
		la $a0,msg6		#Prova final
		syscall
		j fimse
		
	senao2:
		li $v0,4
		la $a0,msg5		#Aprovado
		syscall
		j fimse
		
	fimse:
	
	#repetir codigo
	li $v0,4
	la $a0,msg8
	syscall
	#recebe
	li $v0, 6
	syscall
	mov.s $f10,$f0
	
	c.le.s $f10, $f3
	bc1t main
