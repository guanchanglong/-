#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
typedef struct employee{
	char name[10];
	float a;
	float b;
	float c;
	float sum;
}e;
int main(){
	int n;
	scanf("%d", &n);
	e emp[100];
	for (int i = 0; i < n; i++){
		scanf("%s %f %f %f", emp[i].name, &emp[i].a, &emp[i].b, &emp[i].c);
		emp[i].sum = emp[i].a + emp[i].b - emp[i].c;
	}
	for (int j = 0; j < n; j++){
		printf("%s %.2f\n", emp[j].name, emp[j].sum);
	}
	system("pause");
	return 0;
}