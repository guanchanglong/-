#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_NONSTDC_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include <graphics.h> // ����ͼ�ο�
#include <conio.h>
void main()
{
	initgraph(640, 480); // ��ʼ��ͼ�δ���
	circle(300, 200, 60); // ��Բ��Բ��(100, 100)���뾶 60
	getch(); // �����������
	closegraph(); // �ر�ͼ�ν���
}
//53.��Ŀ����ͼ��ѧ��circle��Բ�Ρ�