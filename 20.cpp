#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d", &n);
	if (n % 3 == 0 && n % 5 == 0)
	{
		printf("FizzBuzz\n");
	}
	else if (n % 3 == 0)
	{
		printf("Fizz\n");
	}
	else if (n % 5 == 0)
	{
		printf("Buzz\n");
	}
	system("pause");
	return 0;
}
//20.��Ŀ�� дһ����������� 1 �� n ���ֵ��ַ�����ʾ��
//			1.��� n ��3�ı����������Fizz����
//			2.��� n ��5�ı����������Buzz����
//			3.��� n ͬʱ��3��5�ı�������� ��FizzBuzz����