typedef int QDataType;

//队列底层使用链表中节点的结构

typedef struct QNode
{
	struct QNode* next;
	QDataType val;
}QNode;

typedef struct Queue
{
	struct QNode* head;
	struct QNode* rear;
	int _size;//记录队列中有效元素的个数
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

//检测队列是否为空

int QueueEmpty(Queue* q)
{
	assert(q);

	return 0 == q->_size;
}

//出队列

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

//获取队列中有效元素的个数

int QueueSize(Queue* q)
{
	assert(q);
	return q->_size;
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

//摧毁队列

void QueueDestroy(Queue* q)
{
	//采用头删法将链表中的有效节点和头结点全部删除

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
		//将q1中的n-1个元素搬移到q2

		while (QueueSize(&obj->q1) > 1)
		{
			QueuePush(&obj->q2, QueueFront(&obj->q1));
			QueuePop(&obj->q1);
		}

		//取出出栈的元素

		ret = QueueFront(&obj->q1);
		QueuePop(&obj->q1);
	}
	else
	{
		//将q2中的n-1个元素搬移到q1

		while (QueueSize(&obj->q2) > 1)
		{
			QueuePush(&obj->q1, QueueFront(&obj->q2));
			QueuePop(&obj->q2);
		}

		//取出出栈的元素

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