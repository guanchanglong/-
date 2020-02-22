#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int nums[10], i = 0, j = 0, n = 9, a = 0;
	printf("请输入十位数组：");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &nums[i]);
	}
	for (i = 0; i < 10; i++)
	{
		if (nums[i] == 0)
		{
			a++;
		}
	}
	for (i = 0; i < 10; i++)
	{
		if (n<=9-a)
		{
			break;
		}
		if (nums[i] == 0&&nums[n]!=0)
		{
			int num = nums[n];
			nums[n] = nums[i];
			nums[i] = num;
			n--;
		}
		if (nums[i] == 0 && nums[n] == 0)
		{
			n--;
			i--;
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = i; j < 10; j++)
		{
			if (nums[i]>nums[j]&&nums[j]!=0&&nums[i]!=0)
			{
				int num = nums[j];
				nums[j] = nums[i];
				nums[i] = num;
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
//79.题目：给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。