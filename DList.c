#include "DoubleList.h"

//#include <stdio.h>
//#include <assert.h>
//#include <malloc.h>
//
//typedef int DataType;
//
////双向链表节点的结构
//typedef struct DoubleListNode
//{
//	struct DoubleListNode* next;
//	struct DoubleListNode* prev;
//	DataType val;
//}DListNode;

//开辟空间

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

//创建节点

DListNode* CreatDlist(DListNode* head, int val)
{
	DListNode* head = BuyDLiatNode(val);
	head->next = head;
	head->prev - head;
	return head;
}

//尾插

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

//尾删

void DListPopBack(DListNode* head)
{
	//assert是一个调试宏，该宏只在debug模式下才存在
	//如果是release模式，assert宏就被删除了
	//所以下面的写法比较好

	//链表不存在

	if (NULL == head)
	{
		assert(0);
		return;
	}

	//检测是否为空链表

	if (head->next == head)
	{
		return;
	}

	//先连接后删除

	DListNode* pos = head->prev;
	head->prev = pos->prev;
	pos->prev->next = head;
	free(pos);
}