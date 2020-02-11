#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10], n = 0, sum = 0;
	printf("请输入10个数字：");
	for (int x = 0; x < 10; x++)
	{
		scanf("%d", &a[x]);
	}
	for (int i = 0; i < 10; i++)
	{
		n = 0;
		for (int j = 0; j < 10; j++)
		{
			if (a[i] == a[j])
			{
				n = n + 1;
			}
		}
		sum += n;
	}
	if (sum == 10)
	{
		printf("true");
	}
	else
	{
		printf("false");
	}
	system("pause");
	return 0;
}
//30.题目：	给定一个整数数组，判断是否存在重复元素。
//			如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。