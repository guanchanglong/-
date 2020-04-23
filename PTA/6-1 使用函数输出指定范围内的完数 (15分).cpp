#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int factorsum(int number);
void PrintPN(int m, int n);
int main()
{
	int i, m, n;
	scanf("%d %d", &m, &n);
	if (factorsum(m) == m)
		printf("%d is a perfect number\n", m);
	if (factorsum(n) == n)
		printf("%d is a perfect number\n", n);
	PrintPN(m, n);
	system("pause");
	return 0;
}
int factorsum(int number)
{
	int i, sum = 0;
	if (number == 1) return 1;
	for (i = 1; i < number; i++)
	if (number % i == 0)
		sum = sum + i;
	return sum;
}
void PrintPN(int m, int n)
{
	int i, j, count = 0;
	for (i = m; i <= n; i++)
	{
		if (factorsum(i) == i)
		{
			count++;
			printf("%d = ", i);
			if (i == 1) printf("1");
			for (j = 1; j < i; j++)
			{
				if (i % j == 0) {
					printf("%d", j);
					if (j == i / 2)
						break;
					printf(" + ");
				}
			}
			printf("\n");
		}
	}
	if (!count)
		printf("No perfect number");
}
