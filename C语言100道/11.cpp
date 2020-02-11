#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdlib.h>
#include<stdio.h>
int main()
{
	int x=0,y=0;
	unsigned int n;
	scanf("%d", &n);
	while (n!=0)
	{
		if (n % 2 == 1)
		{
			x = x + 1;
		}
		n = n / 2;
	}
	printf("%d", x);
	system("pause");
	return 0;
}