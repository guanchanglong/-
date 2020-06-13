#define _CRT_SECURE_NO_DEPRECATE 0
/*
* Copyright(C), 2007-2008, XUPT Univ.
* File name: Main_Menu.c
* Description : TTMS ϵͳ���˵�
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
//ϵͳ���˵� 
void Main_Menu(void) {
	char choice;
	do {
		printf("\n=======================================================================\n");
		printf("********************** ӰԺƱ�����ϵͳ *************************\n");
		printf("			[S]�����ݳ���\n");
		printf("			[P]�����Ŀ\n");
		printf("			[T]��Ʊ\n");
		printf("			[R]��Ʊ\n");
		printf("			[Q]��ѯ�ݳ��ƻ�\n");
		//printf("			[I]ͳ�����۶�\n"); // ͳ�����۶� 
		printf("			[N]ͳ��Ʊ�� \n"); //ͳ��Ʊ�� 
		//printf("			[M]ά����������\n"); //ά���������� 
		printf("			[A]ϵͳ�û�����\n"); //ϵͳ�û����� 
		printf("			[E]xist.\n");
		printf("\n=======================================================================\n");
		printf("���������ѡ��:");
		fflush(stdin);
		choice = getchar();
		switch (choice) {
		case 'S':
		case 's':
			Studio_UI_MgtEntry();	//��ӳ������
			break;
		case 'P':
		case 'p':
			Play_UI_MgtEntry();	//��Ŀ����
			break;
		case 'T':
		case 't':
			Sale_UI_MgtEntry();		//��Ʊ����
			break;
		case 'R':
		case 'r':
			Sale_UI_ReturnTicket();
			break;
		case 'Q':
		case 'q':
			Schedule_UI_ListAll();			//��ѯ�˵�(1.���վ�Ŀ��ȡ�ݳ��ƻ�)
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
