#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[100][100], b[100][100];
	int c[100][100] = { 0 };
	int a1, a2;
	int b1, b2;
	int i, j, k;
	scanf("%d %d", &a1, &a2);
	for (i = 0; i < a1; i++)
		for (j = 0; j < a2; j++)
			scanf("%d", &a[i][j]);      
	scanf("%d %d", &b1, &b2);
	for (i = 0; i < b1; i++)
		for (j = 0; j < b2; j++)
			scanf("%d", &b[i][j]); 
	if (a2 != b1){
		printf("Error: %d != %d", a2, b1);
	}
	else
	{
		for (i = 0; i < a1; i++){
			for (j = 0; j < b2; j++){
				for (k = 0; k < a2; k++){
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		printf("%d %d\n", a1, b2);
		for (i = 0; i < a1; i++)
		{
			for (j = 0; j < b2; j++){
				printf("%d", c[i][j]);
				if (j != b2 - 1){
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}
