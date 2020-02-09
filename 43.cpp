#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[5], i = 0, j = 0, n = 0;
	printf("请输入一个升序数组(五个数字)：");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("请输入目标数字：");
	scanf("%d", &j);
	for (i = 0; i < 5; i++)
	{

		if (j<a[i]&&n==0)
		{
			printf("%d ", j);
			n++;
		}
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
//43.题目：有一个已经排好序的数组。现输入一个数，要求按原来的规律将它插入数组中。