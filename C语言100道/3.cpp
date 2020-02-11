#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<math.h>
int main()
{
	int i;
	for (i = -10000000; i < 10000000; i++)
	{
		if (sqrt(float(i + 100)) == floor(sqrt(float(i + 100))+0.5) && sqrt(float(i + 268)) == floor(sqrt(float(i + 268))+0.5))//floor函数作用是向下取整，如floor(1.5)=1
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
//题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
