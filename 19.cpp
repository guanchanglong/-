#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	unsigned int n;
	scanf("%d", &n);
	int len = sizeof(n)* 8;
	int num;
	printf("ԭ��    ");
	for (int i = 0; i <len; i++)
	{
		num = n;
		num = num >> (31 - i);//������λ
		int t = num & 1;//����λ���㣬����λ��Ϊ0����t=0����Ϊ1����Ϊt=1
		printf("%d", t);
	}
	printf("\n");
	printf("�ߵ���");
	for (int i = 31; i >= 0; i--)
	{
		num = n;
		num = num >> (31 - i);
		int t = num & 1;
		printf("%d", t);
	}
	printf("\n");
	system("pause");
	return 0;
}
//19.��Ŀ���ߵ������� 32 λ�޷��������Ķ�����λ��