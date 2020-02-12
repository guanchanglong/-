#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char a[50];
	int i = 0, j = 0;
	printf("请输入整数(大于等于1000000):");
	gets(a);
	while (a[i] != '\0')
	{
		i++;
	}
	j = i - 7;
	for (; j <= (i - 4); j++)
	{
		printf("%c", a[j]);
	}
	system("pause");
	return 0;
}
//52.题目：取一个整数a从右端开始的4〜7位。