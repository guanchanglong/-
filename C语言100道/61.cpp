#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b, c;
	printf("请依次输入三个数\n");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	int num;
	if (a < b)
	{
		num = a;
		a = b;
		b = num;
	}
	if (a < c)
	{
		num = a;
		a = c;
		c = num;
	}
	if (b < c)
	{
		num = b;
		b = c;
		c = num;
	}
	printf("从大到小为：%d %d %d", a, b, c);
	system("pause");
	return 0;
}
//61.题目：输入3个数a,b,c，按大小顺序输出。