#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[3][3], i = 0, j = 0, sum = 0;
	printf("���������\n");
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
			if (i == j)
			{
				sum = sum + a[i][j];
			}
		}
	}
	printf("���Խ��ߺ�Ϊ��%d\n", sum);
	system("pause");
	return 0;
}
//42.��Ŀ����һ��3*3�������Խ���Ԫ��֮�͡�