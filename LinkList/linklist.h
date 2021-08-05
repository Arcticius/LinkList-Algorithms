#pragma once

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode * next;
}LNode, *LinkList;

LinkList ListHeadInsert(LinkList& L);
LinkList ListTailInsert(LinkList& L);
void PrintList(LinkList L);
bool IsEmpty(LinkList L);
int Length(LinkList L);
LNode* GetLastNode(LinkList L);

void DeleteXRecursion(LinkList& L, ElemType x); //递归删除x
void DeleteX(LinkList& L, ElemType x); //非递归删除x，通用算法
void DeleteXTail(LinkList& L, ElemType x); //非递归删除x，尾插法
void PrintReversedList(LinkList& L); //输出逆置链表，递归法
void DeleteMin(LinkList& L); //删除最小值
void ReverseList(LinkList& L); //原地逆置链表，头插法
void ReverseListM(LinkList& L); //原地逆置链表，指针反转法
void SortAscending(LinkList& L); //递增排序
void DeleteRange(LinkList& L, ElemType min, ElemType max); //删除介于min和max的结点
LNode* SearchCommon(LinkList L1, LinkList L2); //寻找公共结点
void PrintSort(LinkList& L); //升序打印结点并依次删除结点
LinkList SplitOdevity(LinkList& L1); //将链表按照结点序号奇偶拆分
