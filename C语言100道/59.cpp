#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_NONSTDC_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include <conio.h>
int main()
{
	initgraph(600,600);
	ellipse(320, 240, 0, 360);
	getch(); // �����������
	closegraph(); // �ر�ͼ�ν���
}
//59.��Ŀ������Բ��