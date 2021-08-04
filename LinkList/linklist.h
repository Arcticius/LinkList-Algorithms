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

void DeleteXRecursion(LinkList& L, ElemType x); //�ݹ�ɾ��x
void DeleteX(LinkList& L, ElemType x); //�ǵݹ�ɾ��x��ͨ���㷨
void DeleteXTail(LinkList& L, ElemType x); //�ǵݹ�ɾ��x��β�巨
void PrintReversedList(LinkList& L); //������������ݹ鷨
void DeleteMin(LinkList& L); //ɾ����Сֵ
void ReverseList(LinkList& L); //ԭ����������ͷ�巨
void ReverseListM(LinkList& L); //ԭ����������ָ�뷴ת����