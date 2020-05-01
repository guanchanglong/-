#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	double v = 0, r, h, Pi = 3.1415926535;
	while (1){
		printf("1-Ball\n");
		printf("2-Cylinder\n");
		printf("3-Cone\n");
		printf("other-Exit\n");
		printf("Please enter your command:\n");
		scanf("%d", &n);
		if (n == 1){
			printf("Please enter the radius:\n");
			scanf("%lf", &r);
			v = Pi*r*r*r * 4 / 3;
			printf("%.2lf\n", v);
		}
		else if (n == 2){
			printf("Please enter the radius and the height:\n");
			scanf("%lf %lf", &r, &h);
			v = Pi*r*r*h;
			printf("%.2lf\n", v);
		}
		else if (n == 3){
			printf("Please enter the radius and the height:\n");
			scanf("%lf %lf", &r, &h);
			v = Pi*r*r*h / 3;
			printf("%.2lf\n", v);
		}
		else{
			break;
		}
	}
	system("pause");
	return 0;
}