#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

void DeleteXRecursion(LinkList& L, ElemType x){ //�ݹ�ɾ��x
	LNode* p; //pָ���ɾ�����

	if (L == NULL) //LΪ�գ��ݹ����
		return;
	else if (L->data == x) { //��L��ֵΪx��ɾ��x
		p = L; //ɾ��*L������Lָ����һ���
		L = L->next; //LΪ���ã�ֱ�Ӷ�ԭ������в���
		free(p);
		DeleteXRecursion(L, x);
	}
	else //��L��ֵ��Ϊx���ݹ�ɾ��L->next��ָ�����е�x
		DeleteXRecursion(L->next, x);
}

void DeleteX(LinkList& L, ElemType x) { //�ǵݹ�ɾ��x
	LNode* p, *pre, * temp;

	p = L->next; pre = L; //preΪp��ǰ��
	while (p != NULL) {
		if (p->data == x) { //ɾ��x
			temp = p; 
			p = p->next;
			pre->next = p;
			free(temp);
		}
		else { //����ͬ������
			pre = p;
			p = p->next;
		}
	}
}

void DeleteXTail(LinkList& L, ElemType x) {//�ǵݹ�ɾ��x��β�巨
	LNode* p, * r, * temp;

	p = L->next; r = L; //rΪ��βָ��
	while (p != NULL) { //p���ơ��ع�����rͬʱ����
		if (p->data != x) { //p��ֵ��Ϊx���������rβ��
			r->next = p;
			r = p;
			p = p->next;
		}
		else { //p��ֵΪx��ɾ��
			temp = p;
			p = p->next;
			free(temp);
		}
	}

	r->next = NULL; //���ع�֮��������βΪnull
}

void PrintReversedList(LinkList& L) { //�������ã��ݹ鷨
	if (L->next != NULL)
		PrintReversedList(L->next); //�ݹ�
	if (L != NULL)
		printf("%d ", L->data); //���
	//else return;
}

void ReverseList(LinkList& L) { //ԭ����������ͷ�巨
	LNode* p, * q;
	p = L->next; L->next = NULL;

	while (p != NULL) {
		q = p->next;
		p->next = L->next; //��ÿ��������β�������ͷ��
		L->next = p;
		p = q;
	}
}

void ReverseListM(LinkList& L) { //ԭ����������ָ�뷴ת��
	LNode* pre, * p, * q; //��ָ��˳������Ϊpre p q���涨pre֮ǰ�Ľ���������

	p = L->next, q = p->next; 
	p->next = NULL;

	while (q != NULL) {
		pre = p; //���μ�������
		p = q;
		q = q->next;
		p->next = pre; //ָ�뷴ת
	}
	L->next = p; //����ͷ���
}

void DeleteMin(LinkList& L) { //ɾ����Сֵ
	LNode* minpre,* min;
	LNode* pre,* p;

	minpre = L, pre = L;
	min = minpre->next, p = pre->next;

	while (p != NULL) { //һ�α������ҳ���Сֵ
		if (p->data < min->data) {
			min = p; minpre = pre;
		}
		p = p->next;
		pre = pre->next;
	}

	minpre->next = min->next; //ɾ����Сֵ
	free(min);
}

void SortAscending(LinkList& L) { //��������ʹ�ò�������ʵ��
	LNode* p, * pre, * post;

	p = L->next; post = p->next; //postΪp�ĺ��
	p->next = NULL; //����һ����ʼ�������� L �� p

	p = post; //����ԭ����
	while (p != NULL) {
		post = p->next;

		pre = L; //Ѱ�Һ��ʵ�λ�ò���p��㣬�� pre��p��post
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;

		p->next = pre->next; //����p���
		pre->next = p;

		p = post;
	}
}

void DeleteRange(LinkList& L, ElemType min, ElemType max) { //ɾ������min��max�Ľ��
	LNode* p, * pre;

	pre = L; p = pre->next;
	while (p != NULL) {
		if (p->data >= min && p->data <= max) {
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else {
			pre = p;
			p = p->next;
		}
	}
}

LNode* SearchCommon(LinkList L1, LinkList L2) { //Ѱ�ҹ�����㣬���Ը��Ӷ�
	int len1, len2, diff;
	LinkList longList, shortList;

	len1 = Length(L1); len2 = Length(L2); //����L1��L2�ĳ���
	if (len1 > len2) {
		longList = L1; shortList = L2;
		diff = len1 - len2;
	}
	else {
		longList = L2; shortList = L1;
		diff = len2 - len1;
	}

	while (diff--) //�����Ⱥ���diffλ
		longList = longList->next;

	while (longList != NULL) 
		if (longList == shortList) //�ҵ��������
			return longList;
		else {
			longList = longList->next;
			shortList = shortList->next;
		}
	
	return NULL; //������β��㲻һ�£��޹������
}

void PrintSort(LinkList& L) { //�����ӡ��㲢����ɾ�����
	while (!IsEmpty(L)) {
		LNode* pre, * p, * minpre, * min;

		pre = L, p = pre->next;
		minpre = L, min = minpre->next;
		while (p != NULL) { //���β�����Сֵ
			if (p->data < min->data) {
				min = p;
				minpre = pre;
			}
			p = p->next; pre = pre->next;
		}

		printf("%d ", min->data); //��ӡ���
		minpre->next = min->next;
		free(min);
	}
	free(L); //ɾ��ͷ���
}

LinkList SplitOdevity(LinkList& L1) { //�������ս�������ż���
	LinkList L2; //�涨L1Ϊ������L2Ϊż��
	LNode* pre, * p, * r; //rΪL2��β
	int index = 0;

	L2 = (LinkList)malloc(sizeof(LNode));
	r = L2;

	pre = L1, p = pre->next;
	while (p != NULL) { //����L1
		index++; //��ż�1

		if (index % 2 == 0) { //p���Ϊż��������L2
			pre->next = p->next; //��L1ȡ��

			r->next = p; //����L2
			p->next = NULL;
			r = p;

			p = pre->next;
		}
		else { //p���Ϊ����
			p = p->next;
			pre = pre->next;
		}
	}

	return L2;
}

