#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

void DeleteXRecursion(LinkList& L, ElemType x){ //递归删除x
	LNode* p; //p指向待删除结点

	if (L == NULL) //L为空，递归出口
		return;
	else if (L->data == x) { //若L的值为x，删除x
		p = L; //删除*L，并让L指向下一结点
		L = L->next; //L为引用，直接对原链表进行操作
		free(p);
		DeleteXRecursion(L, x);
	}
	else //若L的值不为x，递归删除L->next所指链表中的x
		DeleteXRecursion(L->next, x);
}

void DeleteX(LinkList& L, ElemType x) { //非递归删除x
	LNode* p, *pre, * temp;

	p = L->next; pre = L; //pre为p的前驱
	while (p != NULL) {
		if (p->data == x) { //删除x
			temp = p; 
			p = p->next;
			pre->next = p;
			free(temp);
		}
		else { //否则同步后移
			pre = p;
			p = p->next;
		}
	}
}

void DeleteXTail(LinkList& L, ElemType x) {//非递归删除x，尾插法
	LNode* p, * r, * temp;

	p = L->next; r = L; //r为表尾指针
	while (p != NULL) { //p后移、重构链表r同时进行
		if (p->data != x) { //p的值不为x，则将其插入r尾部
			r->next = p;
			r = p;
			p = p->next;
		}
		else { //p的值为x，删除
			temp = p;
			p = p->next;
			free(temp);
		}
	}

	r->next = NULL; //置重构之后的链表表尾为null
}

void PrintReversedList(LinkList& L) { //链表逆置，递归法
	if (L->next != NULL)
		PrintReversedList(L->next); //递归
	if (L != NULL)
		printf("%d ", L->data); //输出
	//else return;
}

void ReverseList(LinkList& L) { //原地逆置链表，头插法
	LNode* p, * q;
	p = L->next; L->next = NULL;

	while (p != NULL) {
		q = p->next;
		p->next = L->next; //将每个结点依次插入链表头部
		L->next = p;
		p = q;
	}
}

void ReverseListM(LinkList& L) { //原地逆置链表，指针反转法
	LNode* pre, * p, * q; //三指针顺序依次为pre p q，规定pre之前的结点均已逆置

	p = L->next, q = p->next; 
	p->next = NULL;

	while (q != NULL) {
		pre = p; //依次继续遍历
		p = q;
		q = q->next;
		p->next = pre; //指针反转
	}
	L->next = p; //处理头结点
}

void DeleteMin(LinkList& L) { //删除最小值
	LNode* minpre,* min;
	LNode* pre,* p;

	minpre = L, pre = L;
	min = minpre->next, p = pre->next;

	while (p != NULL) { //一次遍历，找出最小值
		if (p->data < min->data) {
			min = p; minpre = pre;
		}
		p = p->next;
		pre = pre->next;
	}

	minpre->next = min->next; //删除最小值
	free(min);
}