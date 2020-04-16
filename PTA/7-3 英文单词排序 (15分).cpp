#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int length(char a[100]){
	int i = 0;
	while (a[i] != '\0'){
		i++;
	}
	return i;
}
int main(){
	char a[100][100];
	int b[100], c[100];
	int i = 0;
	scanf("%s", a[i]);
	while (a[i][0]!='#'){
		i++;
		scanf("%s", a[i]);
	}
	for (int j = 0; j < i; j++){
		b[j] = length(a[j]);
	}
	for (int x = 0; x <i; x++){
		for (int y = x; y < i; y++){
			if (b[x] > b[y]){
				int num = b[x];
				b[x] = b[y];
				b[y] = num;
			}
		}
	}
	c[0] = b[0];
	int len = 1;
	for (int x = 1; x < i; x++){
		if (b[x - 1] != b[x]){
			c[len] = b[x];
			len++;
		}
	}
	for (int x = 0; x < i; x++){
		for (int y = 0; y < i; y++){
			if (c[x] == length(a[y])){
				printf("%s ", a[y]);
			}
		}
	}
	system("pause");
	return 0;
}