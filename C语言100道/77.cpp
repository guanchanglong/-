#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[50], b[50], *c;
	printf("请依次输入a、b字符串：\n");
	gets(a);
	gets(b);
	c=strcat(a, b);	//字符串连接函数
	printf("%s\n", c);
	system("pause");
	return 0;
}
//77.题目：连接字符串。