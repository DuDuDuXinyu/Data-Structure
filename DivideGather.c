//���ϻ�������
//��1-n��intԪ�ؼ��ϣ�Ȼ���������ļ����ж��ٸ����ֿ�����m���Ӽ����

#include<stdio.h>

#pragma warning (disable:4996)

int f(int n, int m) 
{
	if (m == 1 || n == m)
		return 1;
	else
		return  f(n - 1, m - 1) + m * f(n - 1, m);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d", f(n, m));
	return 0;
}