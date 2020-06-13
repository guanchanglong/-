#define _CRT_SECURE_NO_DEPRECATE 0
#include "SalesAnalysis_UI.h"

#include "List.h"
#include "Account.h"
#include "Ticket.h"
#include "Play.h"
#include "Schedule.h"
#include "Sale.h"
#include "SalesAnalysis.h"
#include <stdio.h>
#include <stdlib.h>
static const int SALESANALYSIS_PAGE_SIZE = 5;
//统计票房界面
void SalesAnalysis_UI_MgtEntry()
{
	int i;
	char choice;
	salesanalysis_list_t head;
	salesanalysis_list_t pos;
	Pagination_t paging;
	List_Init(head, salesanalysis_node_t);
	paging.offset = 0;
	paging.pageSize = SALESANALYSIS_PAGE_SIZE;
	if (paging.totalRecords = SalesAnalysis_Srv_StaticSale(head))
	{
		Paging_Locate_FirstPage(head, paging);
		SalesAnalysis_Srv_SortBySale(head);
		printf("sfsjhd");
		do{
			printf(
				"\n==================================================================\n");
			printf(
				"********************** Projection Room List **********************\n");
			printf("%5s %12s %10s  %5s %8s%9s  %5s %10s %10s\n", "ID", "Name", "area", "duration", "总票数",
				"sales", "price", "start_date", "end_date");
			printf(
				"------------------------------------------------------------------\n");
			//显示数据 
			Paging_ViewPage_ForEach(head, paging, salesanalysis_node_t, pos, i){
				printf("%5d %12s %10s %5d %8d %9d   %5d   %4d-%2d-%2d  %02d:%02d:%02d\n", pos->data.play_id,
					pos->data.name, pos->data.area, pos->data.duration, pos->data.totaltickets, pos->data.sales,
					pos->data.price, pos->data.start_date.year, pos->data.start_date.month, pos->data.start_date.day, pos->data.end_date.year, pos->data.end_date.month, pos->data.end_date.day);
			}

			printf(
				"------- Total Records:%2d ----------------------- Page %2d/%2d ----\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
			printf(
				"******************************************************************\n");
			printf(
				"[P]revPage        |         [N]extPage         |           [R]eturn");
			printf(
				"\n==================================================================\n");
			printf("Your Choice:");
			setbuf(stdin, NULL);
			scanf("%c", &choice);
			setbuf(stdin, NULL);
			switch (choice)
			{
			case 'p':
			case 'P':
				if (!Pageing_IsFirstPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, -1, salesanalysis_node_t);
				}
				break;
			case 'n':
			case 'N':
				if (!Pageing_IsLastPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, 1, salesanalysis_node_t);
				}
				break;
			}
		} while (choice != 'r' && choice != 'R');
	}
	setbuf(stdin, NULL);
	List_Destroy(head, salesanalysis_node_t);
}

