#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[100];
	char b[50];
	printf("�������ַ�����");
	gets(a);
	printf("������Ŀ���ַ�����");
	gets(b);
	char *c = strstr(a, b);
	printf("%s", c);
	system("pause");
	return 0;
}
//58.��Ŀ����һ�����ַ����в��Ҷ��ַ�����λ��