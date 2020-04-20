#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int m, n;
	int a[10][10];
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	int sum = 0;
	for (int i = 0; i < m; i++){
		sum = 0;
		for (int j = 0; j < n; j++){
			sum += a[i][j];
		}
		printf("%d\n", sum);
	}
	system("pause");
	return 0;
}