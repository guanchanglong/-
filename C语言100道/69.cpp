#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
double sum(int n)
{
	double num = 0;
	if (n % 2 == 0)
	{
		double i = n;
		while (i > 0)
		{
			num = num + 1 / i;
			i = i - 2;
		}
	}
	else
	{
		double j = n;
		while (j > 0)
		{
			num = num + 1 / j;
			j = j - 2;
		}
	}
	return num;
}
int main()
{
	int n;
	double m;
	scanf("%d", &n);
	m=sum(n);
	printf("���Ϊ��%.5f", m);
	system("pause");
	return 0;
}
//69.��Ŀ����дһ������������nΪż��ʱ�����ú�����1/2+1/4+...+1/n,������nΪ����ʱ�����ú���1/1+1/3+...+1/n     