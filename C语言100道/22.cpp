#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, x, y;
	scanf("%d", &a);
	long long s = a;
	x = a;
	y = a;
	for (int i = 1; i < x; i++)
	{
		y = y * 10;
		a = a + y;
		s = s + a;
	}
	printf("%lld", s);
	system("pause");
	return 0;
}
//22.��Ŀ����s=a+aa+aaa+aaaa+aa...a��ֵ������a��һ�����֡�����2+22+222+2222+22222(��ʱ����5�������)������������ɼ��̿��ơ�