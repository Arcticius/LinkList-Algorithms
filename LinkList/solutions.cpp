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

LinkList SplitOdevityReversed(LinkList& L1) { //�������ս�������ż��֣���ֳ���������������
	LinkList L2 = (LinkList)malloc(sizeof(LNode)); //����������L2
	L2->next = NULL;

	LNode* rear1 = L1; //rear1ʼ��ָ��L1��β
	LNode* p = L1->next, * q = NULL; //qΪp�ĺ��

	while (p != NULL) {
		rear1->next = p; rear1 = p;//p�˴�ΪL1��㣬��p����L1��β
		p = p->next; //p�˴�ΪL2���
		if (p != NULL)
			q = p->next; //��¼p�ĺ�̣���ֹ����
		p->next = L2->next; L2->next = p; //ͷ�巨��p��������L2
		p = q; //p�˴�ΪL1���
	}

	rear1->next = NULL;

	return L2;
}

void DeleteSameNode(LinkList& L) {  //ɾ�������������Ƚ��
	LNode* p, * q; //pָ���������qΪp�ĺ��

	p = L->next;

	if (p == NULL) //�ձ�
		return;
	while (p != NULL) {
		q = p->next;

		if (q != NULL && p->data == q->data) { //p�ͺ����ͬ��ɾ��q��ֱ�������p��ͬΪֹ
			p->next = q->next;
			free(q);
		}
		else //p�ͺ�̲���ͬ����������
			p = p->next;
			
	}
}

void MergeList(LinkList& L1, LinkList& L2) { //ԭ�غϲ������������ϲ��������ӦΪ�ݼ�
	LNode* p1, * p2, * r; 
	p1 = L1->next; p2 = L2->next;

	L1->next = NULL; //�涨�ϲ����ʣL1������Ϊ�ݼ�������ͷ�巨
	while (p1 && p2) { //p1��p2���ǿ�ʱ
		if (p1->data <= p2->data) { //p1��С
			r = p1->next; //��¼p1��̣���ֹ����
			p1->next = L1->next; L1->next = p1; //��p1ͷ����L1
			p1 = r;
		}
		else { //p2��С
			r = p2->next; //��¼p2��̣���ֹ����
			p2->next = L1->next; L1->next = p2; //��p2ͷ����L1
			p2 = r;
		}
	}

	p2 = p1 != NULL ? p1 : p2; //��L1�ϳ�����p2�ѿգ���L1ʣ���㸳��p2

	while (p2) { //��ʣ��������ͷ����L1
		r = p2->next;
		p2->next = L1->next; L1->next = p2;
		p2 = r;
	}

	free(L2); //�ͷ�L2ͷ���
}

LinkList SearchSameNodes(LinkList& L1, LinkList& L2) { //Ѱ���������������Ƚ�㣬����������
	LinkList L3 = (LinkList)malloc(sizeof(LNode)); //��Ƚ�㹹�ɵ�������
	LNode* p1, * p2, * p3, *same;
	p1 = L1->next; p2 = L2->next; p3 = L3;
	
	while (p1 != NULL && p2 != NULL) {
		if (p1->data < p2->data) //p1��С������
			p1 = p1->next;
		else if (p2->data < p1->data) //p2��С������
			p2 = p2->next;
		else { //p1��p2��ȣ��ҵ���Ƚ�㣬β����L3
			same = (LNode*)malloc(sizeof(LNode));
			same->data = p1->data;
			p3->next = same; p3 = same; //β��
			p1 = p1->next; p2 = p2->next; //ͬʱ����
		}
	}

	p3->next = NULL;
	return L3;
}

void Union(LinkList& L1, LinkList& L2) { //Ѱ������������Ľ���������L1��
	LNode* p1, * p2, * p, * temp;
	p1 = L1->next; p2 = L2->next;
	p = L1;

	while (p1 && p2) { //p1��p2���ǿ�ʱ 
		if (p1->data < p2->data) { //p1��С������
			temp = p1;
			p1 = p1->next;
			free(temp);
		}
		else if (p2->data < p1->data) { //p1��С������
			temp = p2;
			p2 = p2->next;
			free(temp);
		}
		else { //p1��p2��ȣ��ҵ�����Ԫ�أ�β����L1
			p->next = p1; p = p1; //β��

			p1 = p1->next;

			temp = p2; //�ͷ�L2���
			p2 = p2->next;
			free(temp);
		}
	}

	while (p1) { //L1����ʣ����
		temp = p1;
		p1 = p1->next;
		free(temp);
	} 
	while (p2) { //L2����ʣ����
		temp = p2;
		p2 = p2->next;
		free(temp);
	}

	p->next = NULL;
	free(L2); //�ͷ�L2ͷ���
}

bool IsPattern(LinkList L1, LinkList L2) { //�ж�L2�Ƿ�ΪL1������������
	LNode* p1, * p2, * start; //start��¼L1ÿ�α�������ʼλ��
	p1 = L1->next; p2 = L2->next; start = p1;

	while (p1 && p2) {
		if (p1->data == p2->data) { //��Ӧ��ͬ
			p1 = p1->next;
			p2 = p2->next;
		} 
		else { //��Ӧ����ͬ��p1���˵���ʼλ�õĺ�̣�p2���˵���ʼλ��
			start = start->next;
			p1 = start;
			p2 = L2->next;
		}
	}

	if (p2 == NULL) //L2��ȫ��������˵��L2��������
		return true;
	else 
		return false;
}

bool IsSymmetrical(DLinkList& L) { //�ж�ѭ��˫�����Ƿ�Գ�
	DNode* p, * q; //��ָ��ֱ��ǰ�����
	p = L->next; q = L->prior;

	while (p != q && q->next != p) { //ѭ����ֹ����������ʱp��qָ��ͬһ�ڵ㣻ż��ʱp��q����
		if (p->data == q->data) {
			p = p->next;
			q = q->prior;
		}
		else
			return false;
	}

	return true;
}

void LinkCircularLists(LinkList& L1, LinkList& L2) { //��ѭ������L2���ӵ�ѭ������L1֮��
	LNode* last1, * last2;

	last1 = L1; last2 = L2;
	while (last1->next != L1) //�ҳ��������β���
		last1 = last1->next;
	while (last2->next != L2)
		last2 = last2->next;

	last1->next = L2->next;
	last2->next = L1;
}

void DeleteAllMins(LinkList& L) { //���������ɾ��ѭ���������Сֵ
	LNode* p, * pre, * min, * minpre;
	while (L->next != L) { //ѭ������ǿ��ж�
		p = L->next, pre = L;
		min = p, minpre = pre;
		while (p != L) { //������������Ѱ����Сֵ
			if (p->data < min->data) {
				min = p; minpre = pre;
			}
			p = p->next; pre = pre->next;
		}

		printf("%d ", min->data); //����˴�ѭ������Сֵ
		minpre->next = min->next; //ɾ���ý��
		free(min);
	}
	free(L); //�ͷ�ͷ���
}

DFNode* Locate(DFLinkList& L, ElemType x) { //����x���ɹ�ʱ��Ƶ����1��������㰴Ƶ�Ƚ�������
	DFNode* p, * pre; //preΪp��ǰ��

	p = L->next;
	while (p != NULL && p->data != x) //��������Ѱ��x
		p = p->next;

	if (p == NULL) //δ�ҵ�x
		return NULL;
	else { //�ҵ�x������Ƶ�Ȳ���������
		p->freq++; //����Ƶ��

		if (p->next != NULL) //ժ��p���
			p->next->prior = p->prior;
		p->prior->next = p->next;

		pre = p->prior;
		while (pre != L && pre->freq <= p->freq) //Ѱ�Ҳ���λ��
			pre = pre->prior;
		
		p->next = pre->next; p->prior = pre; //����p���
		pre->next->prior = p; pre->next = p;
	}

	return p;
}

bool SearchLastK(LinkList L, ElemType k) { //���ҵ�����k��Ԫ�أ������ܸ�Ч��˫ָ�뷨
	LNode* p, * q; //˫ָ��
	p = q = L->next; //��ʼʱ��ָ���һ���ڵ�
	int count = 0; //������

	while (p != NULL) { //����˫ָ�뷨���������һ������
		if (count < k) //��count<k������ƶ�p
			count++;
		else //count=kʱ��q��ʼ���ƣ���p������ʱ��qǡ��λ�ڵ�����k��Ԫ����
			q = q->next;

		p = p->next;
	}

	if (count < k) //�����ڵ�����k��Ԫ��
		return false;
	else {
		printf("%d \n", q->data);
		return true;
	}
}

void DeleteAllSameNode(LinkList& L, ElemType n) { //ɾ�������������ȣ�������ֵ����㣬�������鷨
	//����Ԫ�ص�ֵ������n
	LNode* p, * r;
	p = L;

	ElemType* arr, m; //��������
	arr = (ElemType*)malloc(sizeof(ElemType) * (n + 1)); //����n+1��λ����Ϊ�������飬�����±귨

	for (int i = 0; i < n + 1; i++) //��ʼ������Ԫ��Ϊ0����ʾδ����
		*(arr + i) = 0;

	while (p->next != NULL) { //����һ������
		m = p->next->data > 0 ? p->next->data : -p->next->data; //ȡ����ֵ
		if (*(arr + m) == 0) { //mδ���ʣ������Ӧλ����1��������һ�γ��ֵ�λ��
			*(arr + m) = 1;
			p = p->next;
		}
		else { //m�ѷ��ʣ�ɾ��
			r = p->next;
			p->next = r->next;
			free(r);
		}	
	}

	free(arr); //�ͷŸ�������
}

LNode* FindLoopStart(LinkList L) { //���Ҵ��л�������Ļ���ڣ�˫ָ�뷨
	LNode* slow, * fast; //������ָ�룬ÿ��ѭ��slow��һ����fast������
	slow = fast = L;

	while (slow != NULL && fast->next != NULL) {
		slow = slow->next; 
		fast = fast->next->next;
		if (slow == fast) //��slow��fast���������л�
			break;
	}

	if (slow == NULL || fast->next == NULL) //��slow��fast���������򲻴��ڻ�
		return NULL;

	/*��ͷ��㵽����ڵľ���Ϊa����������뻷��ڵľ���Ϊx������Ϊr������ʱfast�Ѿ�����nȦ����
		2(a + x) = a + nr + x
	��a = nr - x��ͷ��㵽����ڵľ���a����n��������ȥx��
	������ָ��ֱ��ͷ��㡢��������ƣ����������㼴Ϊ�����*/
	LNode* p, * q; 
	p = L; q = slow;
	while (p != q) {
		p = p->next;
		q = q->next;
	}
	return p;
}

void RealignList(LinkList& L) { //������{a1, a2, ..., an}��������Ϊ{a1, an, a2, an-1, ...}��˫ָ��+ͷ�巨
	LNode* p, * q, * r, * s;
	p = q = L;

	while (q->next != NULL) { //Ѱ���м�ڵ�
		p = p->next; //p��һ����q������
		q = q->next->next; 
	}

	q = p->next; //p��ָ���Ϊ�м�ڵ㣬qΪ����������׽ڵ�

	p->next = NULL; //ͷ�巨���ú�������
	while (q != NULL) {
		r = q->next;
		q->next = p->next;
		p->next = q;
		q = r;
	}

	s = L->next; //sΪǰ���������׽ڵ�
	q = p->next; //qΪ����������׽ڵ�

	p->next = NULL; //�������������ǰ���ָ��λ��
	while (q != NULL) {
		r = q->next;
		q->next = s->next;
		s->next = q;
		s = q->next; 
		q = r;
	}
}