#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int num, a[1000], sum = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < num; i++){
		for (int j = i; j < num; j++){
			if (a[i]>=a[j]){
				int n = a[i];
				a[i] = a[j];
				a[j] = n;
			}
		}
	}
	int m = a[0], x = 0, y = 0;
	if (num>1){
		for (int i = 0; i < num; i++){
			if (m == a[i]){
				sum++;
				if (i == num - 1 && x < sum){
					x = sum;
					y = a[i - 1];
				}
			}
			if(m!=a[i]){
				m = a[i];
				if (x < sum){
					x = sum;
					y = a[i - 1];
				}
				sum = 1;
			}
			if (sum == num){
				y = a[0];
				x = num;
			}
		}
	}
	else{
		y = a[0];
		x = 1;
	}
	printf("%d %d\n", y, x);
	system("pause");
	return 0;
}
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int i, j, t, k, b, n;
//	scanf("%d", &n);
//	int a[1000];
//	for (i = 0; i<n; i++)
//		scanf("%d", &a[i]);
//	for (i = 0; i<n - 1; i++)//ÏÈÅÅÐò 
//		for (j = 0; j<n - 1 - i; j++)
//			if (a[j]<a[j + 1])
//			{
//				t = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = t;
//			}
//	k = 0, j = 0, t = a[0];
//	for (i = 0; i<n; i++)
//	{
//		if (t == a[i])
//			j++;
//		else
//		{
//			t = a[i];
//			if (k<j)
//			{
//				k = j;
//				b = t;
//			}
//			j = 1;
//		}
//	}
//	printf("%d %d", b, k);
//	system("pause");
//	return 0;
//}