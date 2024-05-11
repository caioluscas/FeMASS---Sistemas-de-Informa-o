.data
	msg1:.asciiz "diga o número do quarto desejado:"
	msg2:.asciiz "va para a direita"
	msg3:.asciiz "Va para a esquerda "
	num:.float 2.0
.text
main:
#leitura e recebimento de valor
	li $v0, 4
	la $a0, msg1
	syscall
	
	li $v0, 5
	syscall
	
#
	add $t1,$v0,$zero
	rem $t2, $t1, 2
	
	beq $t2,0,se	
	j senao
	
	se:
	li $v0, 4
	la,$a0, msg2
	syscall
	j fimse
	
	senao:
	li $v0, 4
	la,$a0, msg3
	syscall
	
	fimse:
	
	
	
	
