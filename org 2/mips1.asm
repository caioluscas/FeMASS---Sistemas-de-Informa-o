.data
	msg1: .asciiz"\nOlá mundo!"

.text
main:
	li $v0, 4
	la $a0, msg1
syscall


