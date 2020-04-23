#define _CRT_SECURE_NO_DEPRECATE 0
#include <stdio.h>
#include<stdlib.h>
int i = 0;
void printdigits(int n){
	if (n != 0){
		i++;
		printdigits(n / 10);
		printf("%d\n", n % 10);
	}
	else if (n == 0 && i == 0){
		printf("0");
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	printdigits(n);
	system("pause");
	return 0;
}