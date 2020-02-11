#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4-x; y++)
		{
			printf(" ");
		}
		printf("*");
		for (int z = 0; z < x*2; z++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (int x1 = 3; x1 > 0; x1--)
	{
		for (int y1 = 0; y1 < 5-x1 ; y1++)
		{
			printf(" ");
		}
		printf("*");
		for (int z1 = 2; z1 < x1*2; z1++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
//题目：打印出如下图案（菱形）