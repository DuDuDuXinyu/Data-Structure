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

//�����ڵ�

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

	newNode->prev = head->prev;
	newNode->next = head;
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