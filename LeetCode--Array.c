﻿
//多数元素--->找出给定数组中的出现次数大于一半的数据

int majorityElement(int* nums, int numsSize)
{
	int count = 1;
	int arr = nums[0];
	for (int i = 1; i < numsSize; i++)
	{
		//遇见相同的计数器+1，不同的-1

		if (arr == nums[i])
		{
			count++;
		}
		else
		{
			count--;
		}

		//为0则是说明arr所指的数据不够一半，所以就让arr指向i的下一个

		if (0 == count)
		{
			arr = nums[i + 1];
		}
	}
	return arr;
}

//数组拆分
//给定长度为 2n 的数组, 你的任务是将这些数分成 n 对
//例如 (a1, b1), (a2, b2)，...，(an, bn)
//使得从1 到 n 的 min(ai, bi) 总和最大


int cmp(int* a, int* b) {
	return *a > * b;
}
int arrayPairSum(int* nums, int numsSize) {
	int i, j;
	int sum = 0;
	if (numsSize < 2) {
		return 0;
	}
	qsort(nums, numsSize, sizeof(int), cmp);
	for (sum = nums[0], i = 2; i < numsSize; i = i + 2) {
		sum += nums[i];
	}
	return sum;
}