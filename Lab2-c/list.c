
/*#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
*/
/*struct nodeEl {
	int el;
	struct nodeEl *next;
	
	};
*/
#include "list.h"
#include "node.h"



struct nodeEl * cnode(struct nodeEl * head,int *size) {
	struct nodeEl *node1 = malloc(sizeof(struct nodeEl));
	struct nodeEl *node2= malloc(sizeof(struct nodeEl));
	struct nodeEl *node3= malloc(sizeof(struct nodeEl));

	node1->el=1;
	node2->el=2;
	node3->el=3;
	*size=3;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	
	return node1;
	}

int skriv(struct nodeEl *head)

{	

	if (head!=NULL){
		struct nodeEl *node=head;
		printf("\n El: %d \n",node->el);
		skriv(node->next);
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

	for (int i=0;i<pos-2;i++) {
		node1=node1->next;
		/*
		if (node1->next!=NULL) node1=node1->next;
		else {
			printf(" Ogiltig poition");
			size--;
			return 0;		
		}*/
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
	
struct nodeEl *nyfirst(struct nodeEl *head,int a){
		struct nodeEl *node1=head;
		struct nodeEl *new = malloc(sizeof(struct nodeEl));
		new->el=a;
		new->next=node1;
		
		return new;
}
	
	
struct nodeEl * exit1(struct nodeEl *head) {
	struct nodeEl *node=head;
	while (head!=NULL) { 
		
		node=head->next;;
		free(head);
		head=node;		

	}
	
	return NULL;
}

int isEmp(struct nodeEl *head){
	if (head==NULL) return 1;
	return 0;
	
	
	}

struct nodeEl *nynull(struct nodeEl *head,int a){
	
	head=malloc(sizeof(struct nodeEl));
	head->el=a;
	head->next=NULL;
	return head;
	
	}
	
int sok(struct nodeEl *head,int a)
{
	
	int pos=0;
	struct nodeEl *node=head;
	while (node->next!=NULL) {
		pos++;
		if (a==node->el) return pos;
		node=node->next;
		}
		pos++;
		if (a==node->el) return pos;
		return 0;
}

//Searches for an int in the list
//Pre: Pointer to linked list,Int to be found
//post: returns 1 if found in lis and 0 if not
int sok2(struct nodeEl *head,int a){
	
	if (sok(head,a)>0) return 1;
	
	return 0;
	
	}

//Gör om på engelska
//Pre: Pekare till länkad lista, position i listan där position 1 motsaras av heltalet 1
//Post: returnerar heltalet i noden på givna positionen 

int retur(struct nodeEl *head,int pos){
	
	struct nodeEl *node=head;
	for (int i=1;i<pos;i++){
		node=node->next;
		
		}
		return node->el;	
}


int remint(struct nodeEl *head,int a,int pos){
	
	struct nodeEl *node1=head;
	struct nodeEl *node2=head;
	
	pos=sok(head,a);
	if (pos==0) return 0;
	
		
	for (int i=0;i<pos-2;i++) {
		if (node1->next!=NULL) node2=node2->next;
		
	}	

	for (int i=0;i<pos-1;i++) {
		if (node1->next!=NULL) node1=node1->next;
		
	}
	
	
	node2->next=node1->next;
	free(node1);
	
	

	return 0;
	
	
	
	}


int rem(struct nodeEl *head,int pos){
	
	struct nodeEl *node1=head;
	struct nodeEl *node2=head;
	
	
	if (pos==0) return 0;
	
		
	for (int i=0;i<pos-2;i++) {
		if (node1->next!=NULL) node2=node2->next;
		
	}	

	for (int i=0;i<pos-1;i++) {
		if (node1->next!=NULL) node1=node1->next;
		
	}
		
	node2->next=node1->next;
	free(node1);
	

	return 0;
	
	
	
	}

struct nodeEl * rem1(struct nodeEl *head,int size){
	struct nodeEl *node=head;
	if (size==1) {
		free(node);
		return NULL;
		}
	head=head->next;
	free(node);
	
	return head;
	
	}
	
int skriv2(struct nodeEl *head, int *temp,int size)

{	

	if (head!=NULL){
		struct nodeEl node=*head;
		temp[size-1]=node.el;
		skriv2(node.next,temp,size-1);
	}
	return 0;
	}
	
int skriv3(struct nodeEl *head, int *temp,int size)

{	

		struct nodeEl *node=head;
		for (int i=0;i<size;i++){
		node->el=temp[i];
		node=node->next;
		}
	
	return 0;
	}
	
int turn(struct nodeEl *head,int size){
	int *temp=(int*) malloc(size*sizeof(int));
	skriv2(head,temp,size);
	
	skriv3(head,temp,size);
	
	free(temp);
	return 0;
	}	
	
int sort(struct nodeEl *head,int size){
	int k=0;
	int *temp=(int*) malloc(size*sizeof(int));
	int temp2;
	skriv2(head,temp,size);
	while (k==0) {
		k=1;
		for (int i=0;i<size-1;i++) {
			if (temp[i]>temp[i+1]){
				
				k=0;
				temp2=temp[i+1];
				temp[i+1]=temp[i];
				temp[i]=temp2;
				
			} 	
		}	
	}
	skriv3(head,temp,size);
	free(temp);
	return 0;
}
	
int shiftl(struct nodeEl *head,int size){
	int *temp=(int*) malloc(size*sizeof(int));
	int temp2;
	struct nodeEl *node=head;
	
	for (int i=0;i<size;i++){
		temp[i]=node->el;
		node=node->next;
		}
	
	temp2=temp[0];
	for (int i=0;i<size-1;i++){
		temp[i]=temp[i+1];
	}
	temp[size-1]=temp2;
	skriv3(head,temp,size);
	free(temp);
	return 0;	
}
	
int shiftr(struct nodeEl *head,int size){
	int *temp=(int*) malloc(size*sizeof(int));
	int temp2,temp3;
	struct nodeEl *node=head;
	
	for (int i=0;i<size;i++){
		temp[i]=node->el;
		node=node->next;
		}
	
	temp2=temp[size-1];
	for (int i=size-2;i>=0;i--){
		temp[i+1]=temp[i];
	}
	temp[0]=temp2;
	skriv3(head,temp,size);
	free(temp);
	return 0;	
}
	

/*
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

int size=3;

int val=42;
struct nodeEl *head=node1;

printf(" 0:Avsluta\n 1:Skriv ut listan\n 2:Skriv ut storlek\n 3:Lägg till sist\n 4:Lägg till på valfri plats\n 5:Ta bort givet tal\n 6:Ta bort på given plats\n 7:Töm listan\n 8:Vänd listan\n 9:Skifta ett steg åt vänster(första sist)\n 10:Skifta ett steg åt höger(sista först)\n 11:Sortera (lägsta först)\n 12:Skriv ut startadress\n");

while (val!=0){
	
	printf("\n Gör ditt val: ");
	scanf("%d",&val);

	switch (val) {
		
		case 0:
		exit1(head);
			break;
		
		case 1:
			if (size==0) {
				printf(" Listan är tom");
			}
		    else skriv(head);
		    
			break;
		
		case 2:
			printf(" Antalet element i listan är: %d\n",size);
			break;
		
		case 3:
			printf("Värde att lagra: ");
			scanf("%d",&d1);
			if (head!=NULL) nysist(head,d1);
			
			else head=nynull(head,d1);
			size++;
			break;
		
		case 4:
			printf(" Värde att lagra: ");
			scanf("%d",&d1);
			printf(" Position: ");
			scanf("%d",&d2);
		
			if (d2==1) {
				head=nyfirst(head,d1);
				size++;

		    }
			else if (d2>1) {
				ny(head,d1,d2);
				size++;
			}
			
			else printf(" Ogiltig position");
			
			break;
		
		
		case 5:
			printf(" Värde ta bort: ");
			scanf("%d",&d1);
			if (sok(head,d1)==0) printf(" Talet saknas");
			else if (sok(head,d1)==1) {
				
				head=rem1(head,size);
				size--;
				}
			else {
				
				remint(head,d1,0);
				size--;
			}
			
			break;

		case 6:
			printf(" Position att ta bort: ");
			scanf("%d",&d1);
			if (d1<=size && d1!=1) {
			rem(head,d1);
			size--;
			}
			else if (d1==1 && size>0) {
				
				head=rem1(head,size);
				size--;
			}
			
			else printf(" Ogiltig position");
			
			break;
		
		case 7:
			head=exit1(head);
			size=0;
		
			break;
		
		case 8:
			turn(head,size);
			break;
		
		case 9:
			shiftl(head,size);
			break;
		
		case 10:
			shiftr(head,size);
			break;
		
		case 11:
			sort(head,size);
			break;

		case 12:
			printf(" Startadress: %ld\n",(long)&head);
			break;
			
		default:
			
			printf("\n Ogiltig input\n");

	}
}

return 0;

}
*/



