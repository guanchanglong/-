#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int nums[50], target, i = -1;
	printf("��������������(��0����):\n");
	while (nums[i] != 0)
	{
		i++;
		scanf("%d", &nums[i]);
	}
	printf("������Ŀ��ֵ��");
	scanf("%d", &target);
	for (int j = 0; j < i; j++)
	{
		for (int l = j; l < i; l++)
		{
			if (target == nums[j] + nums[l])
			{
				printf("�±�Ϊ��%d %d\n", j, l);
			}
		}
	}
	system("pause");
	return 0;
}
//72.��Ŀ��	����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ�����������������������ǵ������±ꡣ
//			����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ��������������ͬ����Ԫ�ء�