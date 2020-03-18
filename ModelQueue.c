
typedef int DataType;

//动态栈

typedef struct Stack
{
	DataType* array;
	int capacity;
	int size;
}Stack;

//栈的初始化

void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (DataType*)malloc(sizeof(DataType) * 10);
	ps->capacity = 10;
	ps->size = 0;
}

//判断栈是否够用，并扩容

void CheckCapacity(Stack* ps)
{
	if (ps->size >= ps->capacity)
	{
		//申请新空间

		int newCapacity = ps->capacity * 2;
		DataType* temp = (DataType*)malloc(sizeof(DataType) * newCapacity);

		if (temp)
		{
			//拷贝元素

			//memcpy(temp, ps->array, sizeof(DataType) * ps->capacity);


			for (int i = 0; i < ps->size; i++)
			{
				temp[i] = ps->array[i];
			}

			//释放旧空间

			free(ps->array);
			ps->array = temp;
			ps->capacity = newCapacity;
		}
	}
}


//入栈

void StackPush(Stack* ps, DataType data)
{
	assert(ps);

	//判断是否空间不够，并扩容

	CheckCapacity(ps);
	//插入元素
	ps->array[ps->size] = data;
	ps->size++;
}

//判断栈是否为空

int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->size;
}

//出栈

void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
	{
		return;
	}
	ps->size--;
}

//获取栈顶元素

int StackTop(Stack* ps)
{
	assert(ps);
	return ps->array[ps->size - 1];
}

//获取栈中有效元素的个数

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}

//销毁栈

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->capacity = 0;
	ps->size = 0;
}


typedef struct {

	//用来模拟入队列--->队尾

	Stack s1;

	//用来模拟出队列--->队头

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
		//将s1里面的元素导入到s2中去

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