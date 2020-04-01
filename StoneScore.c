//石子合并问题
//n堆石子围一个圈，然后每一次只能合并相邻的俩堆石子
//合成的新堆得石子的个数就是你这一次的得分
//直到全部都合称为一堆的时候的总得分

#include <stdio.h>

#pragma warning (disable:4996)

//最小得分

void Stone_min(int* arr, int num)
{
	int count = 1, i = 0, ret = 0;
	int front = 0, end = 0, amount = 0;

	//找到最小的那一个数字的位置

	for (int j = 1; j < num; j++)
		if (arr[i] > arr[j])
			i = j;

	//开始进行计算最小得分

	front = i, end = i;
	ret = arr[i];
	while (count < num)
	{
		//判断与其相邻的数字的大小

		if (arr[(front + 1) % num] > arr[(end - 1 + num) % num])
		{
			ret += arr[(end - 1 + num) % num];
			amount += ret;
			end = (end - 1 + num) % num;
		}
		else
		{
			ret += arr[(front + 1) % num];
			amount += ret;
			front = (front + 1) % num;
		}

		//计数，确定所有的数字都遍历完成

		count++;
	}
	printf("%d\n", amount);
}

//最大得分

void Stone_max(int* arr, int num)
{
	int count = 1, i = 0, ret = 0;
	int front = 0, end = 0, amount = 0;

	//找到最大的那一个数字的位置

	for (int j = 1; j < num; j++)
		if (arr[i] < arr[j])
			i = j;

	//开始进行计算最大得分

	front = i, end = i;
	ret = arr[i];
	while (count < num)
	{
		if (arr[(front + 1) % num] < arr[(end - 1 + num) % num])
		{
			ret += arr[(end - 1 + num) % num];
			amount += ret;
			end = (end - 1 + num) % num;
		}
		else
		{
			ret += arr[(front + 1) % num];
			amount += ret;
			front = (front + 1) % num;
		}
		count++;
	}
	printf("%d\n", amount);
}

int main()
{
	int num;
	scanf("%d", &num);
	int arr[100] = { 0 };
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}
	Stone_min(arr, num);
	Stone_max(arr, num);
	return 0;
}