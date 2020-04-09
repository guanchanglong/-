#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[10], num, max;
	scanf("%d", &num);
	for (int i = 0; i < num; i++){
		scanf("%d", &a[i]);
	}
	max = a[0];
	for (int j = 0; j < num; j++){
		if (max<a[j]){
			max = a[j];
		}
	}
	for (int k = 0; k < num; k++){
		if (a[k] == max){
			printf("%d %d", max,k);
			break;
		}
	}
	system("pause");
	return 0;
}