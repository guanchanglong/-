#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[2] = { 0, 0 };
	printf("�������������֣�");
	for (int i = 0; i < 2; i++)
	{
		scanf("%d", &a[i]);
	}
	if (a[0]>a[1])
	{
		printf("����%d�Ƚϴ�\n", a[0]);
	}
	else
	{
		printf("����%d�Ƚϴ�\n", a[1]);
	}
	system("pause");
	return 0;
}
//51.��Ŀ�����ֱȽϡ�