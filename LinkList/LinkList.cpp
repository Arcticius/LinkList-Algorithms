#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

int main() {

	LinkList L, L1, L2, L3; LNode* p, * common, * q, * loopStart;
	DLinkList DL; DNode* dp;
	DFLinkList DFL; 
	int x;

	/*ListTailInsert(DL); //1 2 3 3 2 
	Circularize(DL);
	IsSymmetrical(DL) ? printf("DL is symmetrical.") : printf("DL is NOT symmetrical");

	ListTailInsert(L1); //1 2 3 4
	ListTailInsert(L2); //5 6 7
	Circularize(L1); Circularize(L2);
	LinkCircularLists(L1, L2); 
	PrintCircularList(L1);

	ListTailInsert(L); //5 7 4 1 2 9 8
	Circularize(L);
	DeleteAllMins(L);

	ListTailInsert(DFL); // 1 2 3 5 4 9
	scanf_s("%d", &x);
	while (x != 9999) {
		Locate(DFL, x) ? printf("x(which is %d) found.\n", x) : printf("x(which is %d) NOT found.\n", x);
		PrintList(DFL); printf("\n");
		scanf_s("%d", &x);
	}*/

	/*ListTailInsert(L); //1 3 5 7 9
	SearchLastK(L, 6) ? printf("Element found.\n") : printf("Element NOT found.\n");*/

	/*ListTailInsert(L); //21 -15 -15 7 15 -7
	DeleteAllSameNode(L, 21);
	PrintList(L); //21 -15 7*/

	/*ListTailInsert(L); //1 4 3 2 6 8 7 5
	//p = GetLastNode(L); q = LocateX(L, 2); p->next = q; //1 4 3 (2 6 8 7 5)
	loopStart = FindLoopStart(L);
	loopStart ? printf("Loop start exists, which is %d.\n", loopStart->data) : printf("Loop start DOES NOT exist.\n");
	*/

	ListTailInsert(L); //1 2 3 4 5 6 7 8 9 10
	RealignList(L);
	PrintList(L); //1 10 2 9 3 8 4 7 5 6

	return 0;
}