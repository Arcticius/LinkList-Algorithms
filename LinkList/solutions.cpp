#include "linklist.h"
#include <stdlib.h>

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