//半数单集问题
//给定一个自然数n，然后每一次给n的前面+上一个数字（小于n/2），递归直到不能添加
//注意：不能包括重复的元素，比如48,->2 4 48;24 48这样只能算一个

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
			group[n] = group[n] + Set(i);//递归
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
	printf("请输入数字：");
	scanf("%d", &num);
	printf("%d", Set(num));

	system("pause");
	return 0;
}