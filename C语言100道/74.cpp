#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[50];
	int k = 0, b[25], f = 0;
	gets(a);
	int i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	for (int j = 0; j < i; j++)
	{
		k = 0;
		for (int l = 0; l < i; l++)
		{
			if (a[j]==a[l])
			{
				k++;
			}
		}
		if (k == 1)
		{
			b[f] = j;
			f++;
		}
	}
	printf("%d\n", b[0]);
	system("pause");
	return 0;
}
//74.��Ŀ������һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��