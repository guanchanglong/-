#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x = 1, y = 0, z = 0;
	for (x=1; x < 10; x++)
	{
		for (y=0; y < 10; y++)
		{
			for (z=0; z < 10; z++)
			{
				if (x * 100 + y * 10 + z == x*x*x + y*y*y + z*z*z)
				{
					printf("%d\n", (x * 100 + y * 10 + z));
				}
			}
		}
	}
	system("pause");
	return 0;
}
//15.��Ŀ����ӡ�����е�"ˮ�ɻ���"����ν"ˮ�ɻ���"��ָһ����λ�������λ���������͵��ڸ����������磺153��һ��"ˮ�ɻ���"����Ϊ153 = 1�����η���5�����η���3�����η���