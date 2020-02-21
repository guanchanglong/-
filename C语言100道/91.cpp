#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 1, j = 1,k = 1;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 50; j++)
		{
			for (k = 0; k < 100; k++)
			{
				if (100 == i * 5 + j * 2 + k)
				{
					printf("1:%d\t2:%d\t5:%d\n", k, j, i);
				}
			}
		}
	}
	system("pause");
	return 0;
}
//91.题目：如何组合1、2、5这三个数使其和为100.