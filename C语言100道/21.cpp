#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[100],b[100];
	int i, j, z=0;
	printf("������100���ַ��ڵ��ַ���:");
	gets(a);
	int x = strlen(a);
	for (i = 0; i < x; i++)
	{
		int n = 0, y = 0;
		for (j = 0; j < x; j++)
		{
			if (b[j] == a[i])
			{
				y = y + 1;
			}
		}
		for (j = 0; j < x; j++)
		{
			if (a[i] == a[j])
			{
				n = n + 1;
			}
		}
		if (y == 0)
		{
			b[z] = a[i];
			printf("%c�ַ�������%d��\n", b[z], n);
			z = z + 1;
		}
	}
	system("pause");
	return 0;
}
//21.��Ŀ������һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ���ո����ֺ������ַ��ĸ�����