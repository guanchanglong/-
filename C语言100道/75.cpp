#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	for (i = 1; i < 13; i++)
	{
		if (809 * i == 800 * i + 9 * i && 9*i>=100 && 8*i<100)
		{
			printf("%d\n", i);
			printf("结果为：%d\n", 809 * i);
		}
	}
	system("pause");
	return 0;
}
//75.题目：809*??=800*??+9*?? 其中??代表的两位数, 809*??为四位数，8*??的结果为两位数，9*??的结果为3位数。求??代表的两位数，及809*??后的结果。