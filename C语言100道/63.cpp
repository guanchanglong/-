#define _CRT_SECURE_NO_DEPRECATE 0
#include <stdio.h>
#include<stdlib.h>
int main()
{
	int a[50], i, n, count, flag = 0;
	scanf("%d", &n);
	count = n;
	for (i = 1; i <= n; i++)
		a[i] = 1;//所有人都在圈内，为1 
	for (i = 1;; i++){
		if (i == n + 1)
			i = 1;//如果i超出了n个人，让他重新回到1 

		if (a[i] != 0)	flag++;
		else	continue;

		if (flag % 3 == 0){
			a[i] = 0;
			count--;
		}

		if (count == 1)//表示只剩下一个人在圈内 
			break;
	}
	for (i = 1; i <= n; i++)
	if (a[i] != 0)
		printf("%d", i);//注意这里是输出i，一开始写的a[i],调试了老半天 
	system("pause");
	return 0;
}
//63.题目：有n个人围成一圈，顺序排号。从第一个人开始报数（从1到3报数），凡报到3的人退出圈子，问最后留下的是原来第几号的那位。