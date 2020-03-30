//集合划分问题
//有1-n的int元素集合，然后求这样的集合有多少个划分可以由m个子集组成

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