#define _CRT_SECURE_NO_DEPRECATE 0
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>
int main()
{
	time_t now,t1;
	t1 = time(&now); 
	struct tm *t;
	t = localtime(&now);
	Sleep(1000);
	printf("%d年%d月%d日%d:%d:%d\n", t->tm_year+1900, t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
	return 0;
}
//10.题目：暂停一秒输出，并格式化当前时间。