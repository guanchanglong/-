#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int nums[50], target, i = -1;
	printf("请输入整数数组(以0结束):\n");
	while (nums[i] != 0)
	{
		i++;
		scanf("%d", &nums[i]);
	}
	printf("请输入目标值：");
	scanf("%d", &target);
	for (int j = 0; j < i; j++)
	{
		for (int l = j; l < i; l++)
		{
			if (target == nums[j] + nums[l])
			{
				printf("下标为：%d %d\n", j, l);
			}
		}
	}
	system("pause");
	return 0;
}
//72.题目：	给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
//			你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。