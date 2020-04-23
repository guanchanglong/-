#define _CRT_SECURE_NO_DEPRECATE 0
#include <stdio.h>
#include<stdlib.h>
double fact(int n){
	double sum = 1;
	for (int i = n; i > 0; i--){
		sum *= i;
	}
	return sum;
}
int main()
{
	int i, n;
	double result;
	scanf("%d", &n);
	for (i = 0; i <= n; i++){
		result = fact(i);
		printf("%d! = %.0f\n", i, result);
	}
	system("pause");
	return 0;
}

/* 你的代码将被嵌在这里 */