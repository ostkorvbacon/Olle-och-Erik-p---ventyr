
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct nodeEl {
	int el;
	struct nodeEl *next;
	
	};


int skriv(struct nodeEl *head)

{	

	if (head!=NULL){
		struct nodeEl node=*head;
		printf("\n El: %d \n",node.el);
		skriv(node.next);
	}
	return 0;
	}

int storlek(struct nodeEl *head)

{	
	if (head!=NULL){
		struct nodeEl node=*head;
		return 1+storlek(node.next);
	
	}
	return 0;
	}
	
	
int nysist(struct nodeEl *head,int a){
	struct nodeEl *node=head;
	
	while (node->next!=NULL) node=node->next;
	
	struct nodeEl *new = malloc(sizeof(struct nodeEl));
	new->el=a;
	new->next=NULL;
	node->next=new;

	return 0;
	}
	
	
int ny(struct nodeEl *head,int a,int pos){
	struct nodeEl *node1=head;
	struct nodeEl *node2=head;
	if (pos==1){
		
		struct nodeEl *new = malloc(sizeof(struct nodeEl));
		new->el=a;
		new->next=head;
		head->next=new;
		return 0;
	}
	for (int i=0;i<pos-2;i++) {
		if (node1->next!=NULL) node1=node1->next;
		else {
			printf("Ogiltig poition");
			return 0;		
		}
	}
		
	for (int i=0;i<pos-1;i++) {
		if (node2->next!=NULL) node2=node2->next;
		else node2=NULL;
	}
	
	
	struct nodeEl *new = malloc(sizeof(struct nodeEl));
	new->el=a;
	new->next=node2;
	node1->next=new;

	return 0;
	}
	
	
int	exit1(struct nodeEl *head) {
	
	struct nodeEl *node=head;
	while (head->next!=NULL) { 
		
		node=head;
		head=head->next;
		free(node);		

	}
	free(head);
	return 0;
}




int main (){
int d1,d2;	
struct nodeEl *node1 = malloc(sizeof(struct nodeEl));
struct nodeEl *node2= malloc(sizeof(struct nodeEl));
struct nodeEl *node3= malloc(sizeof(struct nodeEl));

node1->el=1;
node2->el=2;
node3->el=3;

node1->next = node2;
node2->next = node3;
node3->next=NULL;

int val=42;
struct nodeEl *head=node1;

printf(" 0: Avsluta\n 1:Skriv ut listan\n 2:Skriv ut storlek\n 3: Lägg till sist\n 4:Lägg till på valfri plats\n 5:Ta bort givet tal\n 6:Ta bort på given plats\n 7: Töm listan\n 8:Vänd listan 9:Skifta ett steg åt vänster(första sist)\n 10:Skifta ett steg åt höger(sista först)\n 11:Sortera (lägsta först)\n 12:Skriv ut startadress\n");

while (val!=0){
	
	printf("\n Gör ditt val: ");
	scanf("%d",&val);

	switch (val) {
		
		case 0:
		exit1(head);
			break;
		
		case 1:
			
		    skriv(head);
			break;
		
		case 2:
			printf("\n Storlek: %d\n",storlek(head));
			break;
		
		case 3:
			
			printf("Värde att lagra: ");
			scanf("%d",&d1);
			nysist(head,d1);
			break;
		
		case 4:
			printf("Värde att lagra: ");
			scanf("%d",&d1);
			printf("Position: ");
			scanf("%d",&d2);
			ny(head,d1,d2);
			break;
		
			break;
		
		case 5:
		
			break;

		case 6:
		
			break;
		
		case 7:
		
			break;
		
		case 8:
		
			break;
		
		case 9:
		
			break;
		
		case 10:
		
			break;
		
		case 11:
		
			break;

		case 12:
		
			break;
			
		default:
			
			printf("\n Ogiltig input\n");

	}
}

return 0;

}




