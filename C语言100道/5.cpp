#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
int main()
{
	int a[3],i,j,n;
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < 2; i++)
	{
		for (j = i + 1; j < 3; j++)
		{
			if (a[i]>a[j])
			{
				n = a[i];
				a[i] = a[j];
				a[j] = n;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}