//������������
//��һ������n��Ȼ������һ������Ԫ�ص���������
//�ӿ�ͷ���������ߣ�ֱ����n�У���;�����������ֵĺ����

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