#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int lenth(char a[])
{
	int i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	return i;
}
int main()
{
	char a[100];
	int i;
	printf("�������ַ�����");
	gets(a);
	i=lenth(a);
	printf("���ַ����ĳ���Ϊ��%d\n", i);
	system("pause");
	return 0;
}
//64.��Ŀ��дһ����������һ���ַ����ĳ��ȣ���main�����������ַ�����������䳤�ȡ�