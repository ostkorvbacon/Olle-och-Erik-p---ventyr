#include "driv.h"
#include "node.h"


int main()
{
  int n = 4;
  int val;
  node * head = NULL;
  head = startList(n);
  meny();
  do
  {
    val = fval();
    switch (val)
    {
      case 1:  case1(head); break;
      case 2:  case2(head); break;
      case 3:  case3(head); break;
      case 4:  case4(head); break;
      case 5:  case5(head); break;
      case 6:  case6(head); break;
      case 7:  case7(head); break;
      case 8:  case8(head); break;
      case 9:  case9(head); break;
      case 10: case10(head); break;
      case 11: case11(head); break;
      case 12: case12(head); break;
      case 0:  case0(head); break;
      default: printf("Invalid input val är %d \n", val);
    }
  }while(val != 0);

    return 0;
}

node *startList(int n)
{
  int i = 0;
  node * head2 = NULL;
  node * temp = NULL;
  node * norm = NULL;

  for(i; i<n; i++)
  {
    temp = (node*)malloc(sizeof(node)*1);
    temp->el = (i+1);
    temp->next = NULL;
    if(head2 == NULL)
      head2 = temp;
    else
    {
      norm = head2;
      while(norm->next != NULL)
      {
        norm = norm->next;
      }
      norm->next = temp;
    }
  }
  return head2;
}

void meny()
{
  printf("---- Meny ----\n");
  printf("1.  Skriv ut listan.\n");
  printf("2.  Skriv ut listans stolek.\n");
  printf("3.  Lägg till ett heltal sist i listan.\n");
  printf("4.  Lägg till ett heltal på valfri plats.\n");
  printf("5.  Ta bort ett givet heltal.\n");
  printf("6.  Ta bort ett heltal på valfri plats.\n");
  printf("7.  Töm listan.\n");
  printf("8.  Vänd på listan.\n");
  printf("9.  Skifta lista ett steg åt vänster och lägg första heltalet sist.\n");
  printf("10. Skifta listan ett steg åt höger och lägg sista heltalet först.\n");
  printf("11. Sortera lista, lägsta heltalet först.\n");
  printf("12. Skriv ut startadress för listan.\n");
  printf("0. Avsluta.\n");
}

int fval()
{
  int val;
  printf(": ");
  scanf("%d", &val);
  if(val > 13 || val < 0)
    val = -1;
  return val;
}
