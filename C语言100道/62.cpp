#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int a[15], i = 0, j = 0, k, b[15];
	printf("������15������:");
	for (i = 0; i < 15; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	printf("�������ƶ�λ��:");
	scanf("%d", &k);
	for (i = 0; i < 15; i++)
	{
		a[(i + k) % 15] = b[i];
	}
	printf("���:");
	for (i = 0; i < 15; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
//62. ��Ŀ����n��������ʹ��ǰ�����˳�������m��λ�ã����m���������ǰ���m����
