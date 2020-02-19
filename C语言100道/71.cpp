#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char a[50], b[50];
	int i = 0, sum1 = 0, sum2 = 0;
	printf("请依次输入字符串a、b：\n");
	gets(a);
	gets(b);
	while (a[i] != '\0')
	{
		sum1 += a[i];
		i++;
	}
	i = 0;
	while (b[i] != '\0')
	{
		sum2 += b[i];
		i++;
	}
	if (sum1 > sum2)
	{
		printf("字符串a大\n");
	}
	else
	{
		printf("字符串b大\n");
	}
	system("pause");
	return 0;
}
//71.题目：字符串排序。 
//分析：
//字符串用ASCII码比较大小，规则是：
//1、比较首字母的ASCII码大小
//2、若是前面的字母相同，则比较之后的字母的ASCII码值
//3、若是一个字符串从首字母开始包含另一个字符串，则认为字符串长度较长的大；例 ：ab > a