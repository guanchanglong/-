#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	float x = 1, y = 2, z = 0, num = 0;
	for (int i = 0; i < 20; i++)
	{
		num = x;
		z = z + y / x;
		x = y;
		y = num + x;
	}
	printf("%f\n", z);
	system("pause");
	return 0;
}
//28.题目：有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和。