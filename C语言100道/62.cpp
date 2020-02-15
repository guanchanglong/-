#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int a[15], i = 0, j = 0, k, b[15];
	printf("请输入15个数字:");
	for (i = 0; i < 15; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	printf("请输入移动位置:");
	scanf("%d", &k);
	for (i = 0; i < 15; i++)
	{
		a[(i + k) % 15] = b[i];
	}
	printf("结果:");
	for (i = 0; i < 15; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
//62. 题目：有n个整数，使其前面各数顺序向后移m个位置，最后m个数变成最前面的m个数
