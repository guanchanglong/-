#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int year = 10;
	for (int i = 0; i < 4; i++)
	{
		year += 2;
	}
	printf("�������Ϊ%d��", year);
	system("pause");
	return 0;
}
//33.��Ŀ��	��5��������һ���ʵ�����˶����ꣿ��˵�ȵ�4���˴�2�ꡣ
//			�ʵ�4������������˵�ȵ�3���˴�2�ꡣ
//			�ʵ������ˣ���˵�ȵ�2�˴����ꡣ
//			�ʵ�2���ˣ�˵�ȵ�һ���˴����ꡣ
//			����ʵ�һ���ˣ���˵��10�ꡣ���ʵ�����˶��