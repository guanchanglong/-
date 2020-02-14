#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char a[100];
	int i = 0;
	printf("请输入长度小于100的字符串：");
	gets(a);
	while (a[i] != '\0')
	{
		i++;
	}
	printf("该字符串长度为：%d\n", i);
	system("pause");
	return 0;
}
//56.题目：计算字符串长度。　