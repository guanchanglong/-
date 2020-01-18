#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	char x;
	scanf("%d", &n);
	x = (n >= 90) ? 'A' : ((n > 60 && n < 89) ? 'B' : ((n<60) ? 'C' : '0'));
	printf("%c", x);
	system("pause");
	return 0;
}
//17.题目：利用条件运算符的嵌套来完成此题：学习成绩 >= 90分的同学用A表示，60 - 89分之间的用B表示，60分以下的用C表示。