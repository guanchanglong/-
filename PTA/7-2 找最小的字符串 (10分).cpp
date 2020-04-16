#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char a[1000][80];//设大点防止出现段错误
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s", a[i]);
	}
	for (int j = 0; j < n; j++){
		for (int k = j; k < n; k++){
			if (strcmp(a[j], a[k]) > 0){
				strcpy(a[j], a[k]);
			}
		}
	}
	printf("Min is: %s", a[0]);
	system("pause");
	return 0;
}