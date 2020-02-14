#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_NONSTDC_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>	//引用图形库
int main()
{
	initgraph(600, 600);	// 初始化图形窗口
	rectangle(100, 100, 400, 400);	//rectangle(x1,y1,x2,y2);参数x1, y1, x2, y2均为整型。函数的功能是以点(x1, y1)为矩形的左上角点，以点（x2, y2）为矩形的右下角点，画一个矩形。
	getch();	// 按任意键继续
	closegraph();	// 关闭图形界面
}
//55.题目：画图，学用rectangle画方形。