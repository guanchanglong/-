#define _CRT_SECURE_NO_DEPRECATE 0
#include "stdio.h"
#include "string.h"
#include<stdlib.h>
int fun(char a[], char b[]){
	if (strcmp(a,b)==0){
		return 0;
	}
	else if (strcmp(a,b)>0){
		return 1;
	}
	else if (strcmp(a,b)<0){
		return -1;
	}
}
int  main()
{
	int t;
	char s1[40], s2[40];
	gets(s1);  gets(s2);
	t = fun(s1, s2);
	printf("%d\n", t);
	system("pause");
	return 0;
}