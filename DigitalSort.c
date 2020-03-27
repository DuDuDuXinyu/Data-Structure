//n个元素{1,2.3,4,5，...，n}有n！个不同的排列顺序
//给一个数字n，然后在给出一个由前n个元素组成的n位数
//我们输出该n位数在顺序排列中的位置处于第几位，从0开始
//并且输出该排列数字的下一个排列数字

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
	int n, i, k, j, order[100];
	int  f[100], mid, h;

	//f数组里面放的是在当前位数字有多少种不同的排列组合，也就是n！

	f[0] = 1;
	for (i = 1; i <= 22; i++)
	{
		f[i] = f[i - 1] * i;
	}

	printf("请输入元素的个数,以及一个序列\n");
	while(scanf("%d", &n) != EOF)
	{
		//n必须大于0

		if (n <= 0)
		{
			return 0;
		}

		//将自己给的排序数字存入order数组

		for (i = 0; i < n; i++)
		{
			scanf("%d", &order[i]);
		}
			
		//只有一个数据的情况

		if (n == 1)
		{
			printf("0\n1\n");
		}
		else
		{
			//计算给出的排列数字在顺序排列中的位置

			int lis = 0;
			for (i = 0, k = n - 1; i < n - 1; i++, k--)
			{
				//k是用来选择现在i对应的数字的的n！

				int t = 0;

				//从头开始遍历到当前看有几个数字是比当前数字小的

				for (j = 0; j < i; j++)
				{
					if (order[j] < order[i])
					{
						t++;
					}
				}

				//计算当前数字排序的位置

				lis += (order[i] - 1 - t) * f[k];
			}
			printf("该序列是第 %d 个\n", lis);

			//排下一个排列数字的顺序

			for (i = n - 2; i >= 0; i--)
			{
				//找到需要改变的位置

				if (order[i] < order[i + 1])
				{
					j = i;
					for (k = n - 1; k > j; k--)
					{
						//确定与哪一个位置的元素进行交换

						if (order[k] > order[j])
						{
							//mid是用来确定需改变位置后面的数字的中间位置

							mid = j + (n - j) / 2;

							//交换这俩个数字

							SWAP(&order[j], &order[k]);

							//把改变位置后的数字逆置，然后就是换了数字之后的第一个数字

							for (j++, h = 1; j <= mid; j++, h++)
							{
								SWAP(&order[j], &order[n - h]);
							}
						}
					}
					break;
				}
			}
			printf("该序列的下一个序列是：\n");
			for (i = 0; i < n; i++)
			{
				printf("%d ", order[i]);
			}	
			printf("\n");
		}
	}
	return 0;
}