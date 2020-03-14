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

//创建链表
//带头结点的链表

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

	//在不断开原链表的情况下将新节点连接到链表中

	newNode->prev = head->prev;
	newNode->next = head;

	//断开原链表

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

//头插

void DListPushFront(DListNode* head, int val)
{
	if (NULL == head)
	{
		return;
	}
	DListInsert(head->next, val);
}

//头删

void DListPopFront(DListNode* head)
{
	if (NULL == head)
	{
		return;
	}
	DListErase(head->next);;
}

//查找

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

//任意位置的插入
//插入在pos的前面

void DListInsert(DListNode* pos, int val)
{
	DListNode* newNode = BuyDLiatNode(val);

	//将新节点连接在链表上

	newNode->prev = pos->prev;
	newNode->next = pos;

	//断开链表

	newNode->prev->next = newNode;
	pos->prev = newNode;
}

//任意节点的删除

void DListErase(DListNode* pos)
{
	//判断节点是否存在

	if (NULL == pos)
	{
		return;
	}
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

//链表的摧毁

void DListDestroy(DListNode** head)
{
	//保证链表存在

	if (NULL == head)
	{
		return;
	}
	DListNode* cur = (*head)->next;

	//删除链表中的有效节点----头删

	while (cur != *head)
	{
		(*head)->next = cur->next;
		free(cur);
		cur = (*head)->next;
	}

	//删除头节点

	free(*head);
	*head = NULL;

}