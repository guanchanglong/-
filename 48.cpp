#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b, c;
	printf("�������������֣�");
	scanf("%d%d", &a,&b);
	c = a;
	a = b;
	b = c;
	printf("%d %d\n", a, b);
	system("pause");
	return 0;
}
//48.��Ŀ����������ֵ������