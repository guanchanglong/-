#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char a[100];
	int i = 0;
	printf("�����볤��С��100���ַ�����");
	gets(a);
	while (a[i] != '\0')
	{
		i++;
	}
	printf("���ַ�������Ϊ��%d\n", i);
	system("pause");
	return 0;
}
//56.��Ŀ�������ַ������ȡ���