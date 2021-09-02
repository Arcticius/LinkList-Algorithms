#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

int main() {

	LinkList L, L1, L2, L3; LNode* p, * common;

	ListTailInsert(L1); //1 2 3 4 5 6
	//ListTailInsert(L2); //2 3 4 5
	ListTailInsert(L2); //2 5 6
	IsPattern(L1, L2) ? printf("L2 is pattern of L1.") : printf("L2 is NOT pattern of L1.");

	return 0;
}