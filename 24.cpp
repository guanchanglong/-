#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	float i, n = 100, x = 0;
	for (i = 0; i < 10; i++)
	{
		x = x + n * 2;
		n = n / 2;
	}
	printf("������%.1f�ף���ʮ�η���%.1f�׸�\n", (x-100-n), n);
	system("pause");
	return 0;
}
//24.��Ŀ��һ���100�׸߶��������£�ÿ����غ�����ԭ�߶ȵ�һ�룻�����£������ڵ�10�����ʱ�������������ף���10�η�����ߣ�