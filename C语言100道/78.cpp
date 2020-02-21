#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
void print(int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("＊");
	}
	printf("\n");
}
int main()
{
	int n, i = 0;
	printf("请输入7个(1-50)的整数值\n");
	for (i = 0; i < 7; i++)
	{
		scanf("%d", &n);
		if (n >= 1 && n <= 50)
		{
			print(n);
		}
		else
		{
			printf("输入数值错误\n");
			break;
		}
	}
	system("pause");
	return 0;
}
//78.题目：读取7个数（1—50）的整数值，每读取一个值，程序打印出该值个数的＊。