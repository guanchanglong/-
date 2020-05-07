#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int hh, mm, ss, n;
	scanf("%d:%d:%d", &hh, &mm, &ss);
	scanf("%d", &n);
	ss = ss + n;
	if (ss >= 60){
		mm = mm + 1;
		if (mm >= 60){
			hh = hh + 1;
		}
	}
	if (hh < 10){
		printf("0%d:", hh);
		if (mm%60 < 10){
			printf("0%d:", mm%60);
			if (ss%60 < 10){
				printf("0%d", ss%60);
			}
			else{
				printf("%d", ss%60);
			}
		}
		else{
			printf("%d:", mm%60);
			if (ss%60 < 10){
				printf("0%d", ss%60);
			}
			else{
				printf("%d", ss%60);
			}
		}
	}
	else if(hh>10&&hh!=24){
		printf("%d:", hh);
		if (mm%60 < 10){
			printf("0%d:", mm%60);
			if (ss%60 < 10){
				printf("0%d", ss%60);
			}
			else{
				printf("%d", ss%60);
			}
		}
		else{
			printf("%d:", mm%60);
			if (ss%60 < 10){
				printf("0%d", ss%60);
			}
			else{
				printf("%d", ss%60);
			}
		}
	}
	else if (hh==24){
		printf("00:");
		if (mm % 60 < 10){
			printf("0%d:", mm % 60);
			if (ss % 60 < 10){
				printf("0%d", ss % 60);
			}
			else{
				printf("%d", ss % 60);
			}
		}
		else{
			printf("%d:", mm % 60);
			if (ss % 60 < 10){
				printf("0%d", ss % 60);
			}
			else{
				printf("%d", ss % 60);
			}
		}
	}
	system("pause");
	return 0;
}