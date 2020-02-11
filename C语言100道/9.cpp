#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
int main()
{
	int i=0, j=1,n,m;
	scanf("%d", &n);
	while (n--)
	{
		m = i + j;
		i = j;
		j = m;
	}
	printf("%d", j);
	return 0;
}
//9.题目：假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？