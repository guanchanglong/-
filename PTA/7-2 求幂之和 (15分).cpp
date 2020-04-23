#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		sum += pow(2, (double)(i));
	}
	printf("result = %d\n", sum);
	system("pause");
	return 0;
}