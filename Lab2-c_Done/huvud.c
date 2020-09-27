#include "driv.h"
#include "node.h"

int main (){

struct nodeEl *head=NULL; //Declare headand and set it to NULL as per instructions
int val=42; 			//Declare val set it to an arbritary value!=0 to ensure the code in while is run at least once
head=start(head);		//Calls start() and saves a pointer to created list in head	

printf(" 0:Avsluta\n 1:Skriv ut listan\n 2:Skriv ut storlek\n 3:Lägg till sist\n 4:Lägg till på valfri plats\n 5:Ta bort givet tal\n 6:Ta bort på given plats\n 7:Töm listan\n 8:Vänd listan\n 9:Skifta ett steg åt vänster(första sist)\n 10:Skifta ett steg åt höger(sista först)\n 11:Sortera (lägsta först)\n 12:Skriv ut startadress\n");

while (val!=0){
	
	printf("\n Gör ditt val: ");
	scanf("%d",&val);

	switch (val) {  //Menu with functins that execute the users choice
		
		case 0:
		
		case0(head);
		
			break;
		
		case 1:
		
			case1(head);
		
			break;
		
		case 2:
		
			case2();
			
			break;
		
		case 3:
		
			head=case3(head);
		
			break;
		
		case 4:
		
			head=case4(head);
		
			break;
		
		
		case 5:
		
			head=case5(head);
	
			break;

		case 6:
		
			head=case6(head);
	
			break;
		
		case 7:
		
			head=case7(head);
			break;
		
		case 8:
		
			case8(head);
			
			break;
		
		case 9:
		
			case9(head);
			
			break;
		
		case 10:
		
			case10(head);
			
			break;
		
		case 11:
		
			case11(head);
			
			break;

		case 12:
		
			case12(head);
			
			break;
			
		default:
			
			printf("\n Ogiltig input\n");
	}
}

return 0;

}

