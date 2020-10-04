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

void case3(node *head)
{
head = addSist(head);
}

void case4(node *head)
{
head = addFri(head);
}

case5(node *head)
{
head = bort(head);
}

void case6(node *head)
{
head = bortPlats(head);
}

void case7(node *head)
{
head = tomLista(head);
}

void case8(node* head)
{
head = vandList(head);
}

void case9(node *head)
{
head = skiftV(head);
}

void case10(node *head)
{
head = skiftH(head);
}

void case11(node *head)
{
head = sortList(head);
}

void case12(node *head)
{
skrivAdrs(head);
}

void case0(node *head)
{
tomLista(head); printf("Exit.\n");
}
