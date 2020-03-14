#include "DoubleList.h"

//#include <stdio.h>
//#include <assert.h>
//#include <malloc.h>
//
//typedef int DataType;
//
////˫������ڵ�Ľṹ
//typedef struct DoubleListNode
//{
//	struct DoubleListNode* next;
//	struct DoubleListNode* prev;
//	DataType val;
//}DListNode;

//���ٿռ�

DListNode* BuyDLiatNode(int val)
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}

	newNode->val = val;
	newNode->next = NULL;
	newNode->prev = NULL;
}

//��������
//��ͷ��������

DListNode* CreatDlist(DListNode* head, int val)
{
	DListNode* head = BuyDLiatNode(val);
	head->next = head;
	head->prev - head;

	return head;
}

//β��

void DListPushBack(DListNode* head, int val)
{
	if (NULL == head)
	{
		return;
	}
	DListNode* newNode = BuyDLiatNode(val);

	//�ڲ��Ͽ�ԭ���������½��½ڵ����ӵ�������

	newNode->prev = head->prev;
	newNode->next = head;

	//�Ͽ�ԭ����

	newNode->prev->next = newNode;
	head->prev = newNode;
}

//βɾ

void DListPopBack(DListNode* head)
{
	//assert��һ�����Ժ꣬�ú�ֻ��debugģʽ�²Ŵ���
	//�����releaseģʽ��assert��ͱ�ɾ����
	//���������д���ȽϺ�

	//��������

	if (NULL == head)
	{
		assert(0);
		return;
	}

	//����Ƿ�Ϊ������

	if (head->next == head)
	{
		return;
	}

	//�����Ӻ�ɾ��

	DListNode* pos = head->prev;
	head->prev = pos->prev;
	pos->prev->next = head;
	free(pos);
}

//ͷ��

void DListPushFront(DListNode* head, int val)
{
	if (NULL == head)
	{
		return;
	}
	DListInsert(head->next, val);
}

//ͷɾ

void DListPopFront(DListNode* head)
{
	if (NULL == head)
	{
		return;
	}
	DListErase(head->next);;
}

//����

DListNode* DListFind(DListNode* head, int val)
{

	DListNode* cur = head->next;
	while (cur)
	{
		if (cur->val == val)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//����λ�õĲ���
//������pos��ǰ��

void DListInsert(DListNode* pos, int val)
{
	DListNode* newNode = BuyDLiatNode(val);

	//���½ڵ�������������

	newNode->prev = pos->prev;
	newNode->next = pos;

	//�Ͽ�����

	newNode->prev->next = newNode;
	pos->prev = newNode;
}

//����ڵ��ɾ��

void DListErase(DListNode* pos)
{
	//�жϽڵ��Ƿ����

	if (NULL == pos)
	{
		return;
	}
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

//����Ĵݻ�

void DListDestroy(DListNode** head)
{
	//��֤�������

	if (NULL == head)
	{
		return;
	}
	DListNode* cur = (*head)->next;

	//ɾ�������е���Ч�ڵ�----ͷɾ

	while (cur != *head)
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	}

	//ɾ��ͷ�ڵ�

	free(*head);
	*head = NULL;

}