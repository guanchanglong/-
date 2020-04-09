#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[10], num, n = 0, m = 0, h = 0, x = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++){
		scanf("%d", &a[i]);
	}
	for (int j = 0; j < num; j++){
		n = 0;
		for (int k = 0; k < num; k++){
			if (a[j] == a[k]){
				n++;
			}
		}
		h = 0;
		m = 0;
		if (n >= 2&&a[j]!=0){
			while (n >= 1){
				if (a[m] == a[j] && h == 0){
					h++;
					n--;
				}
				else if (a[m] == a[j] && h != 0){
					a[m] = 0;
					n--;
				}
				m++;
			}
		}
		if (a[j] != 0){
			x = j;
		}
	}
	for (int i = 0; i < num; i++){
		if (a[i] != 0){
			if (i!=x)
				printf("%d ", a[i]);
			else
				printf("%d", a[i]);
		}
	}
	system("pause");
	return 0;
}