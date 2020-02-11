#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x = 1, y = 1, i;
	for (i = 0; i < 9; i++)
	{
		y = (y + 1) * 2;
	}
	printf("第一天一共摘了%d个\n", y);
	system("pause");
	return 0;
}
//25.题目：猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不瘾，又多吃了一个,第二天早上又将剩下的桃子吃掉一半，又多吃了一个。
//			以后每天早上都吃了前一天剩下的一半零一个。到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了多少。