//3-15收集样本问题
//一个n*n的矩阵，在矩阵中的某些位置有数字
//求从左上角到右下角的俩条路径中所经过的数字的和的最大值

#include <stdio.h>

int roadLine(int arr[][20], int i, int j, int n)
{
	//按行优先开始遍历

	if()
}

int roadColumn(int arr[][20], int i, int j, int n)
{

}

int main()
{
	int n;
	scanf("%d", &n);
	int arr[20][20];
	while (1)
	{
		int i, j, k;
		scanf("%d %d %d", &i, &j, &k);
		if (i == 0 && j == 0 && k == 0)
			break;
		arr[j-1][i-1] = k;
	}
	int longLine = roadLine(arr, 0, 0, n);
	int longColumn = roadColumn(arr, 0, 0, n);
	printf("%d", longLine + longColumn);
	return 0;
}