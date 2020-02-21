#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[50];
	int k = 0, b[25], f = 0;
	gets(a);
	int i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	for (int j = 0; j < i; j++)
	{
		k = 0;
		for (int l = 0; l < i; l++)
		{
			if (a[j]==a[l])
			{
				k++;
			}
		}
		if (k == 1)
		{
			b[f] = j;
			f++;
		}
	}
	printf("%d\n", b[0]);
	system("pause");
	return 0;
}
//74.题目：给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。