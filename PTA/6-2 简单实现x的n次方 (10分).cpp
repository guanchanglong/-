#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
double mypow(double x, int n){
	double y = x;
	for (int i = 0; i<n-1; i++){
		x *= y;
	}
	return x;
}
int main(){
	double x;
	int n;
	scanf("%lf %d", &x, &n);
	printf("%f", mypow(x, n));
	system("pause");
	return 0;
}