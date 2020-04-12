#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int num1, num2, a[20], b[20], c[20];
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &num2);
	for (int j = 0; j < num2; j++){
		scanf("%d", &b[j]);
	}
	int n = 0, m = 0, k = 0;
	for (int x = 0; x < num1; x++){
		n = 0;
		for (int y = 0; y < num2; y++){
			if (a[x] == b[y]){
				n++;
			}
		}
		if (n == 0){
			k = 0;
			for (int z = 0; z < m; z++){
				if (a[x] == c[z]){
					k++;
				}
			}
			if (k == 0){
				c[m] = a[x];
				m++;
			}
		}
	}
	for (int y = 0; y < num2; y++){
		n = 0;
		for (int x = 0; x < num1; x++){
			if (a[x] == b[y]){
				n++;
			}
		}
		if (n == 0){
			k = 0;
			for (int z = 0; z < m; z++){
				if (b[y] == c[z]){
					k++;
				}
			}
			if (k == 0){
				c[m] = b[y];
				m++;
			}
		}
	}
	for (int x = 0; x < m; x++){
		printf("%d", c[x]);
		if (x != m - 1){
			printf(" ");
		}
	}
	system("pause");
	return 0;
}