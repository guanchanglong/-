#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	float i, n = 100, x = 0;
	for (i = 0; i < 10; i++)
	{
		x = x + n * 2;
		n = n / 2;
	}
	printf("共经过%.1f米，第十次反弹%.1f米高\n", (x-100-n), n);
	system("pause");
	return 0;
}
//24.题目：一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？