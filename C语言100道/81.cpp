#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int strCount(char * a, char * b){
	int count = 0;
	for (int i = 0; a[i] != '\0'; i++){
		int j = 0;
		for (j = 0; a[i + j] != '\0'&&b[j] != '\0'; j++){
			if (a[i + j] != b[j])	//�������Ⱦ��˳�ѭ��
			{
				break;
			}
		}
		if (b[j] == '\0')	//���Ӵ�ѭ����������һ��
			count++;
	}
	return count;
}
int main(){
	char a[100];
	char b[100];
	printf("�����������ַ�����\n");
	scanf("%s %s", a, b);
	printf("��������%d��\n", strCount(a, b));
	system("pause");
	return 0;
}
//81.��Ŀ�������ַ������Ӵ����ֵĴ�����