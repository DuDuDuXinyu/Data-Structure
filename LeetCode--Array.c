
//����Ԫ��--->�ҳ����������еĳ��ִ�������һ�������

int majorityElement(int* nums, int numsSize)
{
	int count = 1;
	int arr = nums[0];
	for (int i = 1; i < numsSize; i++)
	{
		//������ͬ�ļ�����+1����ͬ��-1

		if (arr == nums[i])
		{
			count++;
		}
		else
		{
			count--;
		}

		//Ϊ0����˵��arr��ָ�����ݲ���һ�룬���Ծ���arrָ��i����һ��

		if (0 == count)
		{
			arr = nums[i + 1];
		}
	}
	return arr;
}
