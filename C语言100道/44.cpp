#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10];
	printf("请输入十个数字：\n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int j = 9; j >=0; j--)
	{
		printf("%d ", a[j]);
	}
	system("pause");
	return 0;
}
//44.题目：将一个数组逆序输出。