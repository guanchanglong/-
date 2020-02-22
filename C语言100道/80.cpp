#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, a = 1, sum = 0, num[4];
	printf("请输入(四位)数据：");
	scanf("%d", &n);
	for (int i = 0; i < 4; i++)
	{
		a = 10;
		n = n / a;
		num[i] = (n%a + 5) % 10;
	}
	sum = num[0];
	num[0] = num[3];
	num[3] = sum;
	sum = num[1];
	num[1] = num[2];
	num[2] = sum;
	sum = 0;
	a = 1;
	for (int j = 0; j < 4; j++)
	{
		sum += num[j] * a;
		a *= 10;
	}
	printf("加密后：%d\n", sum);
	system("pause");
	return 0;
}
//80.题目：	某个公司采用公用电话传递数据，数据是四位的整数，在传递过程中是加密的.
//			加密规则如下：每位数字都加上5,然后用和除以10的余数代替该数字，再将第一位和第四位交换，第二位和第三位交换。