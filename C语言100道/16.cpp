#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x, n;
	scanf("%d", &n);
	for (x = 2; x <= n; x++) 
	{
		while (n%x == 0)
		{
			printf("%d", x);
			n = n / x;
			if (n != 1)
			{
				printf("*");
			}
		}
	}
	system("pause");
	return 0;
}
//16.��Ŀ����һ���������ֽ������������磺����90, ��ӡ��90 = 2 * 3 * 3 * 5��