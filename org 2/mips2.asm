.data
msg1: .asciiz “\nDigite um numero inteiro: ”
msg2: .asciiz “\nA soma é: ”
.text
main:
li $t1, 10
li $v0, 4
la $a0, msg1
syscall
li $v0, 5
syscall
add $t0, $v0, $zero
add $t0, $t0, $t1
li $v0, 4
la $a0, msg2
syscall
li $v0, 1
add $a0, $t0, $zero
syscall