#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char i, j, l;
	printf("请输入前两个字母：");
	scanf("%c", &i);
	switch (i)
	{
	case 'M':
		printf("星期一");
		break;
	case 'm':
		printf("星期一");
		break;
	case 'T':
		scanf("%c", &j);
		switch (j)
		{
		case 'u':printf("星期二"); break;
		case 'h':printf("星期四"); break;
		default:printf("输入错误"); break;
		}
		break;
	case 't':
		scanf("%c", &j);
		switch (j)
		{
		case 'u':printf("星期二"); break;
		case 'h':printf("星期四"); break;
		default:printf("输入错误"); break;
		}
		break;
	case 'W':printf("星期三"); break;
	case 'w':printf("星期三"); break;
	case 'F':printf("星期五"); break;
	case 'f':printf("星期五"); break;
	case 'S':
				scanf("%c", &l);
				if (l == 'a')
				{
					printf("星期六");
				}
				else if (l == 'u')
				{
					printf("星期天");
				}
				else
				{
					printf("输入错误");
				}
				break;
	case 's':
				scanf("%c", &l);
				if (l == 'a')
				{
					printf("星期六");
				}
				else if (l == 'u')
				{
					printf("星期天");
				}
				else
				{
					printf("输入错误");
				}
	}
	system("pause");
	return 0;
}
//36.题目：请输入星期几的第一个字母来判断一下是星期几，如果第一个字母一样，则继续判断第二个字母。