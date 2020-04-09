#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[10], num, n, x = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &n);
	for (int j = 0; j < num; j++){
		if (n <= a[j]&&x==0){
			printf("%d ", n);
			j--;
			x++;
		}
		else if (n >= a[j] && x == 0&&j==num-1){
			printf("%d ", a[j]);
			printf("%d ", n);
			x++;
		}
		else{
			printf("%d ", a[j]);
		}
	}
	if (num == 0){
		printf("%d ", n);
	}
	system("pause");
	return 0;
}