typedef int QDataType;

//���еײ�ʹ�������нڵ�Ľṹ

typedef struct QNode
{
	struct QNode* next;
	QDataType val;
}QNode;

typedef struct Queue
{
	struct QNode* head;
	struct QNode* rear;
	int _size;//��¼��������ЧԪ�صĸ���
}Queue;

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

//�������Ƿ�Ϊ��

int QueueEmpty(Queue* q)
{
	assert(q);

	return 0 == q->_size;
}

//������

void QueuePop(Queue* q)
{
	QNode* pDelNode = NULL;
	if (QueueEmpty(q))
	{
		return;
	}

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

//�ݻٶ���

void QueueDestroy(Queue* q)
{
	//����ͷɾ���������е���Ч�ڵ��ͷ���ȫ��ɾ��

	QNode* cur = q->head;
	while (cur)
	{
		q->head = cur->next;
		free(cur);
		cur = q->head;
	}

	q->head = NULL;
	q->rear = NULL;
}




typedef struct {
	Queue q1;
	Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&ms->q1);
	QueueInit(&ms->q2);
	return ms;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (NULL == obj)
	{
		return;
	}
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int ret = 0;
	if (!QueueEmpty(&obj->q1))
	{
		//��q1�е�n-1��Ԫ�ذ��Ƶ�q2

		while (QueueSize(&obj->q1) > 1)
		{
			QueuePush(&obj->q2, QueueFront(&obj->q1));
			QueuePop(&obj->q1);
		}

		//ȡ����ջ��Ԫ��

		ret = QueueFront(&obj->q1);
		QueuePop(&obj->q1);
	}
	else
	{
		//��q2�е�n-1��Ԫ�ذ��Ƶ�q1

		while (QueueSize(&obj->q2) > 1)
		{
			QueuePush(&obj->q1, QueueFront(&obj->q2));
			QueuePop(&obj->q2);
		}

		//ȡ����ջ��Ԫ��

		ret = QueueFront(&obj->q2);
		QueuePop(&obj->q2);
	}
	return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	if (QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2))
	{
		return true;
	}
	return false;
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/