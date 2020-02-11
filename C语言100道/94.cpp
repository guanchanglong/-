#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long a = 1;
	for (int i = 1; i <= 20; i++)
	{
		a *= 2;
	}
	printf("2的20次方为：%lld\n", a);
	system("pause");
	return 0;
}
//94.题目：计算2的20次方。不允许用**和pow()