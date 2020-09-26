
#include "list.h"
#include "node.h"

int d1,d2;
int size;

//Pre:
//Post:
struct nodeEl * start(struct nodeEl * head){ 
	
	return cnode(head,&size);
	
	}
	

void case0(struct nodeEl *head) {
	
	exit1(head);
	
	}
	
void case1(struct nodeEl *head){
	
	if (size==0) {
		
		printf(" Listan är tom");
	}
	
	else skriv(head);
	
	}
	
void case2 (){
	
	printf(" Antalet element i listan är: %d\n",size);

	}
	
struct nodeEl *case3(struct nodeEl *head){
	
	printf("Värde att lagra: ");
	scanf("%d",&d1);
	
	if (head!=NULL) nysist(head,d1);
			
	else {
		
		head=nynull(head,d1);
		size++;
		return head;

		}
	size++;
	return head;
	}
	
struct nodeEl * case4(struct nodeEl *head){
			
		printf(" Värde att lagra: ");
		scanf("%d",&d1);
		printf(" Position: ");
		scanf("%d",&d2);
		
		if (d2==1) {
			head=nyfirst(head,d1);
			size++;

		}
		else if (d2>1 && d2<=size+1) {
			ny(head,d1,d2);
			size++;
			return head;
		}
			
		else printf("\n Ogiltig position");
		return head;
	
	}
	
struct nodeEl * case5(struct nodeEl *head){
	
			if (size==0) {
					printf("listan tom");
					return NULL;
				}
			printf(" Värde ta bort: ");
			scanf("%d",&d1);
			
			if (sok(head,d1)==0) {
				
				printf(" Talet saknas");
				return head;
			}
			
			else if (sok(head,d1)==1) {
				
				head=rem1(head,size);
				size--;
				return head;
	
				}
				
			else {
				
				remint(head,d1,0);
				size--;
				return head;
			}
	
	}

struct nodeEl * case6(struct nodeEl *head){
	if (size==0) {
		printf(" listan tom");
		return NULL;
	}
	printf(" Position att ta bort: ");
	scanf("%d",&d1);
	if (d1<=size && d1!=1) {
		rem(head,d1);
		size--;
	}
	else if (d1==1 && size>0) {
				
			head=rem1(head,size);
			size--;
			return head;
	}
			
	else printf(" Ogiltig position");
	
	return head;
	}
	
	
struct nodeEl * case7(struct nodeEl *head){
	head=exit1(head);
	size=0;
	return head;
	}
	
void case8(struct nodeEl *head){
	
	turn(head,size);
	
	}
	
void case9(struct nodeEl *head){
	
	shiftl(head,size);
	
	}
	
void case10(struct nodeEl *head){
	shiftr(head,size);
	}
	
void case11(struct nodeEl *head){
	
	sort(head,size);
	
	}
void case12(struct nodeEl *head){
	
	printf(" Startadress: %ld\n",(long)&head);
	
	}

