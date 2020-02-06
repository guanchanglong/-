#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, j, n ;
	for (i = 2; i < 100; i++)
	{
		n = 0;
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				n++;
			}
		}
		if (n == 0)
		{
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}
//39.题目：求100之内的素数。