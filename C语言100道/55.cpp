#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_NONSTDC_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>	//����ͼ�ο�
int main()
{
	initgraph(600, 600);	// ��ʼ��ͼ�δ���
	rectangle(100, 100, 400, 400);	//rectangle(x1,y1,x2,y2);����x1, y1, x2, y2��Ϊ���͡������Ĺ������Ե�(x1, y1)Ϊ���ε����Ͻǵ㣬�Ե㣨x2, y2��Ϊ���ε����½ǵ㣬��һ�����Ρ�
	getch();	// �����������
	closegraph();	// �ر�ͼ�ν���
}
//55.��Ŀ����ͼ��ѧ��rectangle�����Ρ�