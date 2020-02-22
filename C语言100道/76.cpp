#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long i = 7, sum = 0;
	long long num = 4;
	sum += num;
	num = num * 6;
	while (i >0)
	{
		sum += num;
		i = i - 1;
		num = num*i;
	}
	printf("%lld\n", sum);
	system("pause");
	return 0;
}
//组成1位数是4个。
//组成2位数是6*4个。
//组成3位数是6*6*4个。
//组成4位数是6*6*5*4个。
//组成5位数是6*6*5*4*4个。
//组成6位数是6*6*5*4*3*4个。
//组成7位数是6*6*5*4*3*2*4个。
//组成8位数是6*6*5*4*3*2*1*4个。
//76.题目：求0—7所能组成的奇数个数。