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
//13.题目：古典问题：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少？