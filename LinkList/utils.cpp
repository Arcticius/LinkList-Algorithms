#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

LinkList ListHeadInsert(LinkList& L) {
	LNode* s; int x;

	L = (LinkList)malloc(sizeof(LNode)); //����ͷ���
	L->next = NULL; //��ʼΪ������
	scanf_s("%d", &x); //����ڵ��ֵ
	while (x != 9999) { //����9999��ʾ����
		s = (LNode*)malloc(sizeof(LNode)); //�����½ڵ�
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
	LNode* s, * r = L; //rΪ��βָ��
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