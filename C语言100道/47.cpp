#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num=50;
	while (num >= 50)
	{
		printf("����������(��ƽ�������С�� 50 ���˳�):");
		scanf("%d", &num);
		num = num*num;
		printf("�����ֵ�ƽ��Ϊ:%d\n", num);
	}
	system("pause");
	return 0;
}
//47.��Ŀ�����������ֵ�ƽ�������ƽ�������С�� 50 ���˳���