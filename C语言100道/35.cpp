#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num, a[5], n = 0;
	printf("������һ����λ���֣�");
	scanf("%d", &num);
	for (int i = 0; i < 5; i++)
	{
		a[i] = num % 10;
		num /= 10;
	}
	if (a[0] == a[4])
		n++;
	if (a[1] == a[3])
		n++;
	if (n == 2)
		printf("����Ϊ������\n");
	else
		printf("�����ǻ�����\n");
	system("pause");
	return 0;
}
//35.��Ŀ��һ��5λ�����ж����ǲ��ǻ���������12321�ǻ���������λ����λ��ͬ��ʮλ��ǧλ��ͬ