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
			group[n] = group[n] + Set(i);//µÝ¹é
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
	printf("ÇëÊäÈëÊý×Ö£º");
	scanf("%d", &num);
	printf("%d", Set(num));

	system("pause");
	return 0;
}