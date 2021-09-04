#pragma once

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode * next;
}LNode, * LinkList; //������

typedef struct DNode {
	ElemType data;
	struct DNode* prior, * next;
}DNode, * DLinkList; //˫����

typedef struct DFNode {
	ElemType data;
	int freq;
	struct DFNode* prior, * next;
}DFNode, * DFLinkList; //������Ƶ�ȵ�˫����

/*��������*/
LinkList ListHeadInsert(LinkList& L);
LinkList ListTailInsert(LinkList& L);
void PrintList(LinkList L);
bool IsEmpty(LinkList L);
int Length(LinkList L);
LNode* GetLastNode(LinkList L);
LNode* LocateX(LinkList L, ElemType x);

DLinkList ListTailInsert(DLinkList& L);
void PrintList(DLinkList L);
DNode* GetLastNode(DLinkList L);

DFLinkList ListTailInsert(DFLinkList& L);
void PrintList(DFLinkList L);

void Circularize(LinkList& L);
void Circularize(DLinkList& L);

void PrintCircularList(LinkList L);
void PrintCircularList(DLinkList L);

/*����*/
void DeleteXRecursion(LinkList& L, ElemType x); //�ݹ�ɾ��x
void DeleteX(LinkList& L, ElemType x); //�ǵݹ�ɾ��x��ͨ���㷨
void DeleteXTail(LinkList& L, ElemType x); //�ǵݹ�ɾ��x��β�巨
void PrintReversedList(LinkList& L); //������������ݹ鷨
void DeleteMin(LinkList& L); //ɾ����Сֵ
void ReverseList(LinkList& L); //ԭ����������ͷ�巨
void ReverseListM(LinkList& L); //ԭ����������ָ�뷴ת��
void SortAscending(LinkList& L); //��������
void DeleteRange(LinkList& L, ElemType min, ElemType max); //ɾ������min��max�Ľ��
LNode* SearchCommon(LinkList L1, LinkList L2); //Ѱ�ҹ������
void PrintSort(LinkList& L); //�����ӡ��㲢����ɾ�����
LinkList SplitOdevity(LinkList& L1); //�������ս�������ż���
LinkList SplitOdevityReversed(LinkList& L1); //�������ս�������ż��֣���ֳ���������������
void DeleteSameNode(LinkList& L); //ɾ�������������Ƚ��
void MergeList(LinkList& L1, LinkList& L2); //ԭ�غϲ������������ϲ��������ӦΪ�ݼ�
LinkList SearchSameNodes(LinkList& L1, LinkList& L2); //Ѱ���������������Ƚ�㣬����������
void Union(LinkList& L1, LinkList& L2); //Ѱ������������Ľ���������L1��
bool IsPattern(LinkList L1, LinkList L2); //�ж�L2�Ƿ�ΪL1�����������У�BF�㷨
bool IsSymmetrical(DLinkList& L); //�ж�ѭ��˫�����Ƿ�Գ�
void LinkCircularLists(LinkList& L1, LinkList& L2); //��ѭ������L2���ӵ�ѭ������L1֮��
void DeleteAllMins(LinkList& L); //���������ɾ��ѭ���������Сֵ
DFNode* Locate(DFLinkList& L, ElemType x); //����x���ɹ�ʱ��Ƶ����1��������㰴Ƶ�Ƚ�������

/*������*/
bool SearchLastK(LinkList L, ElemType k); //���ҵ�����k��Ԫ�أ������ܸ�Ч��˫ָ�뷨
//LNode* SearchCommon(LinkList L1, LinkList L2); //Ѱ�ҹ������
void DeleteAllSameNode(LinkList& L, ElemType n); //ɾ�������������ȣ�������ֵ����㣬�������鷨
LNode* FindLoopStart(LinkList L); //���Ҵ��л�������Ļ���ڣ�˫ָ�뷨
void RealignList(LinkList& L); //������{a1, a2, ..., an}��������Ϊ{a1, an, a2, an-1, ...}��˫ָ��+ͷ�巨