#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	char x;
	scanf("%d", &n);
	x = (n >= 90) ? 'A' : ((n > 60 && n < 89) ? 'B' : ((n<60) ? 'C' : '0'));
	printf("%c", x);
	system("pause");
	return 0;
}
//17.��Ŀ�����������������Ƕ������ɴ��⣺ѧϰ�ɼ� >= 90�ֵ�ͬѧ��A��ʾ��60 - 89��֮�����B��ʾ��60�����µ���C��ʾ��