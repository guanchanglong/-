#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
int main()
{
	long long int i=0, j=1,n;
	while (j<1000000000000000)
	{
		n = i + j;
		i = j;
		j = n;
		printf("%lld\n", j);
	}
	return 0;
}
//6.题目：斐波那契数列。