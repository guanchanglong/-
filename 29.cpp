#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long num = 1, sum = 0;
	for (int x = 1; x <= 20; x++)
	{
		num = 1;
		for (int y = 1; y <= x; y++)
		{
			num = num*y;
		}
		sum += num;
	}
	printf("%lld\n", sum);
	system("pause");
	return 0;
}
//29.题目：求1+2!+3!+...+20!的和。