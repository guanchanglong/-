#define _CRT_SECURE_NO_DEPRECATE 0
#include <stdio.h>
#include<stdlib.h>
int  fun(int  *p, int  n, int  x){
	for (int i = 0; i < n; i++){
		if (p[i] == x){
			return i;
		}
	}
	return -1;
}
int main()
{
	int  a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, x, k;
	scanf("%d", &x);
	k = fun(a, 10, x);
	if (k >= 0)  printf("%d\n", k);
	else  printf("no\n");
	return 0;
}