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
	if(paging.totalRecords = Play_Srv_FetchAll(list))     //获取全部 剧目 信息
	{
		Paging_Locate_FirstPage(list, paging);
		do
		{
			printf(
				"\n======================================================================================\n");
			printf(
				"***************************** 奥斯卡剧院票务系统 ***********************************\n");

			printf("%5s %15s %5s %10s %6s %6s %10s %10s     %3s\n", "ID", "电影名字", "类型", "地区", "等级", "时长(minute)", "上映日期", "下架日期", "价格");
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


			printf("[C]显示演出计划         [P]上一页       [N]下一页         [R]返回          \n");
			printf("======================================================================================\n");
			printf("please input your choice : ");
			setbuf(stdin, NULL);
			scanf("%c", &choice);
			//getchar( );
			switch (choice)
			{
			case'c':
			case'C':
				printf("please input 剧目id  :");
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

void Sale_UI_ShowScheduler(int play_id)     //通过 剧目ID 显示 演出计划
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

	if (paging.totalRecords = Schedule_Srv_FetchByPlay(list, play_id))    //获取   演出计划链表
	{
		Paging_Locate_FirstPage(list, paging);
		do
		{
			printf("===================================================================================================\n");
			printf("*****************************************剧院票务管理系统*******************************************\n");
			printf("---------------------------------------------------------------------------------------------------\n");
			printf(" 演出计划 ID     剧目 ID      演出厅 ID           放映日期            放映时间          座位数\n");
			printf("---------------------------------------------------------------------------------------------------\n");
			Paging_ViewPage_ForEach(list, paging, schedule_node_t, pos, i)
			{
				printf("         %3d         %3d          %3d             %4d-%02d-%02d           %02d:%02d:%02d               %d  \n",
					pos->data.id, pos->data.play_id, pos->data.studio_id, pos->data.date.year, pos->data.date.month, pos->data.date.day,
					pos->data.time.hour, pos->data.time.minute, pos->data.time.second, pos->data.seat_count);

			}

			printf("-----totalRecords : %2d  -----------------------------Page %2d /%2d ------------------------------------\n", paging.totalRecords, Pageing_CurPage(paging), Pageing_TotalPages(paging));

			printf("[T]显示所有的票    [N]ext     [P]rev    [R]eturn \n");
			printf("Your choice : ");
			setbuf(stdin, NULL);
			scanf("%c", &choice);
			getchar();
			switch (choice)
			{
			case'T':
			case't':
				printf("Please input 演出计划Schedule ID:");
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

	printf("please input the 演出厅studio ID :");
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
			printf("Ticket ID          Scheuid ID         Seat ID       Price             Ticket状态\n");
			Paging_ViewPage_ForEach(list_ti, paging, ticket_node_t, pos, i)
			{
				printf("  %5d               %5d            %5d      %5d                     %5d\n",
					pos->data.id, pos->data.schedule_id, pos->data.seat_id, pos->data.price, pos->data.status);
			}
			printf("------Total Records  : %2d ------------------------Page %2d / %2d----------------------\n",
				paging.totalRecords, Pageing_CurPage(paging), Pageing_TotalPages(paging));
			printf("[N]下一页    [P]上一页    [S]售票      [R]eturn    \n");
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
		printf("输入你想要选择的行数:");
		scanf("%d", &row);
		printf("输入你想要选择的列数:");
		scanf("%d", &col);
		getchar();
		seat = Seat_Srv_FindByRowCol(list_s, row, col);
		if (NULL == seat)
		{
			printf("这个座位不存在!\n");
			continue;
		}
		if (seat->data.status == SEAT_BROKEN)
		{
			printf("这个座位时坏的!\n");
		}
		else if (seat->data.status == SEAT_NONE)
		{
			printf("这个座位是空的!\n");
			break;
		}
		else
		{
			break;
		}
	}
	ticket_t buf;
	account_t buf_a;
	//printf("座位id : %d",seat->data.id);
	Ticket_Perst_SelByseatID(seat->data.id, &buf, schedule_id);
	//printf("%d %d %d\n",buf.id,buf.schedule_id,buf.seat_id);
	if (buf.status == 1)
	{
		printf("这张票已经售出!\n");
		printf("按[Enter]返回!\n");
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
		printf("请在下面输入售货员xuqigang的ID:24\n");
		printf("售货员的ID:");
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
	printf("**************************  退票  ********************************\n");
	printf("------------------------------------------------------------------\n");
	printf("请输入要退的票的ID:");
	scanf("%d", &id);
	fflush(stdin);
	if (!Ticket_Srv_FetchByID(id, &tic)){
		printf("要退的票不存在!\n");
		getchar();
		return;
	}
	if (tic.status != 1){
		printf("此票尚未售出!\n");
		printf("按[Enter]返回!\n");
		getchar();
		return;
	}
	tic.status = TICKET_AVL;
	if (Ticket_Srv_Modify(&tic)){
		printf("退票成功!应退款 %d 元!\n", tic.price);
	}
	else{
		printf("抱歉!退票失败!\n");
	}
	printf("按[Enter]返回!");
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
		printf("剧目 ID   类型   地区      等级         时长     Start_date           End_date          价格     \n");
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
	printf("按[Enter]返回!\n");
	getchar();
	return;

}

void Ticket_UI_Print(const ticket_t data)
{
	printf("\n\n");
	printf("***************奥斯卡剧院演出票****************\n");
	printf("Ticket ID      Schedule ID    Seat ID    Price\n");
	printf("%d                  %d           %d      %d    \n", data.id, data.schedule_id, data.seat_id, data.price);
}


