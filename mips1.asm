.data
space: .asciiz " "
.text
li $v0, 6           
  syscall
  round.w.s $f0, $f0
mfc1 $t3, $f0  
 
 sub $t3, $t3,1
  
  
add $t1, $t1, 1


  bgt $t2, $t3, exit 

  li $v0, 1        # system call code for print_int
  move $a0, $t0       # integer to print
  syscall 
   
    add $t2, $t2, 1
     bgt $t2, $t3, exit 
     
 
  
      li $v0, 4        
  la $a0, space     
  syscall 

  li $v0, 1        # system call code for print_int
  move $a0, $t1       # integer to print
  syscall 
  
    add $t2, $t2, 1
  
loop:

bgt $t2, $t3, exit 

add $t0, $t1, $t0 

    li $v0, 4        
  la $a0, space      
  syscall 

  li $v0, 1        # system call code for print_int
  move $a0, $t0       # integer to print
  syscall 
  
    add $t2, $t2, 1
    
   bgt $t2, $t3, exit 
    
      li $v0, 4        
  la $a0, space     
  syscall 

add $t1, $t1, $t0 

bgt $t2, $t3, exit 

  li $v0, 1        # system call code for print_int
  move $a0, $t1       # integer to print
  syscall 
  
  add $t2, $t2, 1
  
  bgt $t2, $t3, exit 
j loop

exit: 
