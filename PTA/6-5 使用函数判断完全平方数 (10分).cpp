#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int IsSquare(int n){
	int i = 0, j = 0;
	if (n == 1 || n == 0){
		j++;
		return 1;
	}
	while (i<n/2){
		if (i*i == n){
			j++;
			return 1;
		}
		i++;
	}
	if (j == 0){
		return 0;
	}
}
int main(){
	int n;
	scanf("%d", &n);
	if (IsSquare(n)) printf("YES\n");
	else printf("NO\n");
	system("pause");
	return 0;
}