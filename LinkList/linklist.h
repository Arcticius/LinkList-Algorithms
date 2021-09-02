#pragma once

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode * next;
}LNode, * LinkList; //单链表

typedef struct DNode {
	ElemType data;
	struct DNode* prior, * next;
}DNode, * DLinkList; //双链表

typedef struct DFNode {
	ElemType data;
	int freq;
	struct DFNode* prior, * next;
}DFNode, * DFLinkList; //带访问频度的双链表

LinkList ListHeadInsert(LinkList& L);
LinkList ListTailInsert(LinkList& L);
void PrintList(LinkList L);
bool IsEmpty(LinkList L);
int Length(LinkList L);
LNode* GetLastNode(LinkList L);

DLinkList ListTailInsert(DLinkList& L);
void PrintList(DLinkList L);
DNode* GetLastNode(DLinkList L);

DFLinkList ListTailInsert(DFLinkList& L);
void PrintList(DFLinkList L);

void Circularize(LinkList& L);
void Circularize(DLinkList& L);

void PrintCircularList(LinkList L);
void PrintCircularList(DLinkList L);

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
LinkList SplitOdevityReversed(LinkList& L1); //将链表按照结点序号奇偶拆分，拆分出的链表需是逆序
void DeleteSameNode(LinkList& L); //删除递增链表的相等结点
void MergeList(LinkList& L1, LinkList& L2); //原地合并两递增链表，合并后的链表应为递减
LinkList SearchSameNodes(LinkList& L1, LinkList& L2); //寻找两递增链表的相等结点，构造新链表
void Union(LinkList& L1, LinkList& L2); //寻找两递增链表的交集，存入L1中
bool IsPattern(LinkList L1, LinkList L2); //判断L2是否为L1的连续子序列
bool IsSymmetrical(DLinkList& L); //判断循环双链表是否对称
void LinkCircularLists(LinkList& L1, LinkList& L2); //将循环链表L2链接到循环链表L1之后
void DeleteAllMins(LinkList& L); //依次输出并删除循环链表的最小值
DFNode* Locate(DFLinkList& L, ElemType x); //查找x，成功时将频度增1，并将结点按频度降序排列