#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
int main()
{
	int i=0, j=1,n,m;
	scanf("%d", &n);
	while (n--)
	{
		m = i + j;
		i = j;
		j = m;
	}
	printf("%d", j);
	return 0;
}
//9.��Ŀ��������������¥�ݡ���Ҫ n ������ܵ���¥����ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�