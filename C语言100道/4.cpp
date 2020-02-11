#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
int main()
{
	int nian, yue, ri;
	printf("请输入年月日\n");
	scanf("%d%d%d", &nian, &yue, &ri);
	switch (yue)
	{
	case 1:
		break;
	case 2:
		ri = 31 + ri;
		break;
	case 3:
		ri = 31 + 28 + ri;
		break;
	case 4:
		ri = 31 * 2 + 28 + ri;
		break;
	case 5:
		ri = 31 * 2 + 28 + 30 + ri;
		break;
	case 6:
		ri = 31 * 3 + 30 + 28 + ri;
		break;
	case 7:
		ri = 31 * 3 + 30 * 2 + 28 + ri;
		break;
	case 8:
		ri = 31 * 4 + 30 * 2 + 28 + ri;
		break;
	case 9:
		ri = 31 * 5 + 30 * 2 + 28 + ri;
		break;
	case 10:
		ri = 31 * 5 + 30 * 3 + 28 + ri;
		break;
	case 11:
		ri = 31 * 6 + 30 * 3 + 28 + ri;
		break;
	case 12:
		ri = 31 * 6 + 30 * 4 + 28 + ri;
		break;
	}
	if (nian % 4 == 0 && nian % 100 != 0)
	{
		printf("是%d的第%d天\n", nian, (ri+1));
	}
	else
	{
		printf("是%d的第%d天\n", nian, ri);
	}
	return 0;
}