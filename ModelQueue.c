
typedef int DataType;

//��̬ջ

typedef struct Stack
{
	DataType* array;
	int capacity;
	int size;
}Stack;

//ջ�ĳ�ʼ��

void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (DataType*)malloc(sizeof(DataType) * 10);
	ps->capacity = 10;
	ps->size = 0;
}

//�ж�ջ�Ƿ��ã�������

void CheckCapacity(Stack* ps)
{
	if (ps->size >= ps->capacity)
	{
		//�����¿ռ�

		int newCapacity = ps->capacity * 2;
		DataType* temp = (DataType*)malloc(sizeof(DataType) * newCapacity);

		if (temp)
		{
			//����Ԫ��

			//memcpy(temp, ps->array, sizeof(DataType) * ps->capacity);


			for (int i = 0; i < ps->size; i++)
			{
				temp[i] = ps->array[i];
			}

			//�ͷžɿռ�

			free(ps->array);
			ps->array = temp;
			ps->capacity = newCapacity;
		}
	}
}


//��ջ

void StackPush(Stack* ps, DataType data)
{
	assert(ps);

	//�ж��Ƿ�ռ䲻����������

	CheckCapacity(ps);
	//����Ԫ��
	ps->array[ps->size] = data;
	ps->size++;
}

//�ж�ջ�Ƿ�Ϊ��

int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->size;
}

//��ջ

void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
	{
		return;
	}
	ps->size--;
}

//��ȡջ��Ԫ��

int StackTop(Stack* ps)
{
	assert(ps);
	return ps->array[ps->size - 1];
}

//��ȡջ����ЧԪ�صĸ���

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}

//����ջ

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->capacity = 0;
	ps->size = 0;
}


typedef struct {

	//����ģ�������--->��β

	Stack s1;

	//����ģ�������--->��ͷ

	Stack s2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&mq->s1);
	StackInit(&mq->s2);

	return mq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->s1, x);
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->s2))
	{
		//��s1�����Ԫ�ص��뵽s2��ȥ

		while (!StackEmpty(&obj->s1))
		{
			StackPush(&obj->s2, StackTop(&obj->s1));
			StackPop(&obj->s1);
		}
	}
	return StackTop(&obj->s2);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {

	int ret = myQueuePeek(obj);
	StackPop(&obj->s2);
	return ret;
}


/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	if (StackEmpty(&obj->s1) && StackEmpty(&obj->s2))
	{
		return true;
	}
	return false;
}

void myQueueFree(MyQueue* obj) {
	StackDestory(&obj->s1);
	StackDestory(&obj->s2);
	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/