#include "Heap.h"

//typedef int HPDataType;
//
//typedef struct Heap
//{
//	HPDataType* array;
//	int capacity;
//	int size;
//	PCOM Compare;
//}Heap;

int Less(int left, int right)
{
	return left < right;
}

int Greater(int left, int right)
{
	return left > right;
}

//typedef int (*PCOM)(int left, int right);


void Swap(HPDataType* left, HPDataType* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

//���Ѻ�ɾ��ʱ����Ҫ���µ���

void AdjustDown(Heap* hp, int parent)
{
	//child��ǵ���parent������

	int child = parent * 2 + 1;

	//ѭ����������֤���Ӵ��ڣ�������Ӳ����ڣ���parentû�к���

	while (child < hp->size)
	{
		//�ҳ����������н�С�ĺ���

		if (child + 1 < hp->size && hp->Compare(hp->array[child], hp->array[child + 1]))
		{
			child += 1;
		}

		//���parent�Ƿ�Ƚ�С�ĺ���childС

		if (hp->Compare(hp->array[child], hp->array[parent]))
		{
			Swap(&hp->array[child], &hp->array[parent]);

			//parent���Ԫ�������ƶ������ܻᵼ������������ѵ�����

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

//����ʱ�����ϵ���

void AdjustUp(Heap* hp,int child)
{
	//����Ч�ʱȳ��Զ���Ч�ʸ�

	int parent = (child - 1) >> 1;

	while (child)
	{
		if (hp->Compare(hp->array[child], hp->array[parent]))
		{
			Swap(&hp->array[child], &hp->array[parent]);

			//С��Ԫ�������ƶ������ܻᵼ���ϲ㲻����ѵ�����
			//��Ҫ�������ϵ���

			child = parent;
			parent = (child - 1) >> 1;
		}
		else
		{
			return;
		}
	}
}

//

void CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->size >= hp->capacity)
	{
		//��Ҫ����
		//����ռ�

		int newCapacity = hp->capacity * 2;
		HPDataType* temp = (HPDataType*)malloc(sizeof(HPDataType) * newCapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}

		//����Ԫ��

		for (int i = 0; i < hp->size; i++)
		{
			temp[i] = hp->array[i];
		}

		//memcpy(temp, hp->array, hp->size * sizeof(HPDataType);

		//�ͷžɿռ�

		free(hp->array);
		hp->array = temp;
		hp->capacity = newCapacity;
	}
}

void CreatHeap(Heap* hp, HPDataType arr[], int size, PCOM compare)
{
	assert(hp);

	//�Ƚ�arr�е�Ԫ�طŵ��ѵýṹ��
	//��ʼ���ѵĽṹ

	hp->array = (HPDataType*)mallco(sizeof(HPDataType) * size);
	if (NULL == hp -> array)
	{
		assert(0);
		return;
	}
	hp->capacity = size;
	memcpy(hp->array, arr, sizeof(HPDataType) * size);
	hp->size = size;
	hp->Compare = compare;

	//�Զ��е�Ԫ�ؽ��е���

	for (int root = (size - 2) >> 1; root >= 0; root--)
	{
		AdjustDown(hp, root);
	}
}

void HeapPush(Heap* hp, HPDataType data)
{
	assert(hp);
	CheckCapacity(hp);
	hp->array[hp->size++] = data; 
	AdjustUp(hp, hp->size - 1);
}

void HeapPop(Heap* hp)
{
	assert(hp);
	if (HeapEmpty(hp))
	{
		return;
	}

	//���ѵ����һ��Ԫ�غ͵�һ��Ԫ�ػ���λ��

	Swap(&hp->array[0], &hp->array[hp->size - 1]);
	hp->size--;

	//����ֻ�е�һλԪ�ز�����ѵ�Ҫ��
	//ֻ��Ҫ����һλԪ���������򼴿�

	AdjustDown(hp, 0);
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->size;
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp && !HeapEmpty(hp));
	return hp->array[0];
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

void HeapDestroy(Heap* hp)
{
	assert(hp);
	if (hp->array)
	{
		free(hp->array);
		hp->array = NULL;
		hp->capacity = 0;
		hp->size = 0;
	}
}