#include "list.h"
#include "node.h"
int n;

void case1(node *head)
{
  skrivList(head);
}

void case2(node *head)
{
  n = listStor(head);
  printf("Listan har %d noder.\n", n);
}

node *case3(node *head)
{
head = addSist(head);
return head;
}

node *case4(node *head)
{
head = addFri(head);
return head;
}

node *case5(node *head)
{
head = bort(head);
return head;
}

node *case6(node *head)
{
head = bortPlats(head);
return head;
}

node *case7(node *head)
{
head = tomLista(head);
return head;
}

node *case8(node* head)
{
head = vandList(head);
return head;
}

node *case9(node *head)
{
head = skiftV(head);
return head;
}

node *case10(node *head)
{
head = skiftH(head);
return head;
}

node *case11(node *head)
{
head = sortList(head);
return head;
}

void case12(node *head)
{
skrivAdrs(head);
}

void case0(node *head)
{
tomLista(head); printf("Exit.\n");
}
