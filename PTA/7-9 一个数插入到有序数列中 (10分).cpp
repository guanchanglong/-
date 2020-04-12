#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n, a[100], target;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &target);
	int m = 0;
	for (int j = 0; j < n; j++){
		if (a[j]>target){
			printf("%3d", a[j]);
		}
		else if(a[j]<=target&&m==0){
			printf("%3d", target);
			m++;
			j--;
		}
		else{
			printf("%3d", a[j]);
		}
		if (j == (n - 1) && m == 0){
			printf("%3d", target);
		}
	}
	system("pause");
	return 0;
}
//  7  6  4  3  2  1 
