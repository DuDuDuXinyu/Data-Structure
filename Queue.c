#include "Queue.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>


QNode* BuyQNode(int val)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));

	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}

	newNode->val = val;
	newNode->next = NULL;

	return newNode;
}

//初始化队列

void QueueInit(Queue* q)
{
	assert(q);

	q->head = BuyQNode(0);
	q->_size = 0;
	q->rear = q->head;
}

//入队列

void QueuePush(Queue* q, QDataType val)
{
	assert(q);

	QNode* newNode = BuyQNode(val);
	q->rear->next = newNode;
	q->rear = newNode;
	q->_size++;
}

//出队列

void QueuePop(Queue* q)
{
	QNode* pDelNode = NULL;
	if (QueueEmpty(q))
	{
		return;
	}

	QNode* pDelNode = NULL;
	pDelNode = q->head->next;
	q->head->next = pDelNode->next;

	if (NULL == q->head->next)
	{
		q->rear = q->head;
	}

	free(pDelNode);
	q->_size--;
}

//获取队列中有效元素的个数

int QueueSize(Queue* q)
{
	assert(q);
	return q->_size;
}

//检测队列是否为空

int QueueEmpty(Queue* q)
{
	assert(q);

	return 0 == q->_size;
}

//获取队头元素

QDataType QueueFront(Queue* q)
{
	assert(!QueueEmpty(q));

	return q->head->next->val;
}

//获取队尾元素

QDataType QueueBack(Queue* q)
{
	assert(!QueueEmpty(q));

	return q->rear->val;
}

//销毁队列

void QueueDestroy(Queue* q)
{
	//采用头删法将链表中的有效节点和头结点全部删除

	QNode* cur = NULL;
	while (cur)
	{
		q->head = cur->next;
		free(cur);
		cur = q->head;
	}

	q->head = NULL;
	q->head = NULL;
}