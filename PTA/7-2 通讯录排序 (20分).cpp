#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
typedef struct student{
	char name[10];
	int year;
	char number[30];
}s;
int main(){
	int n;
	scanf("%d", &n);
	s stu[10];
	int a[10];
	for (int i = 0; i < n; i++){
		scanf("%s %d %s", stu[i].name, &stu[i].year, stu[i].number);
		a[i] = stu[i].year;
	}
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			if (a[i] > a[j]){
				int m = a[i];
				a[i] = a[j];
				a[j] = m;
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (a[i] == stu[j].year){
				printf("%s %d %s\n", stu[j].name, stu[j].year, stu[j].number);
			}
		}
	}
	system("pause");
	return 0;
}