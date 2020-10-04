#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"


void skrivList(node *head);
int listStor(node *head);
node *addSist(node *head);
node *addFri(node *head);
node *bort(node *head);
int hittaEl(node *head);
node *bortEl(node *head, int j);
node *bortPlats(node *head);
node *tomLista(node *head);
node *vandList(node *head);
node *skiftV(node *head);
node *skiftH(node *head);
node *sortList(node *head);
void skrivAdrs(node *head);
int testList(node *head);

#endif /* LIST_H */
