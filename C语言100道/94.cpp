#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long a = 1;
	for (int i = 1; i <= 20; i++)
	{
		a *= 2;
	}
	printf("2��20�η�Ϊ��%lld\n", a);
	system("pause");
	return 0;
}
//94.��Ŀ������2��20�η�����������**��pow()