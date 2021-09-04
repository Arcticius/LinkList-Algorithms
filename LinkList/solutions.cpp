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

LinkList SplitOdevityReversed(LinkList& L1) { //将链表按照结点序号奇偶拆分，拆分出的链表需是逆序
	LinkList L2 = (LinkList)malloc(sizeof(LNode)); //创建新链表L2
	L2->next = NULL;

	LNode* rear1 = L1; //rear1始终指向L1表尾
	LNode* p = L1->next, * q = NULL; //q为p的后继

	while (p != NULL) {
		rear1->next = p; rear1 = p;//p此处为L1结点，将p链到L1表尾
		p = p->next; //p此处为L2结点
		if (p != NULL)
			q = p->next; //记录p的后继，防止断链
		p->next = L2->next; L2->next = p; //头插法将p插入链表L2
		p = q; //p此处为L1结点
	}

	rear1->next = NULL;

	return L2;
}

void DeleteSameNode(LinkList& L) {  //删除递增链表的相等结点
	LNode* p, * q; //p指针遍历链表，q为p的后继

	p = L->next;

	if (p == NULL) //空表
		return;
	while (p != NULL) {
		q = p->next;

		if (q != NULL && p->data == q->data) { //p和后继相同，删除q，直到后继与p不同为止
			p->next = q->next;
			free(q);
		}
		else //p和后继不相同，继续遍历
			p = p->next;
			
	}
}

void MergeList(LinkList& L1, LinkList& L2) { //原地合并两递增链表，合并后的链表应为递减
	LNode* p1, * p2, * r; 
	p1 = L1->next; p2 = L2->next;

	L1->next = NULL; //规定合并后仅剩L1，因结果为递减，采用头插法
	while (p1 && p2) { //p1、p2均非空时
		if (p1->data <= p2->data) { //p1较小
			r = p1->next; //记录p1后继，防止断链
			p1->next = L1->next; L1->next = p1; //将p1头插至L1
			p1 = r;
		}
		else { //p2较小
			r = p2->next; //记录p2后继，防止断链
			p2->next = L1->next; L1->next = p2; //将p2头插至L1
			p2 = r;
		}
	}

	p2 = p1 != NULL ? p1 : p2; //若L1较长，则p2已空，将L1剩余结点赋给p2

	while (p2) { //将剩余结点依次头插至L1
		r = p2->next;
		p2->next = L1->next; L1->next = p2;
		p2 = r;
	}

	free(L2); //释放L2头结点
}

LinkList SearchSameNodes(LinkList& L1, LinkList& L2) { //寻找两递增链表的相等结点，构造新链表
	LinkList L3 = (LinkList)malloc(sizeof(LNode)); //相等结点构成的新链表
	LNode* p1, * p2, * p3, *same;
	p1 = L1->next; p2 = L2->next; p3 = L3;
	
	while (p1 != NULL && p2 != NULL) {
		if (p1->data < p2->data) //p1较小，后移
			p1 = p1->next;
		else if (p2->data < p1->data) //p2较小，后移
			p2 = p2->next;
		else { //p1、p2相等，找到相等结点，尾插入L3
			same = (LNode*)malloc(sizeof(LNode));
			same->data = p1->data;
			p3->next = same; p3 = same; //尾插
			p1 = p1->next; p2 = p2->next; //同时后移
		}
	}

	p3->next = NULL;
	return L3;
}

void Union(LinkList& L1, LinkList& L2) { //寻找两递增链表的交集，存入L1中
	LNode* p1, * p2, * p, * temp;
	p1 = L1->next; p2 = L2->next;
	p = L1;

	while (p1 && p2) { //p1、p2均非空时 
		if (p1->data < p2->data) { //p1较小，后移
			temp = p1;
			p1 = p1->next;
			free(temp);
		}
		else if (p2->data < p1->data) { //p1较小，后移
			temp = p2;
			p2 = p2->next;
			free(temp);
		}
		else { //p1、p2相等，找到交集元素，尾插入L1
			p->next = p1; p = p1; //尾插

			p1 = p1->next;

			temp = p2; //释放L2结点
			p2 = p2->next;
			free(temp);
		}
	}

	while (p1) { //L1还有剩余结点
		temp = p1;
		p1 = p1->next;
		free(temp);
	} 
	while (p2) { //L2还有剩余结点
		temp = p2;
		p2 = p2->next;
		free(temp);
	}

	p->next = NULL;
	free(L2); //释放L2头结点
}

bool IsPattern(LinkList L1, LinkList L2) { //判断L2是否为L1的连续子序列
	LNode* p1, * p2, * start; //start记录L1每次遍历的起始位置
	p1 = L1->next; p2 = L2->next; start = p1;

	while (p1 && p2) {
		if (p1->data == p2->data) { //对应相同
			p1 = p1->next;
			p2 = p2->next;
		} 
		else { //对应不相同，p1回退到起始位置的后继，p2回退到起始位置
			start = start->next;
			p1 = start;
			p2 = L2->next;
		}
	}

	if (p2 == NULL) //L2已全部遍历，说明L2是子序列
		return true;
	else 
		return false;
}

bool IsSymmetrical(DLinkList& L) { //判断循环双链表是否对称
	DNode* p, * q; //两指针分别从前后遍历
	p = L->next; q = L->prior;

	while (p != q && q->next != p) { //循环终止条件：奇数时p、q指向同一节点；偶数时p、q相邻
		if (p->data == q->data) {
			p = p->next;
			q = q->prior;
		}
		else
			return false;
	}

	return true;
}

void LinkCircularLists(LinkList& L1, LinkList& L2) { //将循环链表L2链接到循环链表L1之后
	LNode* last1, * last2;

	last1 = L1; last2 = L2;
	while (last1->next != L1) //找出两链表的尾结点
		last1 = last1->next;
	while (last2->next != L2)
		last2 = last2->next;

	last1->next = L2->next;
	last2->next = L1;
}

void DeleteAllMins(LinkList& L) { //依次输出并删除循环链表的最小值
	LNode* p, * pre, * min, * minpre;
	while (L->next != L) { //循环链表非空判定
		p = L->next, pre = L;
		min = p, minpre = pre;
		while (p != L) { //遍历依次链表，寻找最小值
			if (p->data < min->data) {
				min = p; minpre = pre;
			}
			p = p->next; pre = pre->next;
		}

		printf("%d ", min->data); //输出此次循环的最小值
		minpre->next = min->next; //删除该结点
		free(min);
	}
	free(L); //释放头结点
}

DFNode* Locate(DFLinkList& L, ElemType x) { //查找x，成功时将频度增1，并将结点按频度降序排列
	DFNode* p, * pre; //pre为p的前驱

	p = L->next;
	while (p != NULL && p->data != x) //遍历链表，寻找x
		p = p->next;

	if (p == NULL) //未找到x
		return NULL;
	else { //找到x，更新频度并重新排列
		p->freq++; //更新频度

		if (p->next != NULL) //摘下p结点
			p->next->prior = p->prior;
		p->prior->next = p->next;

		pre = p->prior;
		while (pre != L && pre->freq <= p->freq) //寻找插入位置
			pre = pre->prior;
		
		p->next = pre->next; p->prior = pre; //插入p结点
		pre->next->prior = p; pre->next = p;
	}

	return p;
}

bool SearchLastK(LinkList L, ElemType k) { //查找倒数第k个元素，尽可能高效，双指针法
	LNode* p, * q; //双指针
	p = q = L->next; //初始时均指向第一个节点
	int count = 0; //计数器

	while (p != NULL) { //采用双指针法，仅需遍历一次链表
		if (count < k) //若count<k，则仅移动p
			count++;
		else //count=k时，q开始后移，则p遍历完时，q恰好位于倒数第k个元素上
			q = q->next;

		p = p->next;
	}

	if (count < k) //不存在倒数第k个元素
		return false;
	else {
		printf("%d \n", q->data);
		return true;
	}
}

void DeleteAllSameNode(LinkList& L, ElemType n) { //删除乱序链表的相等（含绝对值）结点，辅助数组法
	//链表元素的值不超过n
	LNode* p, * r;
	p = L;

	ElemType* arr, m; //辅助数组
	arr = (ElemType*)malloc(sizeof(ElemType) * (n + 1)); //申请n+1个位置作为辅助数组，采用下标法

	for (int i = 0; i < n + 1; i++) //初始化数组元素为0，表示未访问
		*(arr + i) = 0;

	while (p->next != NULL) { //遍历一次链表
		m = p->next->data > 0 ? p->next->data : -p->next->data; //取绝对值
		if (*(arr + m) == 0) { //m未访问，数组对应位置置1，保留第一次出现的位置
			*(arr + m) = 1;
			p = p->next;
		}
		else { //m已访问，删除
			r = p->next;
			p->next = r->next;
			free(r);
		}	
	}

	free(arr); //释放辅助数组
}

LNode* FindLoopStart(LinkList L) { //查找带有环的链表的环入口，双指针法
	LNode* slow, * fast; //设置两指针，每次循环slow走一步，fast走两步
	slow = fast = L;

	while (slow != NULL && fast->next != NULL) {
		slow = slow->next; 
		fast = fast->next->next;
		if (slow == fast) //若slow与fast相遇，则有环
			break;
	}

	if (slow == NULL || fast->next == NULL) //若slow与fast不相遇，则不存在环
		return NULL;

	/*设头结点到环入口的距离为a，相遇点距离环入口的距离为x，环长为r，相遇时fast已经绕了n圈，则
		2(a + x) = a + nr + x
	即a = nr - x，头结点到环入口的距离a等于n倍环长减去x。
	设置两指针分别从头结点、相遇点后移，则再相遇点即为环入口*/
	LNode* p, * q; 
	p = L; q = slow;
	while (p != q) {
		p = p->next;
		q = q->next;
	}
	return p;
}

void RealignList(LinkList& L) { //将链表{a1, a2, ..., an}重新排列为{a1, an, a2, an-1, ...}，双指针+头插法
	LNode* p, * q, * r, * s;
	p = q = L;

	while (q->next != NULL) { //寻找中间节点
		p = p->next; //p走一步，q走两步
		q = q->next->next; 
	}

	q = p->next; //p所指结点为中间节点，q为后半段链表的首节点

	p->next = NULL; //头插法逆置后半段链表
	while (q != NULL) {
		r = q->next;
		q->next = p->next;
		p->next = q;
		q = r;
	}

	s = L->next; //s为前半段链表的首节点
	q = p->next; //q为后半段链表的首节点

	p->next = NULL; //将后半段链表插至前半段指定位置
	while (q != NULL) {
		r = q->next;
		q->next = s->next;
		s->next = q;
		s = q->next; 
		q = r;
	}
}