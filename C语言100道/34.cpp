#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num, sum = 0;
	printf("请输入数字:");
	scanf("%d", &num);
	while (num > 0)
	{
		printf("%d ", num % 10);
		num = num / 10;
		sum++;
	}
	printf("\n它是%d位数\n", sum);
	system("pause");
	return 0;
}
//34.题目：给一个不多于5位的正整数，要求：一、求它是几位数，二、逆序打印出各位数字。