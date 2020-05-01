#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int reverse(int n){
	int m = 0;
	while (n != 0){
		m += n % 10;
		n = n / 10;
		m = m * 10;
	}
	return m/10;
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", reverse(n));
	system("pause");
	return 0;
}