#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10], i = 0, j = 0, k, b[10];
	printf("请输入数组(10位):");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	printf("请输入移动位置:");
	scanf("%d", &k);
	for (i = 0; i < 10; i++)
	{
		a[(i + k) % 10] = b[i];
	}
	printf("结果:");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
//50.题目：给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数