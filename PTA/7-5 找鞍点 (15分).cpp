#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	int a[100][100];
	scanf("%d", &n);
	for (int i1 = 0; i1 < n; i1++){
		for (int j = 0; j < n; j++){
			scanf("%d", &a[i1][j]);
		}
	}
	int max = a[0][0], num;
	int min, i2;
	for (i2 = 0; i2 < n; i2++){
		max = 0;
		for (int j = 0; j < n; j++){
			if (max <= a[i2][j]){
				max = a[i2][j];
			}
		}
		for (int h = 0; h < n; h++){
			if (a[i2][h] == max){
				num = h;
			}
		}
		min = max;
		for (int k = 0; k < n; k++){
			if (min>a[k][num]){
				min = 123456;
			}
		}
		if (min == max){
			printf("%d %d", i2, num);
			break;
		}
	}
	if (min == 123456){
		printf("NONE");
	}
	system("pause");
	return 0;
}