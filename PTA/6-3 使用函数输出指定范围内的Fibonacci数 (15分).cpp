#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
void PrintFN(int m, int n)
{
	int i = 1, num = 0;
	while (fib(i) <= n){
		if (fib(i) >= m&&fib(i) <= n)
		{
			num++;
			if (num == 1)
				printf("%d", fib(i));
			else
				printf(" %d", fib(i));

		}
		i++;
	}
	if (num == 0)
	{
		printf("No Fibonacci number\n");
	}

}
int main(){
	int m, n, t;
	scanf("%d %d %d", &m, &n, &t);
	printf("fib(%d) = %d\n", t, fib(t));
	PrintFN(m, n);
	system("pause");
	return 0;
}