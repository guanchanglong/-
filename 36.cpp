#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char i, j, l;
	printf("������ǰ������ĸ��");
	scanf("%c", &i);
	switch (i)
	{
	case 'M':
		printf("����һ");
		break;
	case 'm':
		printf("����һ");
		break;
	case 'T':
		scanf("%c", &j);
		switch (j)
		{
		case 'u':printf("���ڶ�"); break;
		case 'h':printf("������"); break;
		default:printf("�������"); break;
		}
		break;
	case 't':
		scanf("%c", &j);
		switch (j)
		{
		case 'u':printf("���ڶ�"); break;
		case 'h':printf("������"); break;
		default:printf("�������"); break;
		}
		break;
	case 'W':printf("������"); break;
	case 'w':printf("������"); break;
	case 'F':printf("������"); break;
	case 'f':printf("������"); break;
	case 'S':
				scanf("%c", &l);
				if (l == 'a')
				{
					printf("������");
				}
				else if (l == 'u')
				{
					printf("������");
				}
				else
				{
					printf("�������");
				}
				break;
	case 's':
				scanf("%c", &l);
				if (l == 'a')
				{
					printf("������");
				}
				else if (l == 'u')
				{
					printf("������");
				}
				else
				{
					printf("�������");
				}
	}
	system("pause");
	return 0;
}
//36.��Ŀ�����������ڼ��ĵ�һ����ĸ���ж�һ�������ڼ��������һ����ĸһ����������жϵڶ�����ĸ��