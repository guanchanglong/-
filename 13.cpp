#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int x=1,y=1,z=2,n=0;
	while (n<10)
	{
		printf("%lld	%lld	%lld	", x, y, z);
		x = x + z;
		y = y + x;
		z = z + y;
		n++;
	}
	system("pause");
	return 0;
}
//13.��Ŀ���ŵ����⣺��һ�����ӣ��ӳ������3������ÿ���¶���һ�����ӣ�С���ӳ����������º�ÿ��������һ�����ӣ��������Ӷ���������ÿ���µ���������Ϊ���٣�