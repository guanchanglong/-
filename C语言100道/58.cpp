#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[100];
	char b[50];
	printf("请输入字符串：");
	gets(a);
	printf("请输入目标字符串：");
	gets(b);
	char *c = strstr(a, b);
	printf("%s", c);
	system("pause");
	return 0;
}
//58.题目：在一个长字符串中查找短字符串的位置