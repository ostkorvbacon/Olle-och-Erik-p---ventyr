.data
	vek: .word 4,5,2,2,1,6,7,9,5,10
	antal: .word 10
	out_string1: .asciiz "\n"
	out_string2: .asciiz "%d"

.text
.globl main
main:
	lw $a0, antal
	la $a1, vek
	jal skriv
	
	la $a0, vek
	lw $a1, antal
	subi $a2, $a1, 1
	li $a1, 0
	jal quickSort
	
	la $a1, vek
	move $a2, $t0
	jal skriv
	li $v0, 10
    	syscall
	

.globl skriv
skriv:	
	
	move $t1, $a1
	move $t3, $a0
	move $t5,$ra
	
	li $v0, 4 
	la $a0, out_string1
	syscall
	
	forloop:
    	bge $t4, $t3, end

    	# load word from addrs and goes to the next addrs
    	lw $t2, 0($t1)
    	addi $t1, $t1, 4

    	# syscall to print value
   	li $v0, 1      
    	move $a0, $t2
    	syscall
 
 	li $v0, 11  
    	li $a0, 32 # 32 är space i ascii table
    	syscall


    	#increment counter
    	addi $t4, $t4, 1
    	j forloop

 	end:
 	
 	li $v0, 4 
	la $a0, out_string1
	syscall
	
	move $ra, $t5
	jr $ra 


.globl quickSort
quickSort:
	
	subu $sp, $sp, 12
  	sw $ra, ($sp)
  	sw $s1, 4($sp)
  	sw $s2, 8($sp)
  	move $s1, $a1 		# a 0
  	move $s2, $a2 		# b 9

	forloop2:
	bgt $a1, $a2, end2
	
	jal partition
	
	add $a2, $v0, -1 	# $a2 = k -1
	la $a0,vek
	jal quickSort
	
	la $a0,vek
	add $a1, $v0, 1 	# $a1 = k+1
	move $a2, $s2 		# $a2 = b
	jal quickSort
	
	j forloop2
	end2:
	
 	lw  $ra, ($sp)
 	lw  $s1, 4($sp) 
 	lw  $s2, 8($sp) 
 	addu $sp, $sp, 12
 	jr $ra

.globl partition
partition:

	subu $sp, $sp, 16
  	sw $ra, ($sp)
    	sw $s0, 4($sp)
      	sw $s1, 8($sp)
        sw $s2, 12($sp)

  	
  	move $t0, $a0 
  	sll $t1, $a1, 2 
  	addu $t0, $t0, $t1
  	lw $t3, ($t0) 		#pivot = $t3
  	move $t0, $a0 		#v[] = $t0
  	
  	addi $t1, $a1, 1  	#lower = $t1
  	
  	move $t2, $a2 		#upper = $t2
  	
  	doWhile:
  	while1:
  	sll $s1, $t1, 2 
  	addu $s0, $t0, $s1
  	lw $t4, ($s0) 		# $t4 = v[lower]
  	bge $t4, $t3, whileEnd1
  	bge $t1, $t2, whileEnd1
  	add $t1, $t1, 1
  	
  	j while1
 	whileEnd1:
 	
 	while2:
  	sll $s1, $t2, 2
  	addu $s0, $t0, $s1
  	lw $t5, ($s0) 		# $t5 = v[upper]
  	blt $t5, $t3, whileEnd2
  	bge $t1, $t2, whileEnd2
  	sub $t2, $t2, 1
  	
  	j while2
 	whileEnd2:
  	
  	bge $t1, $t2, ifEnd
  	
  	sll $s1, $t1, 2 
  	addu $s0, $t0, $s1
  	lw $t4, ($s0)
  	
  	sll $s1, $t2, 2
  	addu $s0, $t0, $s1
  	lw $t4, ($s0)
  	
  	move $s0, $t4
  	move $t4, $t5
  	move $t5, $s0
  	add $t1, $t1, 1
  	sub $t2, $t2, 1
  		
  	ifEnd:
  	
	ble $t1, $t2, doWhile

	sll $s1, $t1, 2 
  	addu $s0, $t0, $s1
  	lw $t4, ($s0)
  	
  	sll $s1, $t2, 2
  	addu $s0, $t0, $s1
  	lw $t4, ($s0)
	
	move $s0, $t5
	move $t5, $t3
	move $t3, $s0
  	
  	
  	lw  $ra, ($sp) 
  	lw  $s0, 4($sp) 
    	lw  $s1, 8($sp) 
       	lw  $s2, 12($sp) 
 	addu $sp, $sp, 16
 	
 	move $v0, $t2
 	jr $ra


