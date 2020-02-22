#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int strCount(char * a, char * b){
	int count = 0;
	for (int i = 0; a[i] != '\0'; i++){
		int j = 0;
		for (j = 0; a[i + j] != '\0'&&b[j] != '\0'; j++){
			if (a[i + j] != b[j])	//如果不相等就退出循环
			{
				break;
			}
		}
		if (b[j] == '\0')	//当子串循环完后算出现一次
			count++;
	}
	return count;
}
int main(){
	char a[100];
	char b[100];
	printf("请输入两个字符串：\n");
	scanf("%s %s", a, b);
	printf("共出现了%d次\n", strCount(a, b));
	system("pause");
	return 0;
}
//81.题目：计算字符串中子串出现的次数。