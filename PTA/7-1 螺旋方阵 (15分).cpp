#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d", &n);
	int a[10][10];
	int m = 1;
	int tier;//����
	int up, down, left, right;//��������
	int x = 0, i, j;
	for (tier = 0; tier<n / 2 + 1; tier++){
		x = n - 2 * tier - 1;
		for (right = 0; right<x; right++){//�Ҳ���
			a[tier][tier + right] = m;
			m++;
		}
		for (down = 0; down<x; down++){//�²���
			a[tier + down][right + tier] = m;
			m++;
		}
		for (left = 0; left<x; left++){//�����
			a[tier + down][right + tier - left] = m;
			m++;
		}
		for (up = 0; up<x; up++){//�ϲ���
			a[tier + down - up][right + tier - left] = m;
			m++;
		}
	}

	if (n % 2 != 0){//���ĵ�
		a[n / 2][n / 2] = n*n;
	}
	for (i = 0; i<n; i++){
		for (j = 0; j<n; j++){
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
