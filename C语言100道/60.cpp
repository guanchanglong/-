#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[50];
	gets(a);
	int i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	if (a[0] =='-')
	{
		printf("%c", a[0]);
		for (int j = i-1; j > 0; j--)
		{
			printf("%c", a[j]);
		}
	}
	else
	{
		for (int j = i-1; j > -1; j--)
		{
			printf("%c", a[j]);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
//60.题目：	给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
//			例：输入: 123  输出: 321