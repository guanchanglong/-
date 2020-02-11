#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	unsigned int n;
	scanf("%d", &n);
	int len = sizeof(n)* 8;
	int num;
	printf("原：    ");
	for (int i = 0; i <len; i++)
	{
		num = n;
		num = num >> (31 - i);//向右移位
		int t = num & 1;//进行位运算，若该位上为0，则t=0，若为1，则为t=1
		printf("%d", t);
	}
	printf("\n");
	printf("颠倒后：");
	for (int i = 31; i >= 0; i--)
	{
		num = n;
		num = num >> (31 - i);
		int t = num & 1;
		printf("%d", t);
	}
	printf("\n");
	system("pause");
	return 0;
}
//19.题目：颠倒给定的 32 位无符号整数的二进制位。