.data

antal: .word 10
vek: .word 4,5,2,2,1,6,7,9,5,10
space: .asciiz "\n"
test: .word 0
.text
  
   
    .globl main
  
 main:
 lw $a1,antal #S�tter inparametrar till r�tt v�rden och "hoppar" till subrutinerna. 
  la $a0,vek
 jal skriv
 
  la $a0,vek 
  li $a1,0
  lw $a2,antal
  add $a2,$a2,-1
  jal quickSort
 
 lw $a1,antal
 la $a0,vek
 jal skriv 
  
  li $v0, 10  #Avslutar programmet
    syscall


.globl partition
 partition:
 
 #move $t0,$a0
 move $t1,$a0   #l�ser in v[a] till $t3 => pivot ligger i $t3
 sll $t2,$a1,2
 add $t1,$t1,$t2
 
 lw $t3,($t1)  #l�ser in v[a] till $t3 => pivot ligger i $t3
 add $t4,$a1,1 #lower = a+1
 move $t5,$a2  #upper: $t5
 loop1:
 move $t1,$a0  # l�ser in v[lower] och l�gger i $t6
  sll $t2,$t4,2
 add $t1,$t1,$t2
 lw $t6,($t1)
 
  move $t1,$a0  # l�ser in v[upper] och l�gger i $t7
  sll $t2,$t5,2
 add $t1,$t1,$t2
 lw $t7,($t1)
 
 
 loop2:
 bgt $t6,$t3,end2 # Kollar om v[lower]<=pivot �r uppfyllt
 bgt $t4,$t5,end2 # Kollar om lower<=upper �r uppfyllt
 add $t4,$t4,1 
 
 move $t1,$a0  # l�ser in v[lower] och l�gger i $t6
  sll $t2,$t4,2
 add $t1,$t1,$t2
 lw $t6,($t1)
 
 j loop2
 end2:
 
 loop3:
 blt $t7,$t3,end3 # Kollar om v[upper]>pivot �r uppfyllt
 blt $t5,$t4,end3 # Kollar om lower<=upper �r uppfyllt
add $t5,$t5,-1 

  move $t1,$a0  # l�ser in v[upper] och l�gger i $t7
  sll $t2,$t5,2
 add $t1,$t1,$t2
 lw $t7,($t1)


j loop3
 
end3:
 bgt $t4,$t5,end4  
 
 move $t0,$t6 #Byter plats p� v[upper] och v[lower] i minnet
  move $t1,$a0  
  sll $t2,$t4,2
 add $t1,$t1,$t2
 sw $t7,($t1)
 
  move $t1,$a0
 sll $t2,$t5,2
 add $t1,$t1,$t2
 sw $t0,($t1)

 add $t4,$t4,1 # �kar lower och minskar upper med 1
 add $t5,$t5,-1
end4:   
 bgt $t4,$t5,end1 
 j loop1

end1:
 move $t1,$a0    #Byter plats p� v[a] och v[upper] i minnet
  sll $t2,$t5,2
 add $t1,$t1,$t2
 lw $t0,($t1)
 sw $t3,($t1)
 
 move $t1,$a0
 sll $t2,$a1,2
 add $t1,$t1,$t2
 sw $t0,($t1)
move $v0,$t5
 
 
 
 jr $ra
 

 
  .globl quickSort
  quickSort:

  addu $sp,$sp,-8 # Alokerar plats f�r returadressen
  sw $ra,($sp)
  
  bge $a1,$a2,end5
  la $a0,vek
   move $s2,$a2 # Sparar undan a2 och a1 Anv�ndningen av $s register �r tempor�r tills jag vet exakt vad som m�ste sparas undan. 
   move $s1,$a1 #�terst�ller a1
   jal partition
 
  

 add $a2,$v0,-1	#Minskar returv�rdet fr�n partition med ett och anv�nder det som "b" till n�sta instans av quicksort
  move $a1,$s1
  la $a0,vek
 jal quickSort
  
  move $s2,$a2 #�terst�ller a2
  add $a1,$v0,1 #�kar returv�rdet fr�n partition med ett och anv�nder det som "a" till n�sta instans av quicksort
  la $a0,vek
  jal quickSort
  
  end5:
 
 lw  $ra,($sp)  #l�ser in returadressen
 addu $sp,$sp,8 #Avalokerar minnet
  jr $ra  #hoppar tillbaka till kallande funktion
 
 

 

 
 
 .globl skriv
 skriv:

move $t1,$a0 #flyttar inparametrarna till register som inte beh�vs till "printf"
move $t2,$a1
move $t0,$0  #nollst�ller iterationsvariabeln
move $t7,$ra  #sparar undan adressen tillbaka till main

  li $v0, 4       #F�rsta radbrytning
  la $a0, space     
  syscall 

 a: 
bge  $t0,$t2,loop

  lw $t3,($t1) #l�ser in datan vid adressen 
  
  li $v0, 1        #Printar ut tal fr�n arrayen
  la $a0, ($t3) 
   syscall 
  
  li $v0, 4         #Andra radbrytning
  la $a0, space     
  syscall 
  
   add $t1,$t1,4  #F�rskjuter adressen till n�sta tal i arrayen
   add $t0,$t0,1  #�kar iterationsvariabeln
 j a
 
  loop: 
  move $ra,$t7  #�terst�ller adressen tillbaka till main
  jr $ra 	#hoppasr tillbaka till main

  

  
 
