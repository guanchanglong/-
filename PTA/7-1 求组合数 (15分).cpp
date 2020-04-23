#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
double fact(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n*fact(n - 1);
}
int main()
{
	int m, n;
	double sum;
	scanf("%d %d", &m, &n);
	sum = fact(n) / (fact(m)*fact(n - m));
	printf("result = %0.f", sum);
	system("pause");
	return 0;
}