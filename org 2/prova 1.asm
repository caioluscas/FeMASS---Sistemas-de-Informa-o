.data
msg1:.asciiz"\nDiga os tres numeros inteiros positivos : "
msg2:.asciiz"\nNumeros em ordem Crescente: "
msg3:.asciiz ","
msg4:.asciiz "\nDeseja verificar outros numeros?"
.text

main:
	#Diga os tres numeros inteiros positivos
	li $v0, 4
	la $a0, msg1
	syscall
	#receber
	li $v0, 5
   	syscall
    	add $t1, $v0, $zero 
    	#receber
    	li $v0, 5
   	syscall
    	add $t2, $v0, $zero 
	#receber
    	li $v0, 5
    	syscall
    	add $t3, $v0, $zero 
   
    	#branch if greater or equal
    	bge $t1, $t2, se 
    	j senao
    	
    	se:
    	move $t5, $t1 
    	move $t1, $t2 
    	move $t2, $t5 
    	
    	senao: 
    	#maior ou igual
    	bge $t2, $t3, se2 
    	j senao2
    	
    	se2:
    	move $t5, $t2
    	move $t2, $t3 
    	move $t3, $t5 
    	
    	senao2: 
    	#maior ou igual
    	bge $t1, $t2, se3 
  	j senao3
  	
    	se3:
    	move $t5, $t1 
    	move $t1, $t2 
    	move $t2, $t5 
    	
    	senao3: 
    	li $v0, 4
	la $a0, msg2 #ordem crescente
	syscall

	li $v0, 1
	add $a0, $t1, $zero
	syscall

	li $v0, 4
	la $a0, msg3 #","
	syscall

	li $v0, 1
	add $a0, $t2, $zero
	syscall

	li $v0, 4
	la $a0, msg3 #","
	syscall

	li $v0, 1
	add $a0, $t3, $zero
	syscall
