#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	for (i = 1; i < 13; i++)
	{
		if (809 * i == 800 * i + 9 * i && 9*i>=100 && 8*i<100)
		{
			printf("%d\n", i);
			printf("���Ϊ��%d\n", 809 * i);
		}
	}
	system("pause");
	return 0;
}
//75.��Ŀ��809*??=800*??+9*?? ����??�������λ��, 809*??Ϊ��λ����8*??�Ľ��Ϊ��λ����9*??�Ľ��Ϊ3λ������??�������λ������809*??��Ľ����