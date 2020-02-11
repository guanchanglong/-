#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 101;
	for (; n <= 200; n++)
	{
		int m = 2,x=0;
		while (m < n)
		{
			if (n%m == 0)
			{
				x = x + 1;
			}
			m = m + 1;
		}
		if (x == 0)
		{
			printf("%d\n", n);
		}
	}
	system("pause");
	return 0;
}
//14.题目：判断101-200之间有多少个素数，并输出所有素数。