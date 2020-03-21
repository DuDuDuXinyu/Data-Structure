
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
