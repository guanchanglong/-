#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_NONSTDC_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>	//引用图形库
#include<conio.h>	//"conio.h"头文件是控制台输入输出函数头文件。它定义了通过控制台进行数据输入和数据输出的函数，例如 键盘输入，屏幕输出。
int main()
{
	initgraph(600, 600);	// 初始化图形窗口
	line(100, 100, 300, 100);	//line（x1,y1,x2,y2）;其中两个数为一个坐标，表示从(x1,y1)画线到（x2,y2）
	getch();	// 按任意键继续
	closegraph();	// 关闭图形界面
}
//54.题目：画图，学用line画直线。