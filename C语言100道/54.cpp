#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_NONSTDC_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>	//����ͼ�ο�
#include<conio.h>	//"conio.h"ͷ�ļ��ǿ���̨�����������ͷ�ļ�����������ͨ������̨���������������������ĺ��������� �������룬��Ļ�����
int main()
{
	initgraph(600, 600);	// ��ʼ��ͼ�δ���
	line(100, 100, 300, 100);	//line��x1,y1,x2,y2��;����������Ϊһ�����꣬��ʾ��(x1,y1)���ߵ���x2,y2��
	getch();	// �����������
	closegraph();	// �ر�ͼ�ν���
}
//54.��Ŀ����ͼ��ѧ��line��ֱ�ߡ�