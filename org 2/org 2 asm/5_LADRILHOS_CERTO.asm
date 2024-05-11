.data
msg1: .asciiz "\nCalculando a quantidade de ladrilhos para a piscina!"
msg2: .asciiz "\nInforme a altura do lado da piscina em metros :"
msg3: .asciiz "\nInforme a largura do lado da piscina em metros:"
msg4: .asciiz "\nArea Total da Piscina:"
msg5: .asciiz " m²"
msg9: .asciiz "\n*********************************"
msg10:.asciiz "\nInforme a altura do ladrilho em metros :"
msg11:.asciiz "\nInforme a largura do ladrilho em metros:"
msg12:.asciiz "\n*********************************"
msg13:.asciiz "\nQuantidade de ladrilhos necessaria:"

.text

#Printando mensagem na tela
li $v0,4
la $a0,msg1
syscall

#Criando loop
enquanto:

#Solicitando altura
li $v0,4
la $a0,msg2
syscall

li $v0, 6
syscall
mov.s $f1, $f0

#Solicitando largura
li $v0,4
la $a0,msg3
syscall

li $v0, 6
syscall
mov.s $f2, $f0

#$f3 guardará a area dos lados
#$f4 guardará a area total dos lados da piscina
mul.s $f3,$f1,$f2
add.s $f4,$f4,$f3

#Incrementando Contador
add $t5,$t5,1
ble $t5,4,enquanto

#Printando a area total
li $v0,4
la $a0,msg4
syscall
li $v0,2
mov.s $f12, $f4
syscall
li $v0,4
la $a0,msg5
syscall

#Agora, para calcular a area dos ladrilhos
li $v0,4
la $a0,msg9
syscall
#Solicitando altura dos ladrilhos
li $v0,4
la $a0,msg10
syscall

li $v0, 6
syscall
mov.s $f14, $f0

#Solicitando largura dos ladrilhos
li $v0,4
la $a0,msg11
syscall

li $v0, 6
syscall
mov.s $f15, $f0

#Calculando area
mul.s $f16,$f14,$f15

#Calculando a quantidade de ladrilhos necessaria
#Area Total da piscina / Area dos ladrilhos
div.s $f6,$f4,$f16

#Printando Resultado
li $v0,4
la $a0,msg12
syscall

li $v0,4
la $a0,msg13
syscall
li $v0,2
mov.s $f12, $f6
syscall
