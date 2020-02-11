#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10], t;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int j = 0; j < 10; j++)
	{
		for (int l = j; l < 10; l++)
		{
			if (a[j]>=a[l])
			{
				t = a[l];
				a[l] = a[j];
				a[j] = t;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
//41.题目：对10个数进行排序。