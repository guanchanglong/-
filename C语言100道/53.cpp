#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_NONSTDC_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include <graphics.h> // 引用图形库
#include <conio.h>
void main()
{
	initgraph(640, 480); // 初始化图形窗口
	circle(300, 200, 60); // 画圆，圆心(100, 100)，半径 60
	getch(); // 按任意键继续
	closegraph(); // 关闭图形界面
}
//53.题目：画图，学用circle画圆形。