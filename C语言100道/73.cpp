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
	printf("故原来沙滩上最少有%d个桃子\n", sum[0]);
	system("pause");
	return 0;
}
//73.题目：	海滩上有一堆桃子，五只猴子来分。
//			第一只猴子把这堆桃子平均分为五份，多了一个，这只猴子把多的一个扔入海中，拿走了一份。
//			第二只猴子把剩下的桃子又平均分成五份，又多了一个，它同样把多的一个扔入海中，拿走了一份，
//			第三、第四、第五只猴子都是这样做的，问海滩上原来最少有多少个桃子？