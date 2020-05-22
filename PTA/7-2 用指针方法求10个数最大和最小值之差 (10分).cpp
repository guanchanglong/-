#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[10];
	for (int i = 0; i < 10; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 10; i++){
		for (int j = i; j < 10; j++){
			if (a[i]>a[j]){
				int num = a[i];
				a[i] = a[j];
				a[j] = num;
			}
		}
	}
	printf("difference value = %d", a[9] - a[0]);
	system("pause");
	return 0;
}