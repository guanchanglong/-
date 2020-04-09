#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n, num = 0, sum = 0;
	scanf("%d", &n);
	for (int a = 0; a < n; a++){
		for (int b = 0; b < n; b++){
			for (int c = 0; c < n; c++){
				if (a + b + c == n&&(double)(a) / 5 + (double)(b) / 3 + c * 3 == n){
					num++;
					sum += a / 5;
				}
			}
		}
	}
	if (num == 0){
		printf("-1");
	}
	else{
		printf("%d %d", num, sum);
	}
	system("pause");
	return 0;
}