#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b, c;
	printf("请输入两个数字：");
	scanf("%d%d", &a,&b);
	c = a;
	a = b;
	b = c;
	printf("%d %d\n", a, b);
	system("pause");
	return 0;
}
//48.题目：两个变量值互换。