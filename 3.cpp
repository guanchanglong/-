#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<math.h>
int main()
{
	int i;
	for (i = 1; i < 10000; i++)
	{
		if (sqrt(float(i + 100)) == floor(sqrt(float(i + 100))+0.5) && sqrt(float(i + 268)) == floor(sqrt(float(i + 268))+0.5))//floor��������������ȡ������floor(1.5)=1
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
//��Ŀ��һ��������������100����һ����ȫƽ�������ټ���168����һ����ȫƽ���������ʸ����Ƕ��٣�