#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
void print(int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("��");
	}
	printf("\n");
}
int main()
{
	int n, i = 0;
	printf("������7��(1-50)������ֵ\n");
	for (i = 0; i < 7; i++)
	{
		scanf("%d", &n);
		if (n >= 1 && n <= 50)
		{
			print(n);
		}
		else
		{
			printf("������ֵ����\n");
			break;
		}
	}
	system("pause");
	return 0;
}
//78.��Ŀ����ȡ7������1��50��������ֵ��ÿ��ȡһ��ֵ�������ӡ����ֵ�����ģ���