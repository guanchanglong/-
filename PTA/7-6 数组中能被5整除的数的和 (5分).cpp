#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[10], sum = 0;
	for (int i = 0; i < 10; i++){
		scanf("%d", &a[i]);
	}
	for (int j = 0; j < 10; j++){
		if (a[j] % 5 == 0){
			sum += a[j];
		}
	}
	printf("%d", sum);
	system("pause");
	return 0;
}