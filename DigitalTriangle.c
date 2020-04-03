//数字三角问题
//给一个数字n，然后输入一个逐行元素递增的数据
//从开头逐行向下走，直到第n行，求途径上所有数字的和最大

#include <stdio.h>

#pragma warning (disable:4996)

int max_way(int arr[][100], int i,int j, int num)
{
	if (i >= num-1)
		return 0;
	int retLeft = arr[i + 1][j] + max_way(arr, i + 1, j, num);
	int retRight = arr[i + 1][j+1] + max_way(arr, i + 1, j+1, num);
	return retLeft > retRight ? retLeft : retRight;
}

int main()
{
	int num, ret;
	scanf("%d", &num);
	int arr[100][100];
	for (int i = 0; i < num; i++)
		for (int j = 0; j <= i; j++)
			scanf("%d",&arr[i][j]);
	ret = arr[0][0];
	printf("%d",ret+max_way(arr, 0,0, num));
	return;
}