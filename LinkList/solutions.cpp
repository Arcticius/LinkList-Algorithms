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