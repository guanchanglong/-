#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, a = 1, sum = 0, num[4];
	printf("������(��λ)���ݣ�");
	scanf("%d", &n);
	for (int i = 0; i < 4; i++)
	{
		a = 10;
		n = n / a;
		num[i] = (n%a + 5) % 10;
	}
	sum = num[0];
	num[0] = num[3];
	num[3] = sum;
	sum = num[1];
	num[1] = num[2];
	num[2] = sum;
	sum = 0;
	a = 1;
	for (int j = 0; j < 4; j++)
	{
		sum += num[j] * a;
		a *= 10;
	}
	printf("���ܺ�%d\n", sum);
	system("pause");
	return 0;
}
//80.��Ŀ��	ĳ����˾���ù��õ绰�������ݣ���������λ���������ڴ��ݹ������Ǽ��ܵ�.
//			���ܹ������£�ÿλ���ֶ�����5,Ȼ���úͳ���10��������������֣��ٽ���һλ�͵���λ�������ڶ�λ�͵���λ������