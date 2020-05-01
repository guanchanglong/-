#define _CRT_SECURE_NO_DEPRECATE 0
#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int indexOfMax(int *array, int size){
	int n = array[0];
	for (int i = 1; i < size; i++){
		if (n < array[i]){
			n = array[i];
		}
	}
	for (int j = 0; j < size; j++){
		if (n == array[j]){
			return j;
		}
	}
}
int main(){
	int num[MAXSIZE];
	int total;
	scanf("%d", &total);
	for (int i = 0; i<total; i++) scanf("%d", &num[i]);
	printf("%d\n", num[indexOfMax(num, total)]);
	system("pause");
	return 0;
}
