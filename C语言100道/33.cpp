#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int year = 10;
	for (int i = 0; i < 4; i++)
	{
		year += 2;
	}
	printf("第五个人为%d岁", year);
	system("pause");
	return 0;
}
//33.题目：	有5个人坐在一起，问第五个人多少岁？他说比第4个人大2岁。
//			问第4个人岁数，他说比第3个人大2岁。
//			问第三个人，又说比第2人大两岁。
//			问第2个人，说比第一个人大两岁。
//			最后问第一个人，他说是10岁。请问第五个人多大？