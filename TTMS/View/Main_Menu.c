#include <stdio.h>
#include "Main_Menu.h"
#include "Studio_UI.h"
#include "Account.h"	
#include "Queries_Menu.h"
#include "Query_Play_UI.h"
#include "Sale_UI.h"
#include "Play_UI.h"
#include "SalesAnalysis_UI.h"
#include "Play_UI.h"	
#include "conio.h"
#include "Ticket_UI.h" 
#include "Play_Persist.h" 

void Main_Menu(account_t usr)
{
	char choice;
	char ch[30];
	int sal_id;
	play_t buf;
	schedule_t buf2;
	play_list_t list;
	
	switch (usr.type)
	{
	case 1:
		do {
            system("cls");
			printf("\n\n\n\n\n\n\n\t\t\t\t\t��ƱԱ����,��ѡ��\n\n"); 
			printf("\t\t\t\t\t  [1]\t��Ʊ����Ʊ\n\n");
			printf("\t\t\t\t\t  [2]\t��ѯ�ݳ�Ʊ\n\n");
			printf("\t\t\t\t\t  [3]\t��ѯ�ݳ�\n\n");
			printf("\t\t\t\t\t  [4]\tͳ�����۶�\n\n");
			printf("\t\t\t\t\t  [5]\tά����������\n\n");
			printf("\t\t\t\t\t  [6]\t�˳�ϵͳ\n\n");
			printf("\n\t\t\t\t\t:");
			choice = getche();
			switch (choice) {
			case '3':
				Schedule_UI_ListAll();
				break;
			case '5':
				Account_UI_MgtEntry();
				break;
			case '2':
				printf("\n\t\t\t\t\t�ݳ��ƻ�ID:");
				scanf("%d", &sal_id);
				getchar();
				if (!Schedule_Srv_FetchByID(sal_id, &buf2))
				{
					printf("\t\t\t\t\t�ݳ��ƻ�������,���������");
					getch();
				}
				else
				{
					Sale_UI_ShowTicket2(sal_id);
				}
				break;
			case '1':
				Sale_UI_MgtEntry();
				break;
			case '4':
				SalesAanalysis_UI_MgtEntry();
				break;
			}
		} while ('6' != choice);
	
		break;
	case 2:
		do {
            system("cls");
			printf("\n\n\n\n\n\n\n\t\t\t\t\t��������,��ѡ��\n\n"); 
			printf("\t\t\t\t\t  [1]\t�����Ŀ\n\n");
			printf("\t\t\t\t\t  [2]\t��ѯ�ݳ�\n\n");
			printf("\t\t\t\t\t  [3]\tͳ�����۶�\n\n");
			printf("\t\t\t\t\t  [4]\tά����������\n\n");
			printf("\t\t\t\t\t  [5]\tͳ��Ʊ��\n\n");
			printf("\t\t\t\t\t  [6]\t��ѯ�ݳ�Ʊ\n\n");
			printf("\t\t\t\t\t  [7]\t�����ݳ�\n\n");
			printf("\t\t\t\t\t  [8]\t�˳�ϵͳ\n\n");
			printf("\n\t\t\t\t\t:");
			rewind(stdin);
			choice = getche();
			switch (choice) {
			case '5':
				SalesAnalysis_UI_BoxOffice();
				break; 
			case '4':
				Account_UI_MgtEntry();
				break;
			case '7':
				Schedule_UI_MgtEntry(); 
				break;
			case '1':
				Play_UI_MgtEntry(0);
				break;
			case '6':
				printf("\n\t\t\t\t\t�ݳ��ƻ�ID:");
				scanf("%d", &sal_id);
				getchar();
				if (!Schedule_Srv_FetchByID(sal_id, &buf2))
				{
					printf("\t\t\t\t\t�ݳ��ƻ�������,���������");
					getch();
				}
				else
				{
					Sale_UI_ShowTicket2(sal_id);
				}
				break;
				break;
			case '2':
				Schedule_UI_ListAll();
				break;
			case '3':
				SalesAanalysis_UI_MgtEntry();
				break;
				
			}
		} while ('8' != choice);
		break;
	case 9:
		do {
            system("cls");
			printf("\n\n\n\n\n\n\n\t\t\t\t\t����Ա����,��ѡ��\n\n"); 
			printf("\t\t\t\t\t  [1]\t�����ݳ���\n\n");
			printf("\t\t\t\t\t  [2]\t����ϵͳ�û�\n\n");
			printf("\t\t\t\t\t  [3]\tά����������\n\n");
			printf("\t\t\t\t\t  [4]\t�˳�ϵͳ\n\n");
			printf("\n\t\t\t\t\t:");
			choice = getche();
			switch (choice) {
			case '1':
				Studio_UI_MgtEntry(usr.type);
				break;
			case '2':
				Account_UI_MgtEntry();
				break;
			case '3':
				Account_UI_MgtEntry();
				break;
			}
		} while ('4' != choice);
		break;
	case 0:
	default:
		do {
            system("cls");
			printf("\n\n\n\n\n\n\n\t\t\t\t\t����,��ѡ��\n\n"); 
			printf("\t\t\t\t\t  [1]\t��Ϣ��ѯ\n\n\n");
			printf("\t\t\t\t\t  [2]\t�˳�ϵͳ\n\n");
			printf("\n\t\t\t\t\t:");
			choice = getche();
			switch (choice) {
			case '1':
				Queries_Menu();
				break;
			}
		} while ('2' != choice);
		break;
	}
	printf("\n\t\t\t");
	getchar();
}

