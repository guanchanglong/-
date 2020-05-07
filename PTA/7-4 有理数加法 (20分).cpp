#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int a1, b1, a2, b2;
	int a, b;
	scanf("%d/%d %d/%d", &a1,&b1,&a2, &b2);
	a = a1*b2 + a2*b1;
	b = b1*b2;
	int n;
	if (a > b){
		n = a;
	}
	else{
		n = b;
	}
	while (1){
		if (a%n == 0 && b%n == 0){
			a = a / n;
			b = b / n;
		}
		if (n<=1){
			break;
		}
		n--;
	}
	if (a%b == 0) 
		printf("%d", a / b);
	else if (a%b != 0 && b != 0) 
		printf("%d/%d", a, b);
	system("pause");
	return 0;
}