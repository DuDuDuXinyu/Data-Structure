//3-15�ռ���������
//һ��n*n�ľ����ھ����е�ĳЩλ��������
//������Ͻǵ����½ǵ�����·���������������ֵĺ͵����ֵ

#include <stdio.h>

int roadLine(int arr[][20], int i, int j, int n)
{
	//�������ȿ�ʼ����

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