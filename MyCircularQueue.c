typedef struct {
	int* array;    //存放元素空间
	int front;   //队头
	int rear;   //队尾
	int count;  //循环队列中有效元素个数
	int capacity;   //空间的总大小
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) 
{

	//申请结构体变量的空间

	MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));

	//初始化循环队列结构体变量中各个成员

	//存储元素底层空间

	mq->array = (int*)malloc(sizeof(int) * k);
	mq->front = mq->rear = mq->count = 0;
	mq->capacity = k;

	return mq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

	//队列满的情况

	if (obj->count == obj->capacity)
	{
		return false;
	}

	obj->array[obj->rear++] = value;

	//注意：rear当到达队尾的时候，应该在折回到队头

	if (obj->rear == obj->capacity)
	{
		obj->rear = 0;
	}
	obj->count++;

	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (obj->count == 0)
	{
		return false;
	}

	//非空

	obj->front++;
	if (obj->front == obj->capacity)
	{
		obj->front = 0;
	}
	obj->count--;

	return true;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->count == 0 ? true : false;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {

	//为空

	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->array[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {

	//注意rear的位置有可能在0号位置，rear-1<0
	//    rear不在0号位置，rear-1

	//为空

	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->array[(obj->rear - 1 + obj->capacity) % obj->capacity];
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return obj->count == obj->capacity ? true : false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->array);
	free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/