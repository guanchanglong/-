#define _CRT_SECURE_NO_DEPRECATE 0
/*
* Copyright(C), 2007-2008, XUPT Univ.
* File name: Main_Menu.c
* Description : TTMS 系统主菜单
* Author:   XUPT
* Version:  v.1
* Da
*/
#include <stdio.h>
#include "Account_UI.h"
#include "Main_Menu.h"
#include "Play_UI.h"
#include "Studio_UI.h"
#include "Sale_UI.h"
#include "SalesAnalysis_UI.h"
#include "Schedule_UI.h"
//系统主菜单 
void Main_Menu(void) {
	char choice;
	do {
		printf("\n=======================================================================\n");
		printf("********************** 影院票务管理系统 *************************\n");
		printf("			[S]管理演出厅\n");
		printf("			[P]管理剧目\n");
		printf("			[T]售票\n");
		printf("			[R]退票\n");
		printf("			[Q]查询演出计划\n");
		//printf("			[I]统计销售额\n"); // 统计销售额 
		printf("			[N]统计票房 \n"); //统计票房 
		//printf("			[M]维护个人资料\n"); //维护个人资料 
		printf("			[A]系统用户管理\n"); //系统用户管理 
		printf("			[E]xist.\n");
		printf("\n=======================================================================\n");
		printf("请输入你的选择:");
		fflush(stdin);
		choice = getchar();
		switch (choice) {
		case 'S':
		case 's':
			Studio_UI_MgtEntry();	//放映厅管理
			break;
		case 'P':
		case 'p':
			Play_UI_MgtEntry();	//剧目管理
			break;
		case 'T':
		case 't':
			Sale_UI_MgtEntry();		//售票管理
			break;
		case 'R':
		case 'r':
			Sale_UI_ReturnTicket();
			break;
		case 'Q':
		case 'q':
			Schedule_UI_ListAll();			//查询菜单(1.按照剧目获取演出计划)
			break;
		case 'N':
		case 'n':
			SalesAnalysis_UI_MgtEntry();
			break;
		case 'A':
		case 'a':
			Account_UI_MgtEntry();
			break;
		}
	} while ('E' != choice && 'e' != choice);
}
