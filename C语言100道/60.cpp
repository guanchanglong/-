#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[50];
	gets(a);
	int i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	if (a[0] =='-')
	{
		printf("%c", a[0]);
		for (int j = i-1; j > 0; j--)
		{
			printf("%c", a[j]);
		}
	}
	else
	{
		for (int j = i-1; j > -1; j--)
		{
			printf("%c", a[j]);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
//60.��Ŀ��	����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��
//			��������: 123  ���: 321