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
	getch(); // 按任意键继续
	closegraph(); // 关闭图形界面
}
//59.题目：画椭圆。