#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

LinkList ListHeadInsert(LinkList& L) {
	LNode* s; int x;

	L = (LinkList)malloc(sizeof(LNode)); //创建头结点
	L->next = NULL; //初始为空链表
	scanf_s("%d", &x); //输入节点的值
	while (x != 9999) { //输入9999表示结束
		s = (LNode*)malloc(sizeof(LNode)); //创建新节点
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf_s("%d", &x);
	}
	return L;
}

LinkList ListTailInsert(LinkList& L) {
	int x;

	L = (LinkList)malloc(sizeof(LNode));
	LNode* s, * r = L; //r为表尾指针
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf_s("%d", &x);
	}
	r->next = NULL;
	return L;
}

void PrintList(LinkList L) {
	LNode* p;
	p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}