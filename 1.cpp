#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
int  main()
{
	int x, y, z,n,m=0;
	for (x = 1; x < 5; x++)
	{
		for (y = 1; y < 5; y++)
		{
			for (z = 1; z < 5; z++)
			{
				if (x != z&&z != y&&x != y)
				{
					n = x * 100 + y * 10 + z;
					printf("%d\n", n);
					m = m + 1;
				}
			}
		}
	}
	printf("һ�������%d����ͬ����λ��\n", m);
	return 0;
}