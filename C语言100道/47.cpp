#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num=50;
	while (num >= 50)
	{
		printf("请输入数字(若平方运算后小于 50 则退出):");
		scanf("%d", &num);
		num = num*num;
		printf("该数字的平方为:%d\n", num);
	}
	system("pause");
	return 0;
}
//47.题目：求输入数字的平方，如果平方运算后小于 50 则退出。