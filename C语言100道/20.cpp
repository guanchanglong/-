#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d", &n);
	if (n % 3 == 0 && n % 5 == 0)
	{
		printf("FizzBuzz\n");
	}
	else if (n % 3 == 0)
	{
		printf("Fizz\n");
	}
	else if (n % 5 == 0)
	{
		printf("Buzz\n");
	}
	system("pause");
	return 0;
}
//20.题目： 写一个程序，输出从 1 到 n 数字的字符串表示。
//			1.如果 n 是3的倍数，输出“Fizz”；
//			2.如果 n 是5的倍数，输出“Buzz”；
//			3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。