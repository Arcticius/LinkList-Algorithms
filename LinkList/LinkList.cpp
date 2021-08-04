#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

int main() {

	LinkList L; LNode* p;

	ListTailInsert(L); //2 4 3 1 9
	PrintList(L);

	//DeleteXRecursion(L, 4);
	//DeleteX(L, 4);
	//DeleteXTail(L, 4);
	//PrintReversedList(L->next);
	//ReverseList(L);
	//ReverseListM(L);
	if (!IsEmpty(L)) {
		DeleteMin(L);
		printf("\n");
		PrintList(L); //2 4 3 9
	}
	else
		printf("Empty List");

	return 0;
}