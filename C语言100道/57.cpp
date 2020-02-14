#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long a[100] = { 0 }, i = 0, j = 0, b[100] = { 0 };
	a[0] = 1;
	a[1] = 1;
	a[2] = 1;
	printf("%lld\n", a[0]);
	printf("%lld	%lld\n", a[0],a[1]);
	for (i = 2; i < 15; i++)
	{
		b[0] = 1;
		b[i] = 1;
		printf("%lld	", b[0]);
		for (j = 1; j < i; j++)
		{
			b[j] = a[j - 1] + a[j];
			printf("%lld	", b[j]);
		}
		for (j = 1; j < i; j++)
		{
			a[0] = 1;
			a[j] = b[j];
		}
		a[i] = 1;
		printf("%lld	", b[i]);
		printf("\n");
	}
	system("pause");
	return 0;
}
//57.题目：打印出杨辉三角形