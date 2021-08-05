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

void SortAscending(LinkList& L) { //递增排序，使用插入排序实现
	LNode* p, * pre, * post;

	p = L->next; post = p->next; //post为p的后继
	p->next = NULL; //构造一条初始有序链表 L → p

	p = post; //遍历原链表
	while (p != NULL) {
		post = p->next;

		pre = L; //寻找合适的位置插入p结点，即 pre→p→post
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;

		p->next = pre->next; //插入p结点
		pre->next = p;

		p = post;
	}
}

void DeleteRange(LinkList& L, ElemType min, ElemType max) { //删除介于min和max的结点
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

LNode* SearchCommon(LinkList L1, LinkList L2) { //寻找公共结点，线性复杂度
	int len1, len2, diff;
	LinkList longList, shortList;

	len1 = Length(L1); len2 = Length(L2); //链表L1、L2的长度
	if (len1 > len2) {
		longList = L1; shortList = L2;
		diff = len1 - len2;
	}
	else {
		longList = L2; shortList = L1;
		diff = len2 - len1;
	}

	while (diff--) //长表先后移diff位
		longList = longList->next;

	while (longList != NULL) 
		if (longList == shortList) //找到公共结点
			return longList;
		else {
			longList = longList->next;
			shortList = shortList->next;
		}
	
	return NULL; //两链表尾结点不一致，无公共结点
}

void PrintSort(LinkList& L) { //升序打印结点并依次删除结点
	while (!IsEmpty(L)) {
		LNode* pre, * p, * minpre, * min;

		pre = L, p = pre->next;
		minpre = L, min = minpre->next;
		while (p != NULL) { //依次查找最小值
			if (p->data < min->data) {
				min = p;
				minpre = pre;
			}
			p = p->next; pre = pre->next;
		}

		printf("%d ", min->data); //打印结点
		minpre->next = min->next;
		free(min);
	}
	free(L); //删除头结点
}

LinkList SplitOdevity(LinkList& L1) { //将链表按照结点序号奇偶拆分
	LinkList L2; //规定L1为奇数，L2为偶数
	LNode* pre, * p, * r; //r为L2队尾
	int index = 0;

	L2 = (LinkList)malloc(sizeof(LNode));
	r = L2;

	pre = L1, p = pre->next;
	while (p != NULL) { //遍历L1
		index++; //序号加1

		if (index % 2 == 0) { //p序号为偶数，插入L2
			pre->next = p->next; //从L1取下

			r->next = p; //插入L2
			p->next = NULL;
			r = p;

			p = pre->next;
		}
		else { //p序号为奇数
			p = p->next;
			pre = pre->next;
		}
	}

	return L2;
}

