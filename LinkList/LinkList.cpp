#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

int main() {

	LinkList L, L1, L2, L3; LNode* p, * common;
	DLinkList DL; DNode* dp;
	DFLinkList DFL; 
	int x;

	//ListTailInsert(DL); //1 2 3 3 2 
	//Circularize(DL);
	//IsSymmetrical(DL) ? printf("DL is symmetrical.") : printf("DL is NOT symmetrical");

	//ListTailInsert(L1); //1 2 3 4
	//ListTailInsert(L2); //5 6 7
	//Circularize(L1); Circularize(L2);
	//LinkCircularLists(L1, L2); 
	//PrintCircularList(L1);

	//ListTailInsert(L); //5 7 4 1 2 9 8
	//Circularize(L);
	//DeleteAllMins(L);

	ListTailInsert(DFL); // 1 2 3 5 4 9
	scanf_s("%d", &x);
	while (x != 9999) {
		Locate(DFL, x) ? printf("x(which is %d) found.\n", x) : printf("x(which is %d) NOT found.\n", x);
		PrintList(DFL); printf("\n");
		scanf_s("%d", &x);
	}

	return 0;
}