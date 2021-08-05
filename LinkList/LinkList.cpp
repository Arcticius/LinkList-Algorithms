#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

int main() {

	LinkList L, L1, L2, L3; LNode* p, * common;

	//ListTailInsert(L1); //1 2 3 4 5
	//ListTailInsert(L2); //8 9 10
	//ListTailInsert(L3); //19 20
	//GetLastNode(L1)->next = L3->next;
	//GetLastNode(L2)->next = L3->next;

	//SortAscending(L);
	//DeleteRange(L, 2, 4);
	//printf("\n");
	//PrintList(L); //1 5

	//common = SearchCommon(L1, L2);
	//common != NULL? printf("%d", common->data): printf("No common node");

	ListTailInsert(L1); //2 4 5 9 7 8 1 3 10
	L2 = SplitOdevity(L1);
	PrintList(L1); //2 5 7 1 10
	printf("\n");
	PrintList(L2); //4 9 8 3

	return 0;
}