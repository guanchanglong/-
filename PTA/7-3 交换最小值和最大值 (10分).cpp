#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[10], num, min, max;
	scanf("%d", &num);
	for (int i = 0; i < num; i++){
		scanf("%d", &a[i]);
	}
	min = a[0];
	max = a[0];
	for (int j = 0; j < num; j++){
		if (min>a[j]){
			min = a[j];
		}
		if (max < a[j]){
			max = a[j];
		}
	}
	for (int k = 0; k < num; k++){
		if (a[k] == min){
			a[k] = a[0];
			a[0] = min;
			break;
		}
	}
	for (int l = 0; l < num; l++){
		if (a[l] == max){
			a[l] = a[num-1];
			a[num-1] = max;
			break;
		}
	}
	for (int h = 0; h < num; h++){
		printf("%d ", a[h]);
	}
	system("pause");
	return 0;
}