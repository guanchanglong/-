#define _CRT_SECURE_NO_DEPRECATE 0
#include <stdio.h>
#include<stdlib.h>
int main()
{
	int a[50], i, n, count, flag = 0;
	scanf("%d", &n);
	count = n;
	for (i = 1; i <= n; i++)
		a[i] = 1;//�����˶���Ȧ�ڣ�Ϊ1 
	for (i = 1;; i++){
		if (i == n + 1)
			i = 1;//���i������n���ˣ��������»ص�1 

		if (a[i] != 0)	flag++;
		else	continue;

		if (flag % 3 == 0){
			a[i] = 0;
			count--;
		}

		if (count == 1)//��ʾֻʣ��һ������Ȧ�� 
			break;
	}
	for (i = 1; i <= n; i++)
	if (a[i] != 0)
		printf("%d", i);//ע�����������i��һ��ʼд��a[i],�������ϰ��� 
	system("pause");
	return 0;
}
//63.��Ŀ����n����Χ��һȦ��˳���źš��ӵ�һ���˿�ʼ��������1��3��������������3�����˳�Ȧ�ӣ���������µ���ԭ���ڼ��ŵ���λ��