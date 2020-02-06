#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int math(int n)
{
	if (n == 1)
		return 1;
	else
		return n*math(n - 1);
}
int main()
{
	int n = 5;
	int x = n;
	printf("%d\n",math(n));
	system("pause");
	return 0;
}
//31.题目：利用递归方法求5!。