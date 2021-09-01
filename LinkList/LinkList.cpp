#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

int main() {

	LinkList L, L1, L2, L3; LNode* p, * common;

	//common = SearchCommon(L1, L2);
	//common != NULL? printf("%d", common->data): printf("No common node");

	//ListTailInsert(L1); //2 4 5 9 7 8 1 3
	//L2 = SplitOdevity(L1);
	//PrintList(L1); //2 5 7 1
	//printf("\n");
	//PrintList(L2); //4 9 8 3
	//L2 = SplitOdevityReversed(L1);
	//PrintList(L1); //2 5 7 1
	//printf("\n");
	//PrintList(L2); //3 8 9 4

	//ListTailInsert(L1); //7 10 10 21 30 42 42 42 51 70
	//DeleteSameNode(L1);
	//PrintList(L1);

	//ListTailInsert(L1); //1 2 3 4 5
	//ListTailInsert(L2); //2 3 4 5 6
	//MergeList(L1, L2);
	//PrintList(L1); //6 5 5 4 4 3 3 2 2 1 1

	ListTailInsert(L1); //1 2 3 4 5
	ListTailInsert(L2); //2 3 4 5 6 7
	//L3 = SearchSameNodes(L1, L2);
	//PrintList(L3); //2 3 4 5
	Union(L1, L2);
	PrintList(L1); //2 3 4 5

	return 0;
}