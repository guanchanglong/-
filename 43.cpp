#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[5], i = 0, j = 0, n = 0;
	printf("������һ����������(�������)��");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("������Ŀ�����֣�");
	scanf("%d", &j);
	for (i = 0; i < 5; i++)
	{

		if (j<a[i]&&n==0)
		{
			printf("%d ", j);
			n++;
		}
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
//43.��Ŀ����һ���Ѿ��ź�������顣������һ������Ҫ��ԭ���Ĺ��ɽ������������С�