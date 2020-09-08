#4.

#addi $t1,$t1,45
#sub $t1,$t1,17
#addi $t1,$t1,78
#addi $t1,$t1,5
#sub $t1,$t1,11

#5. jämför om värdet i $a0< det i $ $t1 och påverkar värden i andra register beroende på resultatet. 
#addi $t0, $zero, 0
#addi $t1, $zero, 1
#loop:
#slt $t2, $a0, $t1
#bne $t2, $zero, finish
#add $t0, $t0, $t1
#addi $t1, $t1, 2
#j loop
#finish:
#add $v0, $t0, $zero

#6.
#add $t1,$t1,0x00000dc0
#add $t2,$t2,0x00003c00

#and $t0, $t1, $t2 # jämför varje bit i t1 och t2 enligt and och lagrar resulterande sekvenen(talet c00 hex eller 3072 decimal) i t0. 
#or $t0, $t1, $t2  # jämför varje bit enligt or och lagrar resulterande sekvenen i t0 och skriver därför över resultatet från and.

#7

#addi $t1,$t1,12
#sub $t1,$t1,45

#8
#addi $t1,$t1,35
#sll $t1,$t1,3 #2^3=8 "bitshifta uppåt (left) 3 steg"
#addi $t2,$t2,35
#srl $t2,$t2,2 #2^2=4 "bitshifta nedsåt (right) 2 steg"

#9 10 11
#.data
#var1: .word 19
#var2: .word 3
#sum: .word 0
#prod: .word 0
#rest: .word 0
#kvot: .word 0
#.text
#lw $t1, var1 #laddar in värde på var1 och var2 till register och adderar dem
#lw $t2, var2
#add $t0, $t1, $t2
#mult $t1,$t2
#mflo $t3
#sw $t3, prod
#sw $t0,sum

#div $t1,$t2
#mflo $t3
#sw $t3,kvot
#mfhi $t3
#sw $t3, rest 

#12 kom tillbaka till

#13 Klart inte värt att spara

#14 kom tillbaka till





