#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
int main()
{
	int i, j;
	for (i = 1; i < 10;i++)\
	{
		for (j = 1; j <=i; j++)
		{
			printf("%d * %d = %-5d", j, i, i*j);
		}
		printf("\n");
	}
}
//8.题目：输出 9 * 9 乘法口诀表。