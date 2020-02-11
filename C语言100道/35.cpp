#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num, a[5], n = 0;
	printf("请输入一个五位数字：");
	scanf("%d", &num);
	for (int i = 0; i < 5; i++)
	{
		a[i] = num % 10;
		num /= 10;
	}
	if (a[0] == a[4])
		n++;
	if (a[1] == a[3])
		n++;
	if (n == 2)
		printf("该数为回文数\n");
	else
		printf("该数非回文数\n");
	system("pause");
	return 0;
}
//35.题目：一个5位数，判断它是不是回文数。即12321是回文数，个位与万位相同，十位与千位相同