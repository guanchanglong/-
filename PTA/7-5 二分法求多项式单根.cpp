#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
double  a0, a1, a2, a3;
double target(double n){
	double f;
	f = a3*(n*n*n) + a2*(n*n) + a1*n + a0;
	return f;
}
int main(){
	double  a, b;
	int i = 0;
	scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
	scanf("%lf %lf", &a, &b);
	double f1, f2, n, f;
	f1 = target(a);
	f2 = target(b);
	if (f1*f2 < 0){
		n = (a + b) / 2;
		f = target(n);
		while (1){
			i++;
			if (f == 0){
				printf("%.2lf", n);
				break;
			}
			if (i == 100){
				printf("%.2lf", n);
				break;
			}
			else if (f*f1 < 0){
				b = n;
				n = (n + a) / 2;
			}
			else if (f*f2 < 0){
				a = n;
				n = (n + b) / 2;
			}
			f = target(n);
		}
	}
	else if (f1 == 0){
		printf("%.2lf", a);
	}
	else if (f2 == 0){
		printf("%.2lf", b);
	}
	system("pause");
	return 0;
}