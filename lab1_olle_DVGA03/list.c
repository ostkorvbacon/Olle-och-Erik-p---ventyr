#include "list.h"
#include "node.h"

void skrivList(node *head)
{
  node * temp = head;
  printf("Lista: \t");
  while(temp != NULL)
  {
    printf("%d \t", temp->el);
    temp = temp->next;
  }
  printf("\n");
}

int listStor(node *head)
{
  int n = 0;
  node * temp = head;
  while(temp != NULL)
  {
    n++;
    temp = temp->next;
  }
  return n;
}

node *addSist(node *head)
{
  node * temp = NULL;
  temp = (node*)malloc(sizeof(node));
  printf("Skriv in element: ");
  scanf("%d", &temp->el);
  printf("\n");
  if(head == NULL)
  {
    return temp;
  }
  temp->next = NULL;
  node * temp2 = head;
  while(temp2->next != NULL)
  {
    temp2 = temp2->next;
  }
  temp2->next = temp;
  return head;
}

node *addFri(node *head)
{

  int k, i=0;
  node * temp = NULL;
  temp = (node*)malloc(sizeof(node));
  printf("Skriv in element: ");
  scanf("%d", &temp->el);
  printf("\n");
  printf("Skriv in en position: ");
  scanf("%d", &k);
  printf("\n");

  if(k < 1 || k > listStor(head)+1)
  {
    printf("Postitionen finns inte.\n");
    free(temp);
    return head;
  }
  temp->next = NULL;
  node * tempH1 = head;
  node * tempH2 = head;
  if(k==1)
  {
    temp->next = tempH1;
    return temp;
  }
  for (i = 0; i < (k-2); i++)
  {
		if (tempH1->next != NULL)
      tempH1=tempH1->next;
	}
  for (i = 0; i < (k-1); i++)
  {
		if (tempH2->next != NULL)
      tempH2 = tempH2->next;
		else
      tempH2 = NULL;
	}
  temp->next = tempH2;
  tempH1->next = temp;
  return head;

}

node *bort(node *head)
{
  int j;
  j = hittaEl(head);
  if(j == 0)
  {
    printf("Värdet finns inte i listan\n");
    return head;
  }
  return bortEl(head, j);
}

int hittaEl(node *head)
{
  node * temp = head;
  int k, i=0, j=0;
  printf("Skriv in elementet du vill ta bort: ");
  scanf("%d", &k);
  printf("\n");
  while(temp != NULL)
  {
    i++;
    if(k == temp->el)
    {
      j = i;
      return j;
    }
    temp = temp->next;
  }

  return 0;
}

node *bortEl(node *head, int j)
{
  int i = 0;
  node * temp = head;
  node * tempH1 = head;
  node * tempH2 = head;
  node * tempH3 = head;
  printf("position %d \n", j);

  if(j == 1)
  {
    head = temp->next;
    free(temp);
    return head;
  }
  for(i=0; i < j-2; i++)
  {
      tempH1=tempH1->next;
  }
  for(i=0; i < j-1; i++)
  {
      tempH2=tempH2->next;
  }
  for(i=0; i < j; i++)
  {
    if (tempH3->next != NULL)
      tempH3=tempH3->next;
    else
    {
      tempH1->next = NULL;
      free(tempH3);
      return temp;
    }
  }
  tempH1->next = tempH3;
  free(tempH2);

  return temp;
}

node *bortPlats(node *head)
{
  int k;
  node * temp = head;
  printf("Skriv in en position: ");
  scanf("%d", &k);
  printf("\n");
  if(k > 0 && k <= listStor(temp))
    return bortEl(temp, k);
  else
  {
    printf("Positionen finns inte.\n");
    return temp;
  }
}

node *tomLista(node *head)
{
  if(listStor(head) == 0)
  {
    printf("Listan är redan tom.\n");
    return head;
  }
  node * temp = head;
  node * temp2 = head;

  while(temp != NULL)
  {
    temp = temp->next;
    free(temp2);
    temp2 = temp;
  }
  return NULL;
}

node *vandList(node *head)
{
  if( testList(head) == 0)
    return head;
  node *temp1 = NULL;
  node *tempH  = head;
  node *temp2 = NULL;
  while (tempH != NULL)
  {
    temp2 = tempH->next;
    tempH->next = temp1;
    temp1 = tempH;
    tempH = temp2;
  }
  tempH = temp1;
  return tempH;
}

node *skiftV(node *head)
{
  int i, k;
  node *tempH = head;
  node *tempH2 = head;
  node *temp1 = head;
  node *temp2 = head;

  if( testList(head) == 0)
    return head;

  temp1 = temp1->next;
  k = listStor(tempH);
  for(i=0; i < k-1; i++)
  {
    temp2 = temp2->next;
  }
  tempH = temp1;
  temp2->next = tempH2;
  tempH2->next = NULL;

  return tempH;
}

node *skiftH(node *head)
{
  int i, k;
  node *temp1 = head;
  node *temp2 = head;

  if( testList(head) == 0)
    return head;
  k = listStor(temp1);
  for(i=0; i < k-1; i++)
  {
    temp1 = temp1->next;
  }
  for(i=0; i < k-2; i++)
  {
    temp2 = temp2->next;
  }
  temp2->next = NULL;
  temp1->next = head;
  return temp1;
}

node *sortList(node *head)
{
  int k, i, tempEl;
  node *tempH = head;
  node *temp1 = NULL;
  node *temp2 = NULL;
  node *temp3 = NULL;

  if( testList(head) == 0)
    return head;

  do
  {
    k = 0;
    temp1 = tempH;
    while (temp1->next != NULL)
    {
      if (temp1->el > temp1->next->el)
      {
        temp2 = temp1;
        temp3 = temp1->next;

        tempEl = temp2->el;
        temp2->el = temp3->el;
        temp3->el = tempEl;
        k = 1;
      }
      temp1 = temp1->next;
    }
  }
  while(k == 1);

  return tempH;
}

void skrivAdrs(node *head)
{
  printf("Startadressen är: %ld\n", (long)&head);
}

int testList(node *head)
{
  if(1 > listStor(head))
  {
    printf("Listan är tom.\n");
    return 0;
  }
  else if(listStor(head) == 1)
  {
    printf("Listan inehåller bara ett element.\n");
    return 0;
  }
  else
    return 1;
}
