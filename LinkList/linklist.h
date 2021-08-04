#pragma once

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode * next;
}LNode, *LinkList;

LinkList ListHeadInsert(LinkList& L);
LinkList ListTailInsert(LinkList& L);
void PrintList(LinkList L);

void DeleteXRecursion(LinkList& L, ElemType x); //µİ¹éÉ¾³ıx
void DeleteX(LinkList& L, ElemType x); //·Çµİ¹éÉ¾³ıx£¬Í¨ÓÃËã·¨
void DeleteXTail(LinkList& L, ElemType x); //·Çµİ¹éÉ¾³ıx£¬Î²²å·¨