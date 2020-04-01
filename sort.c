#include <stdio.h>

//打印数组

void PrintArray(int* arr, int len)
{
	int i = 0;
	while (i < len)
		printf("%d ", arr[i]);
	printf("\n");
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

//选择排序

void SelectSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int maxpos = 0;
		for (int j = 1; j < size - 1; j++)
		{
			if (arr[j] > arr[maxpos])
				maxpos = j;
		}

		if (maxpos != size - 1 - i)
			Swap(&arr[maxpos], &arr[size - 1 - i]);
	}
}

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

		if(maxpos!=end)
			Swap(&arr[maxpos], &arr[end]);

		if (minpos != end)
			Swap(&arr[minpos], &arr[begin]);

		begin++;
		end--;
	}
}