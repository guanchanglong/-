#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[100],b[100];
	int i, j, z=0;
	printf("请输入100个字符内的字符串:");
	gets(a);
	int x = strlen(a);
	for (i = 0; i < x; i++)
	{
		int n = 0, y = 0;
		for (j = 0; j < x; j++)
		{
			if (b[j] == a[i])
			{
				y = y + 1;
			}
		}
		for (j = 0; j < x; j++)
		{
			if (a[i] == a[j])
			{
				n = n + 1;
			}
		}
		if (y == 0)
		{
			b[z] = a[i];
			printf("%c字符出现了%d次\n", b[z], n);
			z = z + 1;
		}
	}
	system("pause");
	return 0;
}
//21.题目：输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。