#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char a[50], b[50];
	int i = 0, sum1 = 0, sum2 = 0;
	printf("�����������ַ���a��b��\n");
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
		printf("�ַ���a��\n");
	}
	else
	{
		printf("�ַ���b��\n");
	}
	system("pause");
	return 0;
}
//71.��Ŀ���ַ������� 
//������
//�ַ�����ASCII��Ƚϴ�С�������ǣ�
//1���Ƚ�����ĸ��ASCII���С
//2������ǰ�����ĸ��ͬ����Ƚ�֮�����ĸ��ASCII��ֵ
//3������һ���ַ���������ĸ��ʼ������һ���ַ���������Ϊ�ַ������Ƚϳ��Ĵ��� ��ab > a