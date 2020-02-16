#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int lenth(char a[])
{
	int i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	return i;
}
int main()
{
	char a[100];
	int i;
	printf("请输入字符串：");
	gets(a);
	i=lenth(a);
	printf("该字符串的长度为：%d\n", i);
	system("pause");
	return 0;
}
//64.题目：写一个函数，求一个字符串的长度，在main函数中输入字符串，并输出其长度。