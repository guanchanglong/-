#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[50], b[50], *c;
	printf("����������a��b�ַ�����\n");
	gets(a);
	gets(b);
	c=strcat(a, b);	//�ַ������Ӻ���
	printf("%s\n", c);
	system("pause");
	return 0;
}
//77.��Ŀ�������ַ�����