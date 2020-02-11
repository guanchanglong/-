#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void a(int n)
{
	if (n <= 1)
	{
		char c = getchar();
		putchar(c);
	}
	else
	{
		char c = getchar();
		a(n - 1);
		putchar(c); //在C语言中，getchar函数是单个字符输入函数，putchar代表是单个字符输出函数。
	}
}
int main()
{
	int n = 5;
	printf("请输入五个字符:");
	a(n);
	system("pause");
	return 0;
}
//32.题目：利用递归函数调用方式，将所输入的5个字符，以相反顺序打印出来。