#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
typedef struct student{
	int num;
	char name[20];
}stu;
int main(){
	int n;
	scanf("%d", &n);
	stu s[50];
	for (int i = 0; i < n; i++){
		scanf("%d %s", &s[i].num, s[i].name);
	}
	for (int i = 0; i < n; i++){
		for (int j = n-1; j >=0; j--){
			if (s[i].num != s[j].num&&s[i].num!=2&&s[j].num!=2){
				printf("%s %s\n", s[i].name, s[j].name);
				s[i].num = 2;
				s[j].num = 2;
			}
		}
	}
	system("pause");
	return 0;
}