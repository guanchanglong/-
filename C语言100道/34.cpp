#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num, sum = 0;
	printf("����������:");
	scanf("%d", &num);
	while (num > 0)
	{
		printf("%d ", num % 10);
		num = num / 10;
		sum++;
	}
	printf("\n����%dλ��\n", sum);
	system("pause");
	return 0;
}
//34.��Ŀ����һ��������5λ����������Ҫ��һ�������Ǽ�λ�������������ӡ����λ���֡�