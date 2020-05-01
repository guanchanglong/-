#define _CRT_SECURE_NO_DEPRECATE 0
#include <stdio.h>
#include<stdlib.h>
int Ack(int m, int n){
	if (m == 0){
		return n + 1;
	}
	else if (n == 0 && m > 0){
		Ack(m - 1, 1);
	}
	else if (n > 0 && m > 0){
		Ack(m - 1, Ack(m, n - 1));
	}
}
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	printf("%d\n", Ack(m, n));
	system("pause");
	return 0;
}