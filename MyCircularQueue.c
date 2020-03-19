typedef struct {
	int* array;    //���Ԫ�ؿռ�
	int front;   //��ͷ
	int rear;   //��β
	int count;  //ѭ����������ЧԪ�ظ���
	int capacity;   //�ռ���ܴ�С
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) 
{

	//����ṹ������Ŀռ�

	MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));

	//��ʼ��ѭ�����нṹ������и�����Ա

	//�洢Ԫ�صײ�ռ�

	mq->array = (int*)malloc(sizeof(int) * k);
	mq->front = mq->rear = mq->count = 0;
	mq->capacity = k;

	return mq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

	//�����������

	if (obj->count == obj->capacity)
	{
		return false;
	}

	obj->array[obj->rear++] = value;

	//ע�⣺rear�������β��ʱ��Ӧ�����ۻص���ͷ

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

	//�ǿ�

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

	//Ϊ��

	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->array[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {

	//ע��rear��λ���п�����0��λ�ã�rear-1<0
	//    rear����0��λ�ã�rear-1

	//Ϊ��

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