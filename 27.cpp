#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b, c;
	for (a = 'x'; a <= 'z'; a++)
	{
		for (b = 'x'; b <= 'z'; b++)
		{
			for (c = 'x'; c <= 'z'; c++)
			{
				if (a != 'x' && c != 'x' && c != 'z' && a!=b && a!=c && b!=c)
				{
					printf("a对%c,b对%c,c对%c\n", a, b, c);
				}
			}
		}
	}
	system("pause");
	return 0;
}
//27.题目：	两个乒乓球队进行比赛，各出三人。甲队为a,b,c三人，乙队为x,y,z三人。以抽签决定比赛名单。
//			有人向队员打听比赛的名单。a说他不和x比，c说他不和x,z比，请编程序找出三队赛手的名单。