//ʯ�Ӻϲ�����
//n��ʯ��Χһ��Ȧ��Ȼ��ÿһ��ֻ�ܺϲ����ڵ�����ʯ��
//�ϳɵ��¶ѵ�ʯ�ӵĸ�����������һ�εĵ÷�
//ֱ��ȫ�����ϳ�Ϊһ�ѵ�ʱ����ܵ÷�

#include <stdio.h>

#pragma warning (disable:4996)

//��С�÷�

void Stone_min(int* arr, int num)
{
	int count = 1, i = 0, ret = 0;
	int front = 0, end = 0, amount = 0;

	//�ҵ���С����һ�����ֵ�λ��

	for (int j = 1; j < num; j++)
		if (arr[i] > arr[j])
			i = j;

	//��ʼ���м�����С�÷�

	front = i, end = i;
	ret = arr[i];
	while (count < num)
	{
		//�ж��������ڵ����ֵĴ�С

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

		//������ȷ�����е����ֶ��������

		count++;
	}
	printf("%d\n", amount);
}

//���÷�

void Stone_max(int* arr, int num)
{
	int count = 1, i = 0, ret = 0;
	int front = 0, end = 0, amount = 0;

	//�ҵ�������һ�����ֵ�λ��

	for (int j = 1; j < num; j++)
		if (arr[i] < arr[j])
			i = j;

	//��ʼ���м������÷�

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