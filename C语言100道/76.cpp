#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long i = 7, sum = 0;
	long long num = 4;
	sum += num;
	num = num * 6;
	while (i >0)
	{
		sum += num;
		i = i - 1;
		num = num*i;
	}
	printf("%lld\n", sum);
	system("pause");
	return 0;
}
//���1λ����4����
//���2λ����6*4����
//���3λ����6*6*4����
//���4λ����6*6*5*4����
//���5λ����6*6*5*4*4����
//���6λ����6*6*5*4*3*4����
//���7λ����6*6*5*4*3*2*4����
//���8λ����6*6*5*4*3*2*1*4����
//76.��Ŀ����0��7������ɵ�����������