#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10], n = 0, sum = 0;
	printf("������10�����֣�");
	for (int x = 0; x < 10; x++)
	{
		scanf("%d", &a[x]);
	}
	for (int i = 0; i < 10; i++)
	{
		n = 0;
		for (int j = 0; j < 10; j++)
		{
			if (a[i] == a[j])
			{
				n = n + 1;
			}
		}
		sum += n;
	}
	if (sum == 10)
	{
		printf("true");
	}
	else
	{
		printf("false");
	}
	system("pause");
	return 0;
}
//30.��Ŀ��	����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
//			����κ�ֵ�������г����������Σ��������� true�����������ÿ��Ԫ�ض�����ͬ���򷵻� false��