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
	//��i��Ԫ���Ƿ���ǰ��Ԫ��[k...i-1]�г��ֹ�

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
	//��ֻʣ��һ��Ԫ��ʱ����� 

	if (k == m)   
	{
		//ÿһ�ε��������һ�ֽ��

		count++;
		for (int i = 0; i <= m; i++)
		{
			printf("%c", list[i]);
		}
			
		printf("\n");
	}
	
	//���ж��Ԫ�ش����У��ݹ��������

	for (int i = k; i <= m; i++)  
	{
		//��k��i��ָ���Ԫ�ز���ͬ��ʱ��ͽ��л�λ��Ȼ��ݹ������һ��

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
	printf("������Ԫ�ظ���:\n");
	scanf("%d", &n);
	printf("����������е�Ԫ��:\n");

	//getchar�������յ�����������֮��Ļس����߿ո�
	//û�е�getchar�Ļ�������ո���߻س��ͻᱻ����Ϊ���ַ�����¼��arr���棬�Ӷ���������

	getchar();
	gets(arr);
	printf("���в�ͬ����Ϊ:\n");
	perm(arr, 0, n - 1);
	printf("��������Ϊ��%d\n", count);
	return 0;
}