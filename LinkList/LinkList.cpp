#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

int main() {

	LinkList L; LNode* p;

	ListTailInsert(L); //3 4 5 4 6 
	PrintList(L);

	//DeleteXRecursion(L, 4);
	//DeleteX(L, 4);
	DeleteXTail(L, 4);
	printf("\n");
	PrintList(L); //3 5 6

	return 0;
}