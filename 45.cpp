#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[3][3], b[3][3], i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			b[i][j] = b[i][j] + a[i][j];
			printf("%d\t", b[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
//45.��Ŀ������ 3 �� 3 �еľ���ʵ�����Ӧλ�õ�������ӣ�������һ���¾���