#define _CRT_SECURE_NO_DEPRECATE 0


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Play_UI.h"
#include "Schedule_UI.h"
#include "Sale_UI.h"
#include "Ticket_UI.h"
#include "Ticket.h"
#include "Ticket_Persist.h"
#include "Seat.h"
#include "Studio.h"
#include "Sale.h"
#include "Play.h"
#include "Account.h"


static const int SALE_PAGE_SIZE = 5;
static const int SALESANALYSIS_PAGE_SIZE = 5;
void Sale_UI_MgtEntry()
{
	char choice;
	char name[20];
	int i;
	int play_id;
	play_node_t *pos;

	play_list_t list;
	play_list_t list_fetch;
	List_Init(list, play_node_t);
	List_Init(list_fetch, play_node_t);

	Pagination_t paging;
	paging.offset = 0;
	paging.pageSize = SALE_PAGE_SIZE;
	Play_Srv_FetchAll(list_fetch);
	if(paging.totalRecords = Play_Srv_FetchAll(list))     //��ȡȫ�� ��Ŀ ��Ϣ
	{
		Paging_Locate_FirstPage(list, paging);
		do
		{
			printf(
				"\n======================================================================================\n");
			printf(
				"***************************** ��˹����ԺƱ��ϵͳ ***********************************\n");

			printf("%5s %15s %5s %10s %6s %6s %10s %10s     %3s\n", "ID", "��Ӱ����", "����", "����", "�ȼ�", "ʱ��(minute)", "��ӳ����", "�¼�����", "�۸�");
			printf("--------------------------------------------------------------------------------------\n");
			Paging_ViewPage_ForEach(list, paging, play_node_t, pos, i)
			{
				printf("%5d %15s %5d %10s %6d  %6d       %4d-%02d-%02d  %4d-%02d-%02d     %4d\n",
					pos->data.id, pos->data.name, pos->data.type, pos->data.area, pos->data.rating,
					pos->data.duration, pos->data.start_date.year, pos->data.start_date.month,
					pos->data.start_date.day, pos->data.end_date.year, pos->data.end_date.month,
					pos->data.end_date.day, pos->data.price);
			}


			printf("----------------Total Recoeds: %2d---------------------------Page %2d   %2d   -----------\n",
				paging.totalRecords, Pageing_CurPage(paging), Pageing_TotalPages(paging));

			printf("**************************************************************************************\n");


			printf("[C]��ʾ�ݳ��ƻ�         [P]��һҳ       [N]��һҳ         [R]����          \n");
			printf("======================================================================================\n");
			printf("please input your choice : ");
			setbuf(stdin, NULL);
			scanf("%c", &choice);
			//getchar( );
			switch (choice)
			{
			case'c':
			case'C':
				printf("please input ��Ŀid  :");
				scanf("%d", &play_id);
				getchar();
				Sale_UI_ShowScheduler(play_id);
				break;
				/*case's':
				case'S':
				printf( "please input the Play_ name :");
				setbuf(stdin,NULL);
				scanf("%s",name);*/

			case'n':
			case'N':
				if (!Pageing_IsLastPage(paging))
				{
					Paging_Locate_OffsetPage(list, paging, 1, play_node_t);
				}
				break;
			case'P':
			case'p':
				if (!Pageing_IsFirstPage(paging))
				{
					Paging_Locate_OffsetPage(list, paging, -1, play_node_t);
				}
				break;
			}

		} while (choice != 'r' && choice != 'R');
	}
}
int schedule_id;

void Sale_UI_ShowScheduler(int play_id)     //ͨ�� ��ĿID ��ʾ �ݳ��ƻ�
{
	int i;
	char choice;
	//int schedule_id;

	schedule_list_t list;
	schedule_node_t *pos;
	Pagination_t paging;

	List_Init(list, schedule_node_t);

	paging.offset = 0;
	paging.pageSize = SALESANALYSIS_PAGE_SIZE;

	if (paging.totalRecords = Schedule_Srv_FetchByPlay(list, play_id))    //��ȡ   �ݳ��ƻ�����
	{
		Paging_Locate_FirstPage(list, paging);
		do
		{
			printf("===================================================================================================\n");
			printf("*****************************************��ԺƱ�����ϵͳ*******************************************\n");
			printf("---------------------------------------------------------------------------------------------------\n");
			printf(" �ݳ��ƻ� ID     ��Ŀ ID      �ݳ��� ID           ��ӳ����            ��ӳʱ��          ��λ��\n");
			printf("---------------------------------------------------------------------------------------------------\n");
			Paging_ViewPage_ForEach(list, paging, schedule_node_t, pos, i)
			{
				printf("         %3d         %3d          %3d             %4d-%02d-%02d           %02d:%02d:%02d               %d  \n",
					pos->data.id, pos->data.play_id, pos->data.studio_id, pos->data.date.year, pos->data.date.month, pos->data.date.day,
					pos->data.time.hour, pos->data.time.minute, pos->data.time.second, pos->data.seat_count);

			}

			printf("-----totalRecords : %2d  -----------------------------Page %2d /%2d ------------------------------------\n", paging.totalRecords, Pageing_CurPage(paging), Pageing_TotalPages(paging));

			printf("[T]��ʾ���е�Ʊ    [N]ext     [P]rev    [R]eturn \n");
			printf("Your choice : ");
			setbuf(stdin, NULL);
			scanf("%c", &choice);
			getchar();
			switch (choice)
			{
			case'T':
			case't':
				printf("Please input �ݳ��ƻ�Schedule ID:");
				setbuf(stdin, NULL);
				scanf("%d", &schedule_id);
				getchar();
				Sale_UI_ShowTicket(schedule_id);
				break;
			case'N':
			case'n':
				if (!Pageing_IsLastPage(paging))
				{
					Paging_Locate_OffsetPage(list, paging, 1, schedule_node_t);
				}
				break;
			case'p':
			case'P':
				if (!Pageing_IsFirstPage(paging))
				{
					Paging_Locate_OffsetPage(list, paging, -1, schedule_node_t);
				}
				break;
			}
		} while (choice == 'r' && choice == 'R');
	}
}

int Sale_UI_ShowTicket(int schedule_id)
{
	seat_list_t list;
	List_Init(list, seat_node_t);
	int studio_ID;

	printf("please input the �ݳ���studio ID :");
	scanf("%d", &studio_ID);
	getchar();
	int seat = Seat_Srv_FetchValidByRoomID(list, studio_ID);
	int i;
	char choice;
	ticket_node_t *pos;
	Pagination_t paging;

	//	List_Init(list,seat_node_t);
	paging.offset = 0;
	paging.pageSize = TICKET_PAGE_SIZE;
	ticket_list_t list_ti;
	List_Init(list_ti, ticket_node_t);
	if (paging.totalRecords = Ticket_Srv_FetchBySchID(schedule_id, list_ti)){
		Paging_Locate_FirstPage(list_ti, paging);
		do
		{
			//	paging.totalRecords = Ticket_Srv_FetchBySchID(schedule_id,list_ti);
			printf("====================================================================================\n");
			printf("**************************************Ticket****************************************\n");
			printf("------------------------------------------------------------------------------------\n");
			printf("Ticket ID          Scheuid ID         Seat ID       Price             Ticket״̬\n");
			Paging_ViewPage_ForEach(list_ti, paging, ticket_node_t, pos, i)
			{
				printf("  %5d               %5d            %5d      %5d                     %5d\n",
					pos->data.id, pos->data.schedule_id, pos->data.seat_id, pos->data.price, pos->data.status);
			}
			printf("------Total Records  : %2d ------------------------Page %2d / %2d----------------------\n",
				paging.totalRecords, Pageing_CurPage(paging), Pageing_TotalPages(paging));
			printf("[N]��һҳ    [P]��һҳ    [S]��Ʊ      [R]eturn    \n");
			printf("Your choice:");
			scanf("%c", &choice);
			getchar();
			switch (choice)
			{
			case'n':
			case'N':
				if (!Pageing_IsLastPage(paging))
				{
					Paging_Locate_OffsetPage(list_ti, paging, 1, ticket_node_t);
				}

				break;
			case'p':
			case'P':
				if (!Pageing_IsFirstPage(paging))
				{
					Paging_Locate_OffsetPage(list_ti, paging, -1, ticket_node_t);
				}
				break;
			case'S':
			case's':

				if (Sale_UI_SellTicket(list_ti, list))
					paging.totalRecords = Ticket_Srv_FetchBySchID(schedule_id, list_ti);
				break;
			}

		} while (choice != 'r'  && choice != 'R');
	}
	//	printf("%d\n",paging.totalRecords);
	return 0;
}


int Sale_UI_SellTicket(ticket_list_t list_t, seat_list_t list_s)
{
	seat_node_t * seat = NULL;
	setbuf(stdin, NULL);
	sale_t data_t;
	int row, col;
	while (1)
	{
		printf("��������Ҫѡ�������:");
		scanf("%d", &row);
		printf("��������Ҫѡ�������:");
		scanf("%d", &col);
		getchar();
		seat = Seat_Srv_FindByRowCol(list_s, row, col);
		if (NULL == seat)
		{
			printf("�����λ������!\n");
			continue;
		}
		if (seat->data.status == SEAT_BROKEN)
		{
			printf("�����λʱ����!\n");
		}
		else if (seat->data.status == SEAT_NONE)
		{
			printf("�����λ�ǿյ�!\n");
			break;
		}
		else
		{
			break;
		}
	}
	ticket_t buf;
	account_t buf_a;
	//printf("��λid : %d",seat->data.id);
	Ticket_Perst_SelByseatID(seat->data.id, &buf, schedule_id);
	//printf("%d %d %d\n",buf.id,buf.schedule_id,buf.seat_id);
	if (buf.status == 1)
	{
		printf("����Ʊ�Ѿ��۳�!\n");
		printf("��[Enter]����!\n");
		getchar();
		return 0;
	}
	else
	{
		data_t.ticket_id = buf.id;
		buf.status = TICKET_SOLD;
		Ticket_Srv_Modify(&buf);
		ticket_list_t ticket_tmp;
		List_ForEach(list_t, ticket_tmp)
		{
			if (buf.id == ticket_tmp->data.id)
			{
				ticket_tmp->data = buf;
				break;
			}
		}
		/* 			while(1)
		{
		printf( "please input the saler ID:");
		scanf( "%d",&data_t.user_id);
		data_t.user_id=gl_CurUser.id;
		if(!Account_Srv_FetchByID(data_t.user_id,&buf_a))
		{
		continue;
		}
		else
		{
		break;
		}
		} */
		printf("�������������ۻ�Աxuqigang��ID:24\n");
		printf("�ۻ�Ա��ID:");
		scanf("%d", &data_t.user_id);
		data_t.type = SALE_SELL;
		data_t.value = buf.price;
		data_t.id = EntKey_Perst_GetNewKeys("Sale", 1);
		printf("please input date(year-month-day):");
		scanf("%d-%d-%d", &data_t.date.year, &data_t.date.month, &data_t.date.day);
		getchar();
		printf("please input time(shi:fen:miao):");
		scanf("%d:%d:%d", &data_t.time.hour, &data_t.time.minute, &data_t.time.second);
		getchar();
		Sale_Srv_Add(&data_t);
		Ticket_UI_Print(buf);
	}
}



void Sale_UI_ReturnTicket()
{
	int id;
	ticket_t tic;
	printf("\n===============================================================\n");
	printf("**************************  ��Ʊ  ********************************\n");
	printf("------------------------------------------------------------------\n");
	printf("������Ҫ�˵�Ʊ��ID:");
	scanf("%d", &id);
	fflush(stdin);
	if (!Ticket_Srv_FetchByID(id, &tic)){
		printf("Ҫ�˵�Ʊ������!\n");
		getchar();
		return;
	}
	if (tic.status != 1){
		printf("��Ʊ��δ�۳�!\n");
		printf("��[Enter]����!\n");
		getchar();
		return;
	}
	tic.status = TICKET_AVL;
	if (Ticket_Srv_Modify(&tic)){
		printf("��Ʊ�ɹ�!Ӧ�˿� %d Ԫ!\n", tic.price);
	}
	else{
		printf("��Ǹ!��Ʊʧ��!\n");
	}
	printf("��[Enter]����!");
	getchar();
	return;

}
void Play_Srv_Print(play_list_t list)
{
	play_list_t temp;
	temp = list;

	list = list->next;
	if (list != temp)
	{
		printf("*************************************** %s  Play List******************************************\n", list->data.name);
		printf("��Ŀ ID   ����   ����      �ȼ�         ʱ��     Start_date           End_date          �۸�     \n");
	}
	else
	{
		printf("****************Nothing************************\n");
		return;
	}
	while (list != temp)
	{
		printf("   %d      %d     %s        %d            %d     %d-%d-%d               %d.%d.%d          %d\n",
			list->data.id, list->data.type, list->data.area, list->data.rating, list->data.duration,
			list->data.start_date.year, list->data.start_date.month, list->data.start_date.day,
			list->data.start_date.year, list->data.end_date.month, list->data.end_date.day, list->data.price);
		list = list->next;
	}
	setbuf(stdin, NULL);
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("��[Enter]����!\n");
	getchar();
	return;

}

void Ticket_UI_Print(const ticket_t data)
{
	printf("\n\n");
	printf("***************��˹����Ժ�ݳ�Ʊ****************\n");
	printf("Ticket ID      Schedule ID    Seat ID    Price\n");
	printf("%d                  %d           %d      %d    \n", data.id, data.schedule_id, data.seat_id, data.price);
}


