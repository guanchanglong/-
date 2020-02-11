#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int sum = 0;
	for (int i = 1; i < 101; i++)
	{
		sum += i;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}
//46.题目：统计 1 到 100 之和。