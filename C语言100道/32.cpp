#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void a(int n)
{
	if (n <= 1)
	{
		char c = getchar();
		putchar(c);
	}
	else
	{
		char c = getchar();
		a(n - 1);
		putchar(c); //��C�����У�getchar�����ǵ����ַ����뺯����putchar�����ǵ����ַ����������
	}
}
int main()
{
	int n = 5;
	printf("����������ַ�:");
	a(n);
	system("pause");
	return 0;
}
//32.��Ŀ�����õݹ麯�����÷�ʽ�����������5���ַ������෴˳���ӡ������