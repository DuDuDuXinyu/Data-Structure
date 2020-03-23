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

//建堆和删除时，需要向下调整

void AdjustDown(Heap* hp, int parent)
{
	//child标记的是parent的左孩子

	int child = parent * 2 + 1;

	//循环条件：保证左孩子存在，如果左孩子不存在，则parent没有孩子

	while (child < hp->size)
	{
		//找出俩个孩子中较小的孩子

		if (child + 1 < hp->size && hp->Compare(hp->array[child], hp->array[child + 1]))
		{
			child += 1;
		}

		//检测parent是否比较小的孩子child小

		if (hp->Compare(hp->array[child], hp->array[parent]))
		{
			Swap(&hp->array[child], &hp->array[parent]);

			//parent大的元素往下移动，可能会导致子树不满足堆得性质

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

//插入时，向上调整

void AdjustUp(Heap* hp,int child)
{
	//右移效率比乘以二的效率高

	int parent = (child - 1) >> 1;

	while (child)
	{
		if (hp->Compare(hp->array[child], hp->array[parent]))
		{
			Swap(&hp->array[child], &hp->array[parent]);

			//小的元素往上移动，可能会导致上层不满足堆得性质
			//需要继续向上调整

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
		//需要扩容
		//申请空间

		int newCapacity = hp->capacity * 2;
		HPDataType* temp = (HPDataType*)malloc(sizeof(HPDataType) * newCapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}

		//拷贝元素

		for (int i = 0; i < hp->size; i++)
		{
			temp[i] = hp->array[i];
		}

		//memcpy(temp, hp->array, hp->size * sizeof(HPDataType);

		//释放旧空间

		free(hp->array);
		hp->array = temp;
		hp->capacity = newCapacity;
	}
}

void CreatHeap(Heap* hp, HPDataType arr[], int size, PCOM compare)
{
	assert(hp);

	//先将arr中的元素放到堆得结构中
	//初始化堆的结构

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

	//对堆中的元素进行调整

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

	//将堆得最后一个元素和第一个元素互换位置

	Swap(&hp->array[0], &hp->array[hp->size - 1]);
	hp->size--;

	//发现只有第一位元素不满足堆的要求
	//只需要将第一位元素重新排序即可

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