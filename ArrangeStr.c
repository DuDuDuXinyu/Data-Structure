#include<stdio.h>
#include<string.h>

#pragma warning (disable:4996)

int count = 0;

void swap(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int finish(char list[], int k, int i)
{
	//第i个元素是否在前面元素[k...i-1]中出现过

	if (i > k)
	{
		for (int j = k; j < i; j++)
		{
			if (list[j] == list[i])
			{
				return 0;
			}
		}		
	}
	return 1;
}

void perm(char list[], int k, int m)
{
	//当只剩下一个元素时则输出 

	if (k == m)   
	{
		//每一次的输出都是一种结果

		count++;
		for (int i = 0; i <= m; i++)
		{
			printf("%c", list[i]);
		}
			
		printf("\n");
	}
	
	//还有多个元素待排列，递归产生排列

	for (int i = k; i <= m; i++)  
	{
		//当k、i所指向的元素不相同的时候就进行换位，然后递归进入下一层

		if (finish(list, k, i))
		{
			swap(&list[k], &list[i]);
			perm(list, k + 1, m);
			swap(&list[k], &list[i]);
		}
	}
}
int main()
{
	int i, n;
	char arr[500];
	printf("请输入元素个数:\n");
	scanf("%d", &n);
	printf("请输入待排列的元素:\n");

	//getchar用来吸收掉输入完数字之后的回车或者空格
	//没有的getchar的话，这个空格或者回车就会被误以为是字符而记录在arr里面，从而引发错误

	getchar();
	gets(arr);
	printf("所有不同排列为:\n");
	perm(arr, 0, n - 1);
	printf("排列总数为：%d\n", count);
	return 0;
}