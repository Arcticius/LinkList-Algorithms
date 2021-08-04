#include "linklist.h"
#include <stdlib.h>

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