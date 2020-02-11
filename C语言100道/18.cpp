#define _CRT_SECURE_NO_DEPRECATE 0
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	time_t now, t1;
	t1 = time(&now);
	struct tm *t;
	t = localtime(&now);
	printf("%d年%d月%d日\n", t->tm_year + 1900, t->tm_mon+1, t->tm_mday);
	system("pause");
	return 0;
}
//18.题目：输出指定格式的日期。