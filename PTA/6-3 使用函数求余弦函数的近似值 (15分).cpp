#define _CRT_SECURE_NO_DEPRECATE 0
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
double funcos(double e, double x){
	double n = 0, num = 1, sum = 1, m = 1;
	int i = 2;
	while (num > e){
		n += 2;
		m = n;
		num = pow(x, n);
		while (m != 0){
			num /= m;
			m -= 1;
		}
		if (i % 2 == 0){
			sum -= num;
			i += 1;
		}
		else{
			sum += num;
			i -= 1;
		}
	}
	return sum;
}
int main()
{
	double e, x;
	scanf("%lf %lf", &e, &x);
	printf("cos(%.2f) = %.6f\n", x, funcos(e, x));
	system("pause");
	return 0;
}
