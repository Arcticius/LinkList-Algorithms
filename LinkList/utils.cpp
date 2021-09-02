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

bool IsEmpty(LinkList L) {
	return L->next == NULL ? true : false;
}

int Length(LinkList L) {
	int length = 0;
	LNode* p = L->next;

	while (p != NULL) {
		length++;
		p = p->next;
	}

	return length;
}

LNode* GetLastNode(LinkList L) {
	LNode* p = L->next;

	if (p == NULL)
		return L;
	else {
		while (p->next != NULL)
			p = p->next;
		return p;
	}
}

DLinkList ListTailInsert(DLinkList& L) {
	int x;

	L = (DLinkList)malloc(sizeof(DNode));
	DNode* s, * r = L; //r为表尾指针
	//DNode* pre = L; //pre为前驱指针
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (DNode*)malloc(sizeof(DNode));
		s->data = x;
		r->next = s;
		s->prior = r;
		r = s;
		scanf_s("%d", &x);
	}
	r->next = NULL; L->prior = NULL;
	
	return L;
}

void PrintList(DLinkList L) {
	DNode* p;
	p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}

DNode* GetLastNode(DLinkList L) {
	DNode* p = L->next;

	if (p == NULL)
		return L;
	else {
		while (p->next != NULL)
			p = p->next;
		return p;
	}
}

void Circularize(LinkList& L) {
	LNode* last = GetLastNode(L);
	last->next = L;
}

void Circularize(DLinkList& L) {
	DNode* last = GetLastNode(L);
	last->next = L;
	L->prior = last;
}

void PrintCircularList(LinkList L) {
	LNode* p;
	p = L->next;
	while (p != NULL && p != L) {
		printf("%d ", p->data);
		p = p->next;
	}
}

void PrintCircularList(DLinkList L) {
	DNode* p;
	p = L->next;
	while (p != NULL && p != L) {
		printf("%d ", p->data);
		p = p->next;
	}
}