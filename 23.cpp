#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x, y, i,j, b[50] = {0};
	for (i = 2; i <= 1000; i++)
	{
		x = 0;
		y = 0;
		for (j = 1; j < i; j++)
		{
			if (i%j == 0)
			{
				x = x + j;
				b[y++] = j;
			}
		}
		if (i == x)
		{
			printf("%d=", i);
			for (int z=0; z < y; z++)
			{
				printf("%d",b[z]);
				if (z < y - 1)
				{
					printf("+");
				}
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}
//23.��Ŀ��һ�������ǡ�õ�����������֮�ͣ�������ͳ�Ϊ"����"������6=1��2��3.����ҳ�1000���ڵ�����������