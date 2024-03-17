#include <stdio.h>
#include <stdlib.h>
typedef struct Linklist
{
	int num;
	struct Linklist* next;
}Node;
Node* head;
Node* LinklistCreate();
void LinklistIncrease( int t, int n);
void LinklistDelet( int n);
void LinklistDestroy();
void Linklistsearch( int n);
void print();
void LinklistReverse( );
void  LinklistMiddle( );
 
