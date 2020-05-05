#include <iostream>
#include <assert.h>

using namespace std;

//插入排序（直接插入排序）

void InsertSort(int* arr, int size)
{
	int i = 1;
	for (; i < size; i++)
	{
		/*这种写法有点浪费时间，每次比较成功都要交换位置
		while (i > 0 && arr[i - 1] < arr[i])
		{
			int temp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp;
			i--;
		}*/

		int temp = arr[i], j = i - 1;
		while (i > 0 && temp < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		if (j != i - 1)
			arr[j + 1] = temp;
	}
}

//希尔排序——插入排序的优化

void ShellSort(int* arr, int size)
{
	int gap = size / 2;

	while (gap >= 1)
	{
		for (int i = gap; i < size; i++)
		{
			int key = arr[i];
			int end = i - gap;

			while (end >= 0 && key < arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			if (end != i - gap)
				arr[end + gap] = key;
		}
		gap /= 2;
	}
}

// 选择排序 

void swap(int* arr, int num1, int num2)
{
	int temp = arr[num1];
	arr[num1] = arr[num2];
	arr[num2] = temp;
}

void SelectSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int j = i;
		int min = i;
		for (; j < size; j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		if (i != min)
			swap(arr, min, i);
	}
}

// 堆排序 

void Swap(int* left, int* right)
{
	int temp = *left;
	* left = *right;
	*right = temp;
}

void AdjustDwon(int* arr, int size, int parent)
{
	//确定该节点的左孩子的位置

	int child = parent * 2 + 1;

	while (child < size)
	{
		//找到俩个孩子中最大的孩子

		if (child + 1 < size && arr[child] < arr[child + 1])
			child += 1;

		//检测双亲是否大于最大的孩子

		if (arr[parent] < arr[child])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}
void HeapSort(int* arr, int size)
{
	//建堆

	for (int root = (size - 2) >> 1; root >= 0; root--)
	{
		AdjustDwon(arr, size, root);
	}

	//开始排序

	int end = size - 1;
	while (end)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDwon(arr, end, 0);
		end--;
	}
}
// 冒泡排序 
#if 0
void BubbleSort(int* arr, int size)
{
	int i = 0;
	for (; i < size; i++)
	{
		int j = 1;
		for (; j < size - i; j++)
		{
			if (arr[j] > arr[j - 1])
			{
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}
#endif

void BubbleSort(int* arr, int size)
{
	int i = 0;
	for (; i < size - 1; i++)
	{
		int j = 0;
		int end = 0;
		for (; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				end = 1;
			}
		}
		if (end == 0)
			return;
	}
}

// 快速排序递归实现 

//三个数取值为中间的数字

int GetIndexMid(int* arr, int left, int right)
{
	//这里求中间值有一个小小的技巧
	//我们是用小值+俩数的差的一半
	//这样可以有效的避免数字越界带来的问题

	int mid = left + ((right - left) >> 1);

	if (arr[left] < arr[right])
	{
		if (arr[mid] < arr[left])
			return left;
		else if (arr[mid] > arr[right])
			return right ;
		else
			return mid;
	}
	else {
		if (arr[mid] > arr[left])
			return left;
		else if (arr[mid] < arr[right])
			return right;
		else
			return mid;
	}
}

//快速排序hoare版本 
int PartSort1(int* arr, int left, int right)
{
	int end = right;
	int key;
	int mid = GetIndexMid(arr, left, right);

	if (mid != end)
	{
		int temp = arr[mid];
		arr[mid] = arr[end];
		arr[end] = temp;
	}

	key = arr[right];

	while (left < right)
	{
		while (left < right && arr[left] <= key)
			left++;

		while (left < right && arr[right] >= key)
			right--;
		if (left < right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}

	if (left != end)
	{
		int temp = arr[left];
		arr[left] = arr[end];
		arr[end] = temp;
	}

	return left;
}

// 快速排序挖坑法 
int PartSort2(int* arr, int left, int right)
{
	int end = right;
	int key;
	int mid = GetIndexMid(arr, left, right);

	if (mid != end)
	{
		int temp = arr[mid];
		arr[mid] = arr[end];
		arr[end] = temp;
	}

	key = arr[right];

	while (left < right)
	{
		//找的比基准值大的值

		while (left < right && arr[left] <= key)
			left++;

		//用left的值来填right的坑
		//left就是一个新坑

		if (left < right)
			arr[right--] = arr[left];

		//找到比基准值小的值

		while (left < right && arr[right] >= key)
			right--;

		//用right的值来填left的坑
		//right又是一个新坑

		if (left < right)
			arr[left++] = arr[right];
	}

	//基准值来填最后的坑

	arr[left] = key;
	return left;
}

// 快速排序前后指针法 

int PartSort3(int* arr, int left, int right)
{
	int cur = left;
	int prev = left - 1;
	int mid = GetIndexMid(arr, left, right);

	if (mid != right)
	{
		int temp = arr[mid];
		arr[mid] = arr[right];
		arr[right] = temp;
	}
	int key = arr[right];

	while (cur < right)
	{
		if (arr[cur] < key && ++prev != cur)
		{
			int temp = arr[cur];
			arr[cur] = arr[prev];
			arr[prev] = temp;
		}

		cur++;
	}
	if (++prev != right)
	{
		int temp = arr[prev];
		arr[prev] = arr[right];
		arr[right] = temp;
	}
	return prev;
}

void QuickSort(int* arr, int left, int right)
{
	if (right - left > 1)
	{
		int mid = PartSort3(arr, left, right);
		QuickSort(arr, left, mid - 1);
		QuickSort(arr, mid + 1, right);
	}
}

// 归并排序递归实现 

void MergeData(int* arr, int left, int mid, int right, int* temp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	int index = left;

	while (begin1 < end1 && begin2 < end2)
	{
		if (arr[begin1] <= arr[begin2])
			temp[index++] = arr[begin1++];
		else
			temp[index++] = arr[begin2++];
	}

	while(begin1<end1)
		temp[index++] = arr[begin1++];
	while (begin2 < end2)
		temp[index++] = arr[begin2++];
}

void _MergeSort(int* arr, int left, int right, int* temp)
{
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);
		_MergeSort(arr, left, mid, temp);
		_MergeSort(arr, mid, right, temp);
		MergeData(arr, left, mid, right, temp);
		memcpy(arr + left, temp + left, (right - left) * sizeof(arr[0]));

	}
}

void MergeSort(int* arr, int size)
{
	int* temp = (int*)malloc(sizeof(int) * size);

	if (NULL == temp)
	{
		//assert用来查看如果代码报错是不是由于malloc开辟产生的错误

		assert(0);
		return;
	}

	_MergeSort(arr, 0, size, temp);
	free(temp);
}
// 归并排序非递归实现 

void MergeSortNonR(int* arr, int size)
{
	int gap = 1;
	int* temp = (int*)malloc(size * sizeof(int));

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

			if (mid > size)
				mid = size;
			if (right > size)
				right = size;

			MergeData(arr, left, mid, right, temp);
		}
		memcpy(arr, temp, size * sizeof(arr[0]));
		gap <<= 1;
	}
	free(temp);
}

// 计数排序 

void CountSort(int* arr, int size)
{
	//统计数据范围

	int minValue = arr[0], maxValue = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < minValue)
			minValue = arr[0];
		if (arr[i] > maxValue)
			maxValue = arr[0];
	}

	int range = maxValue - minValue + 1;

	//申请空间

	int* temp = (int*)malloc(sizeof(int) * range);

	if (NULL == temp)
	{
		assert(0);
		return;
	}
	memset(temp, 0, range * sizeof(int));
	
	//统计每一个数字出现的个数

	for (int i = 0; i < size; i++)
		temp[arr[i] - minValue]++;

	//回收数据

	int index = 0;
	for (int i = 0; i < size; i++)
	{
		while (arr[i]--)
			arr[index++] = i + minValue;
	}
	free(temp);
}

int main()
{
	int arr[] = { 5,8,9,0,3,1,6,2,7,4 };

	MergeSortNonR(arr, 10);

	for (auto i : arr)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}