#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

//打印数组

void PrintArray(int* arr, int len)
{
	int i = 0;
	while (i < len)
		printf("%d ", arr[i]);
	printf("\n");
}

//交换

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//冒泡排序

void bubble_sort(int* arr,int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int j = 0;
		for (; j < len - 1 - i; j++)
		{
			//倒叙

			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//插入排序

void insertion_sort(int* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && temp < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		if (j != i - 1)
		{
			arr[j + 1] = temp;
		}
	}
}

//插入排序

void InSertSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int key = arr[i];
		int end = i - 1;

		//找待插入数据位置

		while (end >= 0 && arr[end] > key)
		{
			arr[end + 1] = arr[end];
			end--;
		}

		//插入数据

		arr[end + 1] = key;
	}
}

//希尔排序

void ShellSort(int* arr, int size)
{
	int gap = 3;
	while (gap >= 1)
	{
		for (int i = gap; i < size; i++)
		{
			int key = arr[i];
			int end = i - gap;

			//找待插入数据位置

			while (end >= 0 && arr[end] > key)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}

			//插入数据

			arr[end + gap] = key;
		}
		gap--;
	}
}

//快速排序

void fast_sort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int i = left;
	int j = right;
	int temp = arr[left];

	while (i < j)
	{
		while (i < j && temp <= arr[j])
		{
			j--;
		}
		arr[i] = arr[j];
		while (i<j && temp>=arr[i])
		{
			i++;
		}
		arr[j] = arr[i];
	}
	arr[i] = temp;
	fast_sort(arr, left, i - 1);
	fast_sort(arr, i + 1, right);
}

//选择排序--不稳定

void SelectSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		//i来控制循环次数

		int maxpos = 0;
		for (int j = 1; j < size - 1; j++)
		{
			//控制遍历的末位置

			if (arr[j] > arr[maxpos])
				maxpos = j;
		}

		if (maxpos != size - 1 - i)
			Swap(&arr[maxpos], &arr[size - 1 - i]);
	}
}

//选择排序的优化

void SelectSorOP(int* arr, int size)
{
	int begin = 0, end = size - 1;
	while (begin < end)
	{
		int minpos = begin;
		int maxpos = begin;
		int index = begin + 1;
		while (index <= end)
		{
			if (arr[index] < arr[minpos])
				minpos = index;
			if (arr[index] > arr[maxpos])
				maxpos = index;

			index++;
		}

		//注意：最右侧位置有可能存储的是最小值

		if (maxpos != end)
			Swap(&arr[maxpos], &arr[end]);

		//如果最右侧存储的刚好是最小值，经过上述交换之后，最小值的位置已经改变
		//必须更新minpos的值

		if (minpos == end)
			minpos = maxpos;
		if (minpos != begin)
			Swap(&arr[minpos], &arr[begin]);

		begin++;
		end--;
	}
}

//堆排序

void HeapADjust(int* array, int size, int parent)
{
	//优先标记左孩子->因为堆实际是完全二叉树
	//完全二叉树中可能只有左孩子没有右孩子

	int child = parent * 2 + 1;

	while (child < size)
	{
		//找到最大的孩子

		if (child + 1 && array[child + 1] > array[child])
			child += 1;

		//检测双亲是否比较大的孩子还大

		if (array[child] > array[parent])
		{
			Swap(&array[parent], &array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;	
	}
}

void HeapSort(int* array, int size)
{
	//建堆
	//找到倒数第一个非叶子节点

	for (int root = (size - 2) >> 1; root >= 0; root--)
	{
		//向下调整

		HeapADjust(array, size, root);
	}

	//利用堆的思想来进行排序

	int end = size - 1;
	while (end)
	{
		Swap(&array[0], &array[end]);
		HeapADjust(array, end, 0);
		end--;
	}
}

//冒泡排序

void BubbleSort(int* array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int isChange = 0;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
				isChange = 1;
			}
		}

		//没有交换说明已经有序，所以无需继续遍历

		if (!isChange)
			return;
	}
}

//快排

//三个数取值为中间的数字

int GetIndexMid(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);

	if (array[left] < array[right - 1])
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid] > array[right - 1])
			return right - 1;
		else
			return mid;
	}
}

//交换法

int Partion1(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int mid = GetIndexMid(array, left, right);

	//找一个基准值，把数据分为俩部分

	Swap(&array[mid], &array[right - 1]);
	int key = array[end];
	
	while (begin < end)
	{
		//让begin从前往后找，比key大的元素

		while (begin < end && array[begin] <= key)
			begin++;

		//让end从后往前找，比key小的元素

		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
		{
			Swap(&array[begin], &array[end]);
		}
	}

	if (begin != right - 1)
		Swap(&array[begin], &array[right - 1]);
	return begin;
}

//挖坑法

int Partion2(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int mid = GetIndexMid(array, left, right);

	//找一个基准值，把数据分为俩部分

	Swap(&array[mid], &array[right - 1]);
	int key = array[end];

	while (begin < end)
	{
		//让begin从前往后找比基准值大的元素

		while (begin < end && array[begin] <= key)
			begin++;

		//让begin位置的元素填end位置的坑

		if (begin < end)
			array[end--] = array[begin];

		//现在begin位置形成一个新的坑
		//让end从后往前找比基准值小的元素

		while (begin < end && array[end] >= key)
			end--;

		//end找到了一个比基准值小的元素
		//让end位置的元素填begin位置的坑

		if (begin < end)
			array[begin++] = array[end];
	}

	//用基准值填最后的坑

	arary[begin] = key;
	return begin;
}

//前后指针法

int Partion3(int* array, int left, int right)
{
	int cur = left;
	int prev = left - 1;
	int mid = GetIndexMid(array, left, right);

	//找一个基准值，把数据分为俩部分

	Swap(&array[mid], &array[right - 1]);
	int key = array[right-1];

	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur)
			Swap(&array[cur], &array[prev]);

		cur++;
	}
	if (++prev != right - 1)
		Swap(&array[prev], &array[right - 1]);
	return prev;
}

//循环快排
//调用栈来实现，栈的目的就是用来保存划分区间的从而代替递归

void QuickSort(int* array, int size)
{
	Stack s;
	StackInit(&s);

	//将数据整体区间入栈

	StackPush(&s, size);
	StackPush(&s, 0);

	int left = 0, right = 0;
	while (!StackEmpty(&s))
	{
		left = StackTop(&s);
		StackPop(&s);
		right = StackTop(&s);
		StackPop(&s);

		if (right - left > 1)
		{
			int div = Partion2(array, left, right);

			//div是基准的位置
			//左侧[left,div)
			//右侧[div+1,right)

			StackPush(&s, right);
			StackPush(&s, div+1);

			StackPush(&s, div);
			StackPush(&s, left);
		}
	}
}

//递归快排(递归）

void QuickSort(int* array, int left, int right)
{
	if (right - left < 16)
	{
		//优化一下快排，不需要将快速排序递归到只有一个元素的情况

		InSertSort(array + left, right - left);
	}

	if (right - left > 1)
	{
		int div = Partion(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}

//归并排序

void MergeData(int* array, int left, int mid, int right, int* temp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	int index = left;
	
	while (begin1 < end1 && begin2 < end2)
	{
		if (array[begin1] <= array[begin2])
			temp[index++] = array[begin1++];
		else
			temp[index++] = array[begin2++];
	}

	while (begin1 < end1)
		temp[index++] = array[begin1++];
	while (begin2 < end2)
		temp[index++] = array[begin2++];
}

void _MergeSort(int* array, int left, int right, int* temp)
{
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);
		_MergeSort(array, left, mid, temp);
		_MergeSort(array, mid, right, temp);
		MergeData(array, left, mid, right, temp);
		memcpy(array + left, temp + left, (right - left)*sizeof(array[0]));
	}
}

void MergeSort(int* array, int size)
{
	int* temp = (int*)malloc(sizeof(int) * size);
	if (NULL == temp)
	{
		assert(0);
		return;
	}
	_MergeSort(array, 0, size, temp);
	free(temp);
}

//归并排序（循环）

void  MergeSortNor(int* array, int size)
{
	int gap = 1;
	int* temp = (int*)malloc(sizeof(int) * size);
	if (NULL == temp)
	{
		assert(0);
		return;
	}

	while (gap < size)
	{
		for (int i = 0; i < size; i += 2 * gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;

			//随着gap的变化，mid和right有可能越界

			if (mid > size)
				mid = size;
			if (right > size)
				right = size;

			MergeData(array, left, mid, right, temp);
		}
		memcpy(array, temp, size * sizeof(int));
		gap <<= 1;
	}
	free(temp);
}

//计数排序

void CountSort(int* array, int size)
{
	//统计数据范围
	//用户如果已经告诉就不需要统计了

	int minValue = array[0], maxValue = array[0];
	for (int i = 1; i < size; i++)
	{
		if (array[i] < minValue)
			minValue = array[i];
		if (array[i] > maxValue)
			maxValue = array[i];
	}

	//确认范围内的元素个数

	int range = maxValue - minValue + 1;

	//申请计数空间

	int* ArrayCount = (int*)malloc(sizeof(int) * range);
	if (NULL == ArrayCount)
	{
		assert(0);
		return;
	}
	memset(ArrayCount, 0, range * sizeof(int));

	//统计每个数字出现的个数

	for (int i = 1; i < size; i++)
	{
		ArrayCount[array[i] - minValue]++;
	}

	//回收数据

	int index = 0;
	for (int i = 1; i < range; i++)
	{
		while (ArrayCount[i]--)
		{
			array[index++] = i + minValue;
		}
	}
	
	free(ArrayCount);
}