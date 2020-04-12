#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n, a[20], x;
	scanf("%d", &n);
	scanf("%d", &x);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int sum = 0;
	for (int j = 0; j < n; j++){
		if (a[j] == x){
			printf("%d", j);
			sum++;
			break;
		}
	}
	if (sum == 0){
		printf("Not Found");
	}
	system("pause");
	return 0;
}