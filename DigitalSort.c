#include<stdio.h>
#include<stdlib.h>

#pragma warning (disable:4996)

void SWAP(int* a, int* b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int main()
{
	int n, i, k, j, t, order[100];
	int lis, f[100], mid, h;
	f[0] = 1;
	for (i = 1; i <= 22; i++)
		f[i] = f[i - 1] * i;
	printf("请输入元素的个数,以及一个序列\n");
	if (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &order[i]);
		if (n == 1)
			printf("0\n1\n");
		else if (n >= 2)
		{
			lis = 0;
			for (i = 0, k = n - 1; i < n - 1; i++, k--)
			{
				t = 0;
				for (j = 0; j < i; j++)
					if (order[j] < order[i])
						t++;
				lis += (order[i] - 1 - t) * f[k];
			}
			printf("该序列是第%d个\n", lis);

			for (i = n - 2; i >= 0; i--)
			{
				if (order[i] < order[i + 1])
				{
					j = i;
					for (k = n - 1; k > j; k--)
					{
						if (order[k] > order[j])
						{
							mid = j + (n - j) / 2;
							SWAP(&order[j], &order[k]);
							for (j++, h = 1; j <= mid; j++, h++)
								SWAP(&order[j], &order[n - h]);
						}
					}
					break;
				}
			}
			printf("该序列的下一个序列是：\n");
			for (i = 0; i < n - 1; i++)
				printf("%d ", order[i]);
			printf("%d\n", order[i]);
		}
	}
	return 0;
}