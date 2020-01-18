#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x = 1, y = 0, z = 0;
	for (x=1; x < 10; x++)
	{
		for (y=0; y < 10; y++)
		{
			for (z=0; z < 10; z++)
			{
				if (x * 100 + y * 10 + z == x*x*x + y*y*y + z*z*z)
				{
					printf("%d\n", (x * 100 + y * 10 + z));
				}
			}
		}
	}
	system("pause");
	return 0;
}
//15.题目：打印出所有的"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数本身。例如：153是一个"水仙花数"，因为153 = 1的三次方＋5的三次方＋3的三次方。