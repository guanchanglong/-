#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	if (n % 3 == 0)
	{
		printf("是3的幂次方\n");
	}
	else
	{
		printf("不是3的幂次方\n");
	}
	system("pause");
	return 0;
}
//12.题目：给定一个整数，写一个函数来判断它是否是 3 的幂次方。