#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num, i = 0, sum[100], j = 0;
	for (i = 0; i < 100000; i++)
	{
		num = i;
		if (num % 5 == 1)
		{
			num = num - num / 5 - 1;	//1
			if (num % 5 == 1)
			{
				num = num - num / 5 - 1;	//2
				if (num % 5 == 1)
				{
					num = num - num / 5 - 1;	//3
					if (num % 5 == 1)
					{
						num = num - num / 5 - 1;	//4
						if (num % 5 == 1)
						{
							num = num - num / 5 - 1;	//5
							if (num != 0)
							{
								sum[j] = i;
								j++;
							}
						}
					}
				}
			}
		}
	}
	printf("��ԭ��ɳ̲��������%d������\n", sum[0]);
	system("pause");
	return 0;
}
//73.��Ŀ��	��̲����һ�����ӣ���ֻ�������֡�
//			��һֻ���Ӱ��������ƽ����Ϊ��ݣ�����һ������ֻ���ӰѶ��һ�����뺣�У�������һ�ݡ�
//			�ڶ�ֻ���Ӱ�ʣ�µ�������ƽ���ֳ���ݣ��ֶ���һ������ͬ���Ѷ��һ�����뺣�У�������һ�ݣ�
//			���������ġ�����ֻ���Ӷ����������ģ��ʺ�̲��ԭ�������ж��ٸ����ӣ�