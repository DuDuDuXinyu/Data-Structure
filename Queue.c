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

//��ʼ������

void QueueInit(Queue* q)
{
	assert(q);

	q->head = BuyQNode(0);
	q->_size = 0;
	q->rear = q->head;
}

//�����

void QueuePush(Queue* q, QDataType val)
{
	assert(q);

	QNode* newNode = BuyQNode(val);
	q->rear->next = newNode;
	q->rear = newNode;
	q->_size++;
}

//������

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

//��ȡ��������ЧԪ�صĸ���

int QueueSize(Queue* q)
{
	assert(q);
	return q->_size;
}

//�������Ƿ�Ϊ��

int QueueEmpty(Queue* q)
{
	assert(q);

	return 0 == q->_size;
}

//��ȡ��ͷԪ��

QDataType QueueFront(Queue* q)
{
	assert(!QueueEmpty(q));

	return q->head->next->val;
}

//��ȡ��βԪ��

QDataType QueueBack(Queue* q)
{
	assert(!QueueEmpty(q));

	return q->rear->val;
}

//���ٶ���

void QueueDestroy(Queue* q)
{
	//����ͷɾ���������е���Ч�ڵ��ͷ���ȫ��ɾ��

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