#include <stdio.h>
#include <stdlib.h>
typedef struct Linklist
{
	int num;
	struct Linklist* next;
}Node;
Node* head = NULL;
void LinklistCreate();
void LinklistIncrease(Node** head, int t, int n);
void LinklistDelet(Node** head, int n);
void LinklistDestroy(Node** head);
void Linklistsearch(Node** head, int n);
void print(Node** head);
void LinklistReverse(Node** head);
void  LinklistMiddle(Node** head);
 
