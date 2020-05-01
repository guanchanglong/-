#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n, m, num = 0, sum = 0, x;
	scanf("%d %d", &n, &m);
	x = n;
	while (m != 0){
		num = 0;
		for (int i = 2; i <= n/2; i++){
			if (n%i == 0){
				num++;
			}
		}
		if (num == 0){
			if (n != 1){
				printf("%d", n);
				sum += n;
			}
			if (m != 1&&n!=2){
				printf("+");
			}
			else if(m==1){
				printf("=%d", sum);
			}
			m--;
		}
		n--;
	}
	system("pause");
	return 0;
}