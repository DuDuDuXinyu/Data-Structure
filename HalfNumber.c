//������������
//����һ����Ȼ��n��Ȼ��ÿһ�θ�n��ǰ��+��һ�����֣�С��n/2�����ݹ�ֱ���������
//ע�⣺���ܰ����ظ���Ԫ�أ�����48,->2 4 48;24 48����ֻ����һ��

#include <stdio.h>

#pragma warning (disable:4996)

int group[250] = { 0 };

int Set(int n)
{
	if (group[n] > 0)
	{
		return group[n];
	}
	else
	{
		group[n] = 1;
		for (int i = 1; i <= n / 2; i++)
		{
			group[n] = group[n] + Set(i);//�ݹ�
			if ((i > 10) && (i / 10 <= (i % 10) / 2))
			{
				group[n] = group[n] - group[i / 10];
			}
		}
	}
	return group[n];
}

int main()
{
	int num;
	printf("���������֣�");
	scanf("%d", &num);
	printf("%d", Set(num));

	system("pause");
	return 0;
}