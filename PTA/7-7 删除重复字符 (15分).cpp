#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	char a[80];
	gets(a);
	int i = 0;
	while (a[i] != '\0'){
		i++;
	}
	for (int x = 0; x < i; x++){
		for (int y = x; y < i; y++){
			if (a[x] > a[y]){
				char b = a[x];
				a[x] = a[y];
				a[y] = b;
			}
		}
	}
	char c[80];
	c[0] = a[0];
	int z = 1;
	for (int x = 1; x < i; x++){
		if (a[x-1] != a[x]){
			c[z] = a[x];
			z++;
		}
	}
	for (int j = 0; j < z; j++){
		printf("%c", c[j]);
	}
	system("pause");
	return 0;
}