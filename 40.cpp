#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, j, n, m, l = 0;
	printf("请输入：");
	scanf("%d", &n);
	for (i = 2; i < n; i++)
	{
		m = 0;
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				m++;
			}
		}
		if (m == 0)
		{
			l++;
			printf("%d\n", i);
		}
	}
	printf("一共有%d个质数\n", l);
	system("pause");
	return 0;
}
//40.题目：统计所有小于非负整数 n 的质数的数量。